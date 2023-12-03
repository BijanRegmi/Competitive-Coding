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

pub fn day2(input: &str) -> [u32; 2] {
    let limits = Pool {
        red: 12,
        green: 13,
        blue: 14,
    };

    let games = input
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
        .collect::<Vec<Game>>();

    let part_one_output = games
        .iter()
        .filter(|game| {
            game.pools.iter().all(|pool| {
                pool.red <= limits.red && pool.green <= limits.green && pool.blue <= limits.blue
            })
        })
        .map(|game| game.id)
        .sum::<u32>();

    let part_two_output = games
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
        .sum::<u32>();

    return [part_one_output, part_two_output];
}
