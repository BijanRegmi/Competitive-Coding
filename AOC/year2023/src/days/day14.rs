use std::collections::HashMap;

type ParseResult = Vec<Vec<char>>;

fn cycle(input: &mut ParseResult) {
    let row_len = input.len();
    let col_len = input[0].len();

    // North
    for col in 0..col_len {
        for row in 0..row_len {
            if input[row][col] == '.' {
                for down_row in row..row_len {
                    if input[down_row][col] == '#' {
                        break;
                    } else if input[down_row][col] == 'O' {
                        input[row][col] = 'O';
                        input[down_row][col] = '.';
                        break;
                    }
                }
            }
        }
    }
    // West
    for row in 0..row_len {
        for col in 0..col_len {
            if input[row][col] == '.' {
                for right_col in col..col_len {
                    if input[row][right_col] == '#' {
                        break;
                    } else if input[row][right_col] == 'O' {
                        input[row][col] = 'O';
                        input[row][right_col] = '.';
                        break;
                    }
                }
            }
        }
    }
    // South
    for col in 0..col_len {
        for row in (0..row_len).rev() {
            if input[row][col] == '.' {
                for up_row in (0..row).rev() {
                    if input[up_row][col] == '#' {
                        break;
                    } else if input[up_row][col] == 'O' {
                        input[row][col] = 'O';
                        input[up_row][col] = '.';
                        break;
                    }
                }
            }
        }
    }
    // East
    for row in 0..row_len {
        for col in (0..col_len).rev() {
            if input[row][col] == '.' {
                for left_col in (0..col).rev() {
                    if input[row][left_col] == '#' {
                        break;
                    } else if input[row][left_col] == 'O' {
                        input[row][col] = 'O';
                        input[row][left_col] = '.';
                        break;
                    }
                }
            }
        }
    }
}

fn part_one(input: &mut ParseResult) -> u32 {
    let row_len = input.len();
    let col_len = input[0].len();

    for col in 0..col_len {
        for row in 0..row_len {
            if input[row][col] == '.' {
                for down_row in row..row_len {
                    if input[down_row][col] == '#' {
                        break;
                    } else if input[down_row][col] == 'O' {
                        input[row][col] = 'O';
                        input[down_row][col] = '.';
                        break;
                    }
                }
            }
        }
    }

    let mut answer = 0;
    for row in 0..row_len {
        for col in 0..col_len {
            if input[row][col] == 'O' {
                answer += row_len - row;
            }
        }
    }

    answer as u32
}

fn part_two(input: &mut ParseResult) -> u32 {
    let row_len = input.len();
    let col_len = input[0].len();

    let mut seen: HashMap<String, usize> = HashMap::new();

    let to_do = 1000000000;
    let mut completed = 0;
    let mut cycle_start = 0;

    while completed != to_do {
        cycle(input);
        let config = input
            .iter()
            .map(|line| line.iter().collect::<String>())
            .collect::<String>();
        completed += 1;
        if let Some(&old_idx) = seen.get(&config) {
            cycle_start = old_idx;
            break;
        } else {
            seen.insert(config, completed);
        }
    }

    let remaining = (to_do - cycle_start) % (completed - cycle_start);
    for _ in 0..remaining {
        cycle(input);
    }

    let mut answer = 0;
    for row in 0..row_len {
        for col in 0..col_len {
            if input[row][col] == 'O' {
                answer += row_len - row;
            }
        }
    }

    answer as u32
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input.lines().map(|line| line.chars().collect()).collect()
}

pub fn run(input: &str) {
    let part_one_answer = part_one(&mut parse(input, 1));
    println!("Part One: {part_one_answer}");

    let part_two_answer = part_two(&mut parse(input, 2));
    println!("Part Two: {part_two_answer}");
}

#[cfg(test)]
mod test {
    use super::{parse, part_one, part_two};

    const INPUT: &str = "O....#....
O.OO#....#
.....##...
OO.#O....O
.O.....O#.
O.#..O.#.#
..O..#O..O
.......O..
#....###..
#OO..#....";

    #[test]
    fn part_one_test() {
        let expected = 136;
        let output = part_one(&mut parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 64;
        let output = part_two(&mut parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
