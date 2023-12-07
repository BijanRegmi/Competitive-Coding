type ParseResult<'a> = &'a str;

const NUMS: [&str; 9] = [
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
];

fn determine_first_p1(line: &str) -> u32 {
    line.chars()
        .find(|c| c.is_digit(10))
        .map(|c| c.to_digit(10).unwrap_or(0))
        .unwrap_or(0)
}

fn determine_last_p1(line: &str) -> u32 {
    line.chars()
        .rev()
        .find(|c| c.is_digit(10))
        .map(|c| c.to_digit(10).unwrap_or(0))
        .unwrap_or(0)
}

fn determine_first_p2(line: &str) -> u32 {
    let mut i = 0;
    while i < line.len() {
        let x = line.chars().nth(i).unwrap().to_digit(10);
        if let Some(digit) = x {
            return digit;
        }

        for n in 3..6 {
            let digit = line.get(i..i + n);
            if let Some(num) = digit {
                if let Some(idx) = NUMS.iter().position(|n| *n == num) {
                    return (idx + 1) as u32;
                }
            }
        }
        i += 1;
    }
    return 0;
}

fn determine_last_p2(line: &str) -> u32 {
    let mut j = line.len() - 1;
    loop {
        let x = line.chars().nth(j).unwrap().to_digit(10);
        if let Some(digit) = x {
            return digit;
        }

        for n in 3..6 {
            if j < n {
                continue;
            }
            let digit = line.get(j - n + 1..j + 1);
            if let Some(num) = digit {
                if let Some(idx) = NUMS.iter().position(|n| *n == num) {
                    return (idx + 1) as u32;
                }
            }
        }
        j -= 1;
    }
}

fn part_one(input: &ParseResult) -> u32 {
    input
        .lines()
        .map(|s| determine_first_p1(s) * 10 + determine_last_p1(s))
        .sum()
}

fn part_two(input: &ParseResult) -> u32 {
    input
        .lines()
        .map(|s| determine_first_p2(s) * 10 + determine_last_p2(s))
        .sum()
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input
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

    const INPUT: &str = "";

    #[test]
    fn part_one_test() {
        let expected = 0;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 0;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
