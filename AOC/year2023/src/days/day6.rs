use std::u64;

pub fn day6(input: &str) -> [u32; 2] {
    let lines = input.lines().collect::<Vec<_>>();

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

    let get_count = |time_limit: u64, dist_limit: u64| -> u32 {
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
    };

    let possibles = times
        .iter()
        .enumerate()
        .map(|(idx, &time)| get_count(time, distance[idx]))
        .collect::<Vec<_>>();

    let mut part_one_answer = 1;
    for p in possibles {
        part_one_answer *= p;
    }

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

    let part_two_answer = get_count(time, distance);

    return [part_one_answer as u32, part_two_answer as u32];
}

#[cfg(test)]
mod test {
    const INPUT: &str = "Time:      7  15   30
Distance:  9  40  200";

    #[test]
    fn day6() {
        let [part1, part2] = super::day6(INPUT);

        assert_eq!(part1, 288);
        assert_eq!(part2, 71503);
    }
}
