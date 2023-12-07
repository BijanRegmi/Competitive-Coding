#![allow(dead_code, unused_variables)]

type ParseResult<'a> = &'a str;

fn part_one(input: &ParseResult) -> u32 {
    0
}

fn part_two(input: &ParseResult) -> u32 {
    0
}

fn parse(input: &str, part: u8) -> ParseResult {
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
