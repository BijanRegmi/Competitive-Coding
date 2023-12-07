#[derive(Debug)]
struct Pool {
    red: u32,
    blue: u32,
    green: u32,
}

#[derive(Debug)]
struct Game {
    id: u32,
    pools: Vec<Pool>,
}

type ParseResult = Vec<Game>;

const LIMITS: Pool = Pool {
    red: 12,
    green: 13,
    blue: 14,
};

fn part_one(input: &ParseResult) -> u32 {
    input
        .iter()
        .filter(|game| {
            game.pools.iter().all(|pool| {
                pool.red <= LIMITS.red && pool.green <= LIMITS.green && pool.blue <= LIMITS.blue
            })
        })
        .map(|game| game.id)
        .sum::<u32>()
}

fn part_two(input: &ParseResult) -> u32 {
    input
        .iter()
        .map(|game| {
            let (mut r, mut g, mut b) = (0, 0, 0);
            game.pools.iter().for_each(|pool| {
                if pool.red > r {
                    r = pool.red;
                }
                if pool.green > g {
                    g = pool.green;
                }
                if pool.blue > b {
                    b = pool.blue;
                }
            });
            r * g * b
        })
        .sum::<u32>()
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input
        .lines()
        .enumerate()
        .map(|(idx, line)| {
            let y = line.split(":").collect::<Vec<&str>>();
            let pools = y[1]
                .trim()
                .split(";")
                .map(|pool| {
                    let (mut r, mut g, mut b) = (0, 0, 0);
                    pool.split(",").for_each(|c| {
                        let val = c.trim().split_whitespace().collect::<Vec<&str>>();
                        match val[1] {
                            "red" => r = val[0].parse().unwrap_or(0),
                            "green" => g = val[0].parse().unwrap_or(0),
                            "blue" => b = val[0].parse().unwrap_or(0),
                            &_ => panic!("Unexpected color"),
                        }
                    });
                    Pool {
                        red: r,
                        green: g,
                        blue: b,
                    }
                })
                .collect::<Vec<Pool>>();
            Game {
                id: (idx + 1) as u32,
                pools,
            }
        })
        .collect()
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

    const INPUT: &str = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green";

    #[test]
    fn part_one_test() {
        let expected = 8;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 2286;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
