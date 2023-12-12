use std::collections::HashMap;

type Spring = (String, Vec<u32>);
type ParseResult = Vec<Spring>;

fn permute(row: &Spring, i: usize, j: usize, memo: &mut HashMap<(usize, usize), u64>) -> u64 {
    if let Some(v) = memo.get(&(i, j)) {
        return *v;
    }

    if j >= row.1.len() {
        if row.0.chars().skip(i).all(|c| c != '#') {
            return 1;
        } else {
            return 0;
        }
    }

    let current_spring_length = row.1[j];
    let rem_spring_groups = (row.1.len() - j) as u32 - 1;
    let rem_spring_length = row.1.iter().skip(j + 1).sum::<u32>();
    let max_dot_length =
        (row.0.len() - i) as u32 - (rem_spring_length + rem_spring_groups + current_spring_length);

    let mut answer = 0;
    for dot_length in 0..max_dot_length + 1 {
        let dots = ".".repeat(dot_length as usize);
        let spring_str = "#".repeat(current_spring_length as usize);
        let mut possible_pattern = String::new();
        possible_pattern.push_str(&dots);
        possible_pattern.push_str(&spring_str);
        if rem_spring_groups != 0 {
            possible_pattern.push('.');
        }

        let mut valid = true;
        for (ch_idx, ch) in possible_pattern.chars().enumerate() {
            let mch = row.0.chars().nth(ch_idx + i).unwrap();
            if mch != ch && mch != '?' {
                valid = false;
                break;
            }
        }
        if valid {
            answer += permute(row, i + possible_pattern.len(), j + 1, memo);
        }
    }

    memo.insert((i, j), answer);
    answer
}

fn part_one(input: &mut ParseResult) -> u64 {
    let mut memo: HashMap<(usize, usize), u64> = HashMap::new();
    input
        .iter_mut()
        .map(|line| {
            let ans = permute(line, 0, 0, &mut memo);
            memo.clear();
            ans
        })
        .sum()
}

fn part_two(input: &mut ParseResult) -> u64 {
    let mut memo: HashMap<(usize, usize), u64> = HashMap::new();
    input
        .iter_mut()
        .map(|line| {
            let ans = permute(line, 0, 0, &mut memo);
            memo.clear();
            ans
        })
        .sum()
}

fn parse(input: &str, part: u8) -> ParseResult {
    if part == 1 {
        input
            .lines()
            .map(|line| {
                let parts = line.split_whitespace().collect::<Vec<_>>();
                let nums = parts[1]
                    .split(",")
                    .map_while(|n| n.parse::<u32>().ok())
                    .collect::<Vec<_>>();

                (parts[0].to_string(), nums)
            })
            .collect::<Vec<_>>()
    } else {
        input
            .lines()
            .map(|line| {
                let parts = line.split_whitespace().collect::<Vec<_>>();
                let nums = parts[1]
                    .split(",")
                    .map_while(|n| n.parse::<u32>().ok())
                    .collect::<Vec<_>>();

                let mut extended_parts: String = String::new();

                for i in 0..5 {
                    extended_parts.push_str(parts[0]);
                    if i != 4 {
                        extended_parts.push('?')
                    }
                }

                (
                    extended_parts.to_string(),
                    nums.iter()
                        .cycle()
                        .take(nums.len() * 5)
                        .map(|n| *n)
                        .collect::<Vec<u32>>(),
                )
            })
            .collect::<Vec<_>>()
    }
}

pub fn run(input: &str) {
    let part_one_answer = part_one(&mut parse(input, 1));
    println!("Part One: {part_one_answer}");

    let part_two_answer = part_two(&mut parse(input, 2));
    println!("Part Two: {part_two_answer}");
}

#[cfg(test)]
mod test {
    use super::{parse, part_one, part_two};

    const INPUT: &str = "???.### 1,1,3
.??..??...?##. 1,1,3
?#?#?#?#?#?#?#? 1,3,1,6
????.#...#... 4,1,1
????.######..#####. 1,6,5
?###???????? 3,2,1";

    #[test]
    fn part_one_test() {
        let expected = 21;
        let output = part_one(&mut parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 525152;
        let output = part_two(&mut parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
