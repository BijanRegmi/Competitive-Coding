use std::collections::{HashMap, VecDeque};

type ParseResult = Vec<Vec<char>>;

#[derive(PartialEq, Clone, Copy, Debug)]
enum Direction {
    UP = 0,
    Down,
    Right,
    Left,
}

fn get_energized(input: &ParseResult, start: (i32, i32), start_direction: Direction) -> u64 {
    let mut visited: HashMap<(i32, i32), Vec<Direction>> = HashMap::new();
    let mut queue: VecDeque<(i32, i32, Direction)> =
        VecDeque::from([(start.0, start.1, start_direction)]);

    while !queue.is_empty() {
        let (x, y, heading) = queue.pop_front().unwrap();
        if x < 0 || x >= input[0].len() as i32 || y < 0 || y >= input.len() as i32 {
            continue;
        }

        let node = visited.entry((x, y)).or_insert(Vec::new());
        if node.contains(&heading) {
            continue;
        }

        node.push(heading);
        let c = input[y as usize][x as usize];
        let next_cord = match heading {
            Direction::Right => (x + 1, y),
            Direction::Left => (x - 1, y),
            Direction::Down => (x, y + 1),
            Direction::UP => (x, y - 1),
        };
        // println!("({x}, {y}): {c}");
        match c {
            '.' => queue.push_back((next_cord.0, next_cord.1, heading)),
            '|' => {
                if heading == Direction::Right || heading == Direction::Left {
                    queue.push_back((x, y - 1, Direction::UP));
                    queue.push_back((x, y + 1, Direction::Down));
                } else {
                    queue.push_back((next_cord.0, next_cord.1, heading))
                }
            }
            '-' => {
                if heading == Direction::Down || heading == Direction::UP {
                    queue.push_back((x + 1, y, Direction::Right));
                    queue.push_back((x - 1, y, Direction::Left));
                } else {
                    queue.push_back((next_cord.0, next_cord.1, heading))
                }
            }
            '\\' => match heading {
                Direction::Right => queue.push_back((x, y + 1, Direction::Down)),
                Direction::Left => queue.push_back((x, y - 1, Direction::UP)),
                Direction::UP => queue.push_back((x - 1, y, Direction::Left)),
                Direction::Down => queue.push_back((x + 1, y, Direction::Right)),
            },
            '/' => match heading {
                Direction::Right => queue.push_back((x, y - 1, Direction::UP)),
                Direction::Left => queue.push_back((x, y + 1, Direction::Down)),
                Direction::UP => queue.push_back((x + 1, y, Direction::Right)),
                Direction::Down => queue.push_back((x - 1, y, Direction::Left)),
            },
            _ => panic!(),
        }
    }
    visited.len() as u64
}

fn part_one(input: &ParseResult) -> u64 {
    get_energized(input, (0, 0), Direction::Right)
}

fn part_two(input: &ParseResult) -> u64 {
    // Top
    let t = (0..input[0].len())
        .map(|n| get_energized(input, (n as i32, 0), Direction::Down))
        .max()
        .unwrap();
    // Bottom
    let b = (0..input[0].len())
        .map(|n| get_energized(input, (n as i32, input.len() as i32 - 1), Direction::UP))
        .max()
        .unwrap();
    // Left
    let l = (0..input.len())
        .map(|n| get_energized(input, (0, n as i32), Direction::Right))
        .max()
        .unwrap();
    // Right
    let r = (0..input.len())
        .map(|n| {
            get_energized(
                input,
                (input[0].len() as i32 - 1, n as i32),
                Direction::Left,
            )
        })
        .max()
        .unwrap();

    *(vec![t, b, l, r]).iter().max().unwrap()
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input.lines().map(|line| line.chars().collect()).collect()
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

    const INPUT: &str = ".|...\\....
|.-.\\.....
.....|-...
........|.
..........
.........\\
..../.\\\\..
.-.-/..|..
.|....-|.\\
..//.|....";

    #[test]
    fn part_one_test() {
        let expected = 46;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 51;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
