use std::collections::HashMap;

#[derive(Debug)]
struct Entry {
    target: u64,
    source: u64,
    range: u64,
}

#[derive(Debug)]
struct ConversionMap {
    destination: String,
    entries: Vec<Entry>,
}

impl ConversionMap {
    fn get_target(&self, source: u64) -> Option<&Entry> {
        self.entries
            .iter()
            .find(|&e| source >= e.source && source < e.source + e.range)
    }
}

pub fn day5(input: &str) -> [u64; 2] {
    let lines: Vec<&str> = input.lines().collect();

    let mut map: HashMap<&str, ConversionMap> = HashMap::new();

    let seeds: Vec<u64> = lines[0]
        .split(": ")
        .nth(1)
        .unwrap()
        .split_whitespace()
        .filter_map(|n| n.parse::<u64>().ok())
        .collect();

    let mut src_dest = ["", ""];
    for &line in lines.iter().skip(2) {
        if src_dest[0].is_empty() {
            let arr: Vec<&str> = line.split("-to-").collect();
            src_dest[0] = arr[0];
            src_dest[1] = arr[1].split_whitespace().nth(0).unwrap();
            continue;
        }
        if line.trim().is_empty() {
            src_dest = ["", ""];
            continue;
        }

        let nums = line
            .split_whitespace()
            .filter_map(|n| n.parse::<u64>().ok())
            .collect::<Vec<u64>>();

        let conv_map = map.get_mut(src_dest[0]);
        match conv_map {
            Some(m) => m.entries.push(Entry {
                target: nums[0],
                source: nums[1],
                range: nums[2],
            }),
            None => {
                map.insert(
                    src_dest[0],
                    ConversionMap {
                        destination: src_dest[1].to_string(),
                        entries: vec![Entry {
                            target: nums[0],
                            source: nums[1],
                            range: nums[2],
                        }],
                    },
                );
            }
        };
    }

    let part_one_answer = seeds
        .iter()
        .map(|&seed| {
            let mut current_key = "seed";
            let mut source = seed;
            loop {
                let m = map.get(current_key).unwrap();
                let matched_entry = m.get_target(source);
                source = match matched_entry {
                    Some(entry) => entry.target + (source - entry.source),
                    None => source,
                };
                if m.destination == "location" {
                    break;
                }
                current_key = &m.destination;
            }
            source
        })
        .min()
        .unwrap();

    dbg!(part_one_answer);

    let part_two_answer = seeds
        .chunks(2)
        .map(|seed| {
            let mut min = seed[0];
            let mut it = seed[0]..seed[0] + seed[1];
            while let Some(s) = it.next() {
                let mut current_key = "seed";
                let mut source = s;
                loop {
                    let m = map.get(current_key).unwrap();
                    let matched_entry = m.get_target(source);
                    source = match matched_entry {
                        Some(entry) => entry.target + (source - entry.source),
                        None => source,
                    };
                    if m.destination == "location" {
                        break;
                    }
                    current_key = &m.destination;
                }
                if source < min {
                    min = source;
                }
            }
            min
        })
        .min()
        .unwrap();

    return [part_one_answer, part_two_answer];
}

#[cfg(test)]
mod test {
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
    fn day5() {
        let [part1, part2] = super::day5(INPUT);

        assert_eq!(part1, 35);
        assert_eq!(part2, 46);
    }
}
