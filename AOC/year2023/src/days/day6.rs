use std::{u32, u64};

type ParseResult = (Vec<u64>, Vec<u64>);

fn get_count(time_limit: u64, dist_limit: u64) -> u32 {
    let mut start: u64 = 1;
    let mut end: u64 = 1;
    for t in 1..time_limit {
        let d = t * (time_limit - t);
        if d > dist_limit {
            start = t;
            break;
        }
    }
    for t in (1..time_limit).rev() {
        let d = t * (time_limit - t);
        if d > dist_limit {
            end = t;
            break;
        }
    }

    return (end - start + 1) as u32;
}

fn part_one((times, distances): &ParseResult) -> u32 {
    let possibles = times
        .iter()
        .enumerate()
        .map(|(idx, &time)| get_count(time, distances[idx]))
        .collect::<Vec<_>>();

    let mut part_one_answer = 1;
    for p in possibles {
        part_one_answer *= p;
    }
    part_one_answer
}

fn part_two((times, distances): &ParseResult) -> u32 {
    get_count(times[0], distances[0])
}

fn parse(input: &str, part: u8) -> (Vec<u64>, Vec<u64>) {
    let lines = input.lines().collect::<Vec<_>>();

    match part {
        1 => {
            let times = lines[0]
                .split(": ")
                .nth(1)
                .unwrap()
                .trim()
                .split_whitespace()
                .map(str::parse::<u64>)
                .map_while(Result::ok)
                .collect::<Vec<u64>>();

            let distance = lines[1]
                .split(": ")
                .nth(1)
                .unwrap()
                .trim()
                .split_whitespace()
                .map(str::parse::<u64>)
                .map_while(Result::ok)
                .collect::<Vec<u64>>();

            return (times, distance);
        }
        2 => {
            let time = lines[0]
                .split(": ")
                .nth(1)
                .unwrap()
                .trim()
                .chars()
                .filter(|&c| !c.is_whitespace())
                .collect::<String>()
                .parse::<u64>()
                .unwrap();

            let distance = lines[1]
                .split(": ")
                .nth(1)
                .unwrap()
                .trim()
                .chars()
                .filter(|&c| !c.is_whitespace())
                .collect::<String>()
                .parse::<u64>()
                .unwrap();

            return (vec![time], vec![distance]);
        }
        _ => panic!(),
    }
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

    const INPUT: &str = "Time:      7  15   30
Distance:  9  40  200";

    #[test]
    fn part_one_test() {
        let expected = 288;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 71503;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
