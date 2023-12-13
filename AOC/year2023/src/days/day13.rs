type ParseResult = Vec<Vec<String>>;

fn get_score(chunk: &Vec<String>, smudge: bool) -> u64 {
    let row_len = chunk.len();
    let col_len = chunk[0].len();

    for mirror_idx in 1..row_len {
        let mut diff = 0;
        for upper_row_idx in 0..mirror_idx {
            let lower_row_idx = 2 * mirror_idx - upper_row_idx - 1;
            if lower_row_idx >= row_len {
                continue;
            }
            for col_idx in 0..col_len {
                if chunk[upper_row_idx].chars().nth(col_idx)
                    != chunk[lower_row_idx].chars().nth(col_idx)
                {
                    diff += 1;
                }
            }
        }
        if smudge && diff == 1 || !smudge && diff == 0 {
            return 100 * mirror_idx as u64;
        }
    }

    for mirror_idx in 1..col_len {
        let mut diff = 0;
        for left_col_idx in 0..mirror_idx {
            let right_col_idx = 2 * mirror_idx - left_col_idx - 1;
            if right_col_idx >= col_len {
                continue;
            }
            for row_idx in 0..row_len {
                if chunk[row_idx].chars().nth(right_col_idx)
                    != chunk[row_idx].chars().nth(left_col_idx)
                {
                    diff += 1;
                }
            }
        }
        if smudge && diff == 1 || !smudge && diff == 0 {
            return mirror_idx as u64;
        }
    }

    0
}

fn part_one(input: &ParseResult) -> u64 {
    let mut ans = 0;
    for chunk in input {
        ans += get_score(chunk, false);
    }

    ans
}

fn part_two(input: &ParseResult) -> u64 {
    let mut ans: u64 = 0;
    for chunk in input {
        ans += get_score(chunk, true);
    }

    ans
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input
        .split("\n\n")
        .map(|chunk| chunk.lines().map(|line| line.chars().collect()).collect())
        .collect()
}

pub fn run(input: &str) {
    let part_one_answer = part_one(&parse(input, 1));
    println!("Part One: {part_one_answer}");

    let part_two_answer = part_two(&parse(input, 2));
    println!("Part Two: {part_two_answer}");
}

#[cfg(test)]
mod test {
    use super::{parse, part_one, part_two};

    const INPUT: &str = "#.##..##.
..#.##.#.
##......#
##......#
..#.##.#.
..##..##.
#.#.##.#.

#...##..#
#....#..#
..##..###
#####.##.
#####.##.
..##..###
#....#..#";

    #[test]
    fn part_one_test() {
        let expected = 405;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 400;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
