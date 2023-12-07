use std::cmp::min;

#[derive(Debug)]
struct Mapping {
    input: u64,
    output: u64,
    range: u64,
}

type ParseResult = (Vec<u64>, Vec<Vec<Mapping>>);

fn transform(ranges: &mut Vec<(u64, u64)>, maps: &Vec<Vec<Mapping>>) {
    for map in maps.iter() {
        let mut new_ranges: Vec<(u64, u64)> = vec![];
        ranges.iter().for_each(|r| {
            let mut begin = r.0;
            let mut end: u64;
            loop {
                if begin >= r.1 {
                    break;
                }

                let found_map = map
                    .iter()
                    .find(|m| m.input <= begin && begin < m.input + m.range);
                match found_map {
                    Some(mp) => {
                        end = min(mp.input + mp.range, r.1);
                        new_ranges
                            .push((mp.output + (begin - mp.input), mp.output + (end - mp.input)));
                    }
                    None => {
                        end = r.1;
                        new_ranges.push((begin, end));
                    }
                };
                begin = end;
            }
        });
        *ranges = new_ranges;
    }
}

fn part_two((seeds, maps): &ParseResult) -> u64 {
    let mut part_two_ranges: Vec<(u64, u64)> =
        seeds.chunks(2).map(|s| (s[0], s[0] + s[1])).collect();
    transform(&mut part_two_ranges, &maps);
    part_two_ranges.iter().map(|r| r.0).min().unwrap()
}

fn part_one((seeds, maps): &ParseResult) -> u64 {
    let mut part_one_ranges: Vec<(u64, u64)> = seeds.iter().map(|&s| (s, s + 1)).collect();
    transform(&mut part_one_ranges, &maps);
    part_one_ranges.iter().map(|r| r.0).min().unwrap()
}

fn parse(input: &str, _part: u8) -> ParseResult {
    let mut chunks = input.split("\n\n");

    let seeds = chunks
        .next()
        .unwrap()
        .split(": ")
        .nth(1)
        .unwrap()
        .split_whitespace()
        .map(str::parse::<u64>)
        .map_while(Result::ok)
        .collect::<Vec<_>>();

    let maps = chunks
        .map(|chunk| {
            chunk
                .split("\n")
                .skip(1)
                .filter_map(|line| {
                    if line.is_empty() {
                        None
                    } else {
                        let mappings = line
                            .split_whitespace()
                            .map(str::parse::<u64>)
                            .map_while(Result::ok)
                            .collect::<Vec<_>>();
                        Some(Mapping {
                            output: mappings[0],
                            input: mappings[1],
                            range: mappings[2],
                        })
                    }
                })
                .collect::<Vec<_>>()
        })
        .collect::<Vec<_>>();

    (seeds, maps)
}

pub fn run(input: &str) {
    let parsed = parse(input, 0);
    let part_one_answer = part_one(&parsed);
    let part_two_answer = part_two(&parsed);

    println!("Part One: {part_one_answer}");
    println!("Part Two: {part_two_answer}");
}

#[cfg(test)]
mod test {
    use super::{parse, part_one, part_two};

    const INPUT: &str = "seeds: 79 14 55 13

seed-to-soil map:
50 98 2
52 50 48

soil-to-fertilizer map:
0 15 37
37 52 2
39 0 15

fertilizer-to-water map:
49 53 8
0 11 42
42 0 7
57 7 4

water-to-light map:
88 18 7
18 25 70

light-to-temperature map:
45 77 23
81 45 19
68 64 13

temperature-to-humidity map:
0 69 1
1 0 69

humidity-to-location map:
60 56 37
56 93 4";

    #[test]
    fn part_one_test() {
        let expected = 35;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 46;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
