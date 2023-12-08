use regex::Regex;
use std::collections::HashMap;

type ParseResult<'a> = (Vec<char>, HashMap<&'a str, (&'a str, &'a str)>);

fn part_one(input: &ParseResult) -> u32 {
    let mut current_key = "AAA";
    let mut current_direction_idx = 0;
    let mut count: u32 = 0;
    loop {
        let &next = input.1.get(current_key).unwrap();
        let dir = input.0[current_direction_idx];
        current_key = if dir == 'L' { next.0 } else { next.1 };
        count += 1;
        current_direction_idx = (current_direction_idx + 1) % input.0.len();

        if current_key == "ZZZ" {
            break;
        }
    }
    count
}

fn gcd_of_two_numbers(a: u64, b: u64) -> u64 {
    if b == 0 {
        return a;
    }
    gcd_of_two_numbers(b, a % b)
}

fn lcm(nums: &[u64]) -> u64 {
    if nums.len() == 1 {
        return nums[0];
    }
    let a = nums[0];
    let b = lcm(&nums[1..]);
    a * b / gcd_of_two_numbers(a, b)
}

fn part_two(input: &ParseResult) -> u64 {
    let current_keys = input
        .1
        .keys()
        .filter(|k| k.ends_with('A'))
        .map(|&k| k)
        .collect::<Vec<_>>();

    let counts = current_keys
        .iter()
        .map(|&key| {
            let mut current_key = key;
            let mut current_direction_idx = 0;
            let mut count: u64 = 0;
            loop {
                let dir = input.0[current_direction_idx];
                let &next = input.1.get(current_key).unwrap();
                current_key = if dir == 'L' { next.0 } else { next.1 };
                count += 1;
                current_direction_idx = (current_direction_idx + 1) % input.0.len();

                if current_key.ends_with('Z') {
                    break;
                }
            }
            return count;
        })
        .collect::<Vec<_>>();

    lcm(&counts)
}

fn parse(input: &str, _part: u8) -> ParseResult {
    let lines = input.lines().collect::<Vec<_>>();

    let re = Regex::new(r"\w+").unwrap();

    let instructions = lines[0].chars().collect::<Vec<_>>();

    let maps_arr = input
        .lines()
        .skip(2)
        .map(|line| {
            let matches = re.find_iter(line).collect::<Vec<_>>();
            (
                matches[0].as_str(),
                (matches[1].as_str(), matches[2].as_str()),
            )
        })
        .collect::<Vec<_>>();

    let mut m = HashMap::new();
    for (k, v) in maps_arr {
        m.insert(k, v);
    }

    return (instructions, m);
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

    const INPUT_ONE: &str = "RL

AAA = (BBB, CCC)
BBB = (DDD, EEE)
CCC = (ZZZ, GGG)
DDD = (DDD, DDD)
EEE = (EEE, EEE)
GGG = (GGG, GGG)
ZZZ = (ZZZ, ZZZ)";

    const INPUT_TWO: &str = "LLR

AAA = (BBB, BBB)
BBB = (AAA, ZZZ)
ZZZ = (ZZZ, ZZZ)";

    const INPUT_THREE: &str = "LR

11A = (11B, XXX)
11B = (XXX, 11Z)
11Z = (11B, XXX)
22A = (22B, XXX)
22B = (22C, 22C)
22C = (22Z, 22Z)
22Z = (22B, 22B)
XXX = (XXX, XXX)";

    #[test]
    fn part_one_test_a() {
        let expected = 2;
        let output = part_one(&parse(INPUT_ONE, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_one_test_b() {
        let expected = 6;
        let output = part_one(&parse(INPUT_TWO, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 6;
        let output = part_two(&parse(INPUT_THREE, 2));
        assert_eq!(expected, output);
    }
}
