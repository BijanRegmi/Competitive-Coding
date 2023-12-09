use regex::Regex;

type ParseResult = Vec<Vec<i32>>;

fn part_one(input: &ParseResult) -> i32 {
    let mut sum = 0;
    for nums in input {
        let mut initial = nums.clone();
        let mut prediction = *initial.last().unwrap();
        loop {
            initial = initial.windows(2).map(|num| num[1] - num[0]).collect();
            prediction += initial.last().unwrap();
            if initial.iter().all(|&n| n == 0) {
                break;
            }
        }
        sum += prediction;
    }
    sum
}

fn part_two(input: &ParseResult) -> i32 {
    let mut sum = 0;
    for nums in input {
        let mut initial = nums.clone();
        let mut prediction = *initial.last().unwrap();
        loop {
            initial = initial.windows(2).map(|num| num[1] - num[0]).collect();
            prediction += initial.last().unwrap();
            if initial.iter().all(|&n| n == 0) {
                break;
            }
        }
        sum += prediction;
    }

    sum
}

fn parse(input: &str, _part: u8) -> ParseResult {
    let re = Regex::new(r"-?\d+").unwrap();

    input
        .lines()
        .map(|line| {
            re.find_iter(line)
                .filter_map(|m| m.as_str().parse::<i32>().ok())
                .collect::<Vec<_>>()
        })
        .collect::<Vec<_>>()
}

pub fn run(input: &str) {
    let part_one_answer = part_one(&parse(input, 1));
    let part_two_answer = part_two(&parse(input, 2));

    println!("Part One: {part_one_answer}");
    println!("Part Two: {part_two_answer}");
}

#[cfg(test)]
mod test {
    use super::{parse, part_one, part_two};

    const INPUT: &str = "0 3 6 9 12 15
1 3 6 10 15 21
10 13 16 21 30 45";

    #[test]
    fn part_one_test() {
        let expected = 114;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 2;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
