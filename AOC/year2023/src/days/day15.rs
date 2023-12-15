use std::collections::HashMap;

type ParseResult<'a> = &'a str;

struct Lens<'a> {
    label: &'a str,
    focal: u64,
}

fn hash(input: &str) -> u64 {
    let mut hash = 0;
    input.chars().for_each(|ch| {
        if ch != '\n' {
            hash += ch as u64;
            hash *= 17;
            hash %= 256;
        }
    });
    hash
}

fn part_one(input: &ParseResult) -> u64 {
    input.split(",").map(hash).sum::<u64>()
}

fn part_two(input: &ParseResult) -> u64 {
    let mut boxes: HashMap<u64, Vec<Lens>> = HashMap::new();

    input.split(",").for_each(|cmd| {
        if cmd.contains("=") {
            let parts = cmd.split("=").collect::<Vec<_>>();
            let box_hash = hash(parts[0]);
            let focal_length = parts[1].chars().nth(0).unwrap().to_digit(10).unwrap() as u64;
            if let Some(box_content) = boxes.get_mut(&box_hash) {
                if let Some(positon) = box_content.iter().position(|v| v.label == parts[0]) {
                    box_content[positon].focal = focal_length;
                } else {
                    box_content.push(Lens {
                        label: parts[0],
                        focal: focal_length,
                    })
                }
            } else {
                boxes.insert(
                    box_hash,
                    vec![Lens {
                        label: parts[0],
                        focal: focal_length,
                    }],
                );
            }
        } else {
            let parts = cmd.split("-").collect::<Vec<_>>();
            let box_hash = hash(parts[0]);
            if let Some(box_content) = boxes.get_mut(&box_hash) {
                if let Some(position) = box_content.iter().position(|v| v.label == parts[0]) {
                    box_content.remove(position);
                }
            }
        }
    });

    boxes
        .iter()
        .map(|(k, v)| {
            v.iter()
                .enumerate()
                .map(|(idx, lens)| (*k + 1) * (idx + 1) as u64 * lens.focal)
                .sum::<u64>()
        })
        .sum()
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input
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

    const INPUT: &str = "rn=1,cm-,qp=3,cm=2,qp-,pc=4,ot=9,ab=5,pc-,pc=6,ot=7";

    #[test]
    fn part_one_test() {
        let expected = 1320;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 145;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
