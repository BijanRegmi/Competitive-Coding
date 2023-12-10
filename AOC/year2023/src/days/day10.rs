use std::collections::HashSet;

#[derive(Debug, PartialEq, Clone, Copy)]
enum Direction {
    NORTH = 0,
    SOUTH = 1,
    EAST = 2,
    WEST = 3,
    NONE = 4,
    ANY = 5,
}

type ParseResult = Vec<Vec<(Direction, Direction)>>;

fn get_start_idx(input: &ParseResult) -> (isize, isize) {
    for (row_idx, row) in input.iter().enumerate() {
        for (col_idx, col) in row.iter().enumerate() {
            if col.0 == Direction::ANY {
                return (row_idx as isize, col_idx as isize);
            }
        }
    }
    (0, 0)
}

fn get_path_cords(
    input: &ParseResult,
    coming_from: Direction,
    cord: (isize, isize),
) -> (HashSet<(isize, isize)>, Direction) {
    let mut arguments = vec![(coming_from, cord)];
    let mut coords: HashSet<(isize, isize)> = HashSet::new();
    let mut end_direction: Direction = Direction::NONE;
    while arguments.len() != 0 {
        let (coming_from, cord) = arguments.pop().unwrap();
        if cord.0 < 0
            || cord.1 < 0
            || cord.0 > input.len() as isize
            || cord.1 > input[0].len() as isize
        {
            continue;
        }

        let cur = input[cord.0 as usize][cord.1 as usize];

        if cur.0 == Direction::ANY {
            end_direction = coming_from;
            coords.insert(cord);
            break;
        }

        let going_to = if coming_from == cur.0 {
            cur.1
        } else if coming_from == cur.1 {
            cur.0
        } else {
            Direction::NONE
        };

        // If There is no other way to go
        if going_to == Direction::NONE {
            continue;
        }

        coords.insert(cord);
        let next_argument = match going_to {
            Direction::NORTH => (Direction::SOUTH, (cord.0 - 1, cord.1)),
            Direction::SOUTH => (Direction::NORTH, (cord.0 + 1, cord.1)),
            Direction::EAST => (Direction::WEST, (cord.0, cord.1 + 1)),
            Direction::WEST => (Direction::EAST, (cord.0, cord.1 - 1)),
            _ => panic!(),
        };
        arguments.push(next_argument);
    }

    (coords, end_direction)
}

fn part_one(input: &ParseResult) -> u32 {
    let start_idx = get_start_idx(input);

    let mut possible_ways = vec![
        (Direction::WEST, (start_idx.0, start_idx.1 + 1)),
        (Direction::EAST, (start_idx.0, start_idx.1 - 1)),
        (Direction::SOUTH, (start_idx.0 - 1, start_idx.1)),
        (Direction::NORTH, (start_idx.0 + 1, start_idx.1)),
    ];

    let mut path_length: u32 = 0;
    while !possible_ways.is_empty() {
        let way = possible_ways.pop().unwrap();
        let (cords, _) = get_path_cords(input, way.0, way.1);
        if cords.len() > 0 {
            path_length = cords.len() as u32;
            break;
        }
    }

    path_length / 2
}

fn part_two(input: &ParseResult) -> u32 {
    let start_idx = get_start_idx(input);

    let mut possible_ways = vec![
        (Direction::WEST, (start_idx.0, start_idx.1 + 1)),
        (Direction::EAST, (start_idx.0, start_idx.1 - 1)),
        (Direction::SOUTH, (start_idx.0 - 1, start_idx.1)),
        (Direction::NORTH, (start_idx.0 + 1, start_idx.1)),
    ];

    let mut coords: HashSet<(isize, isize)> = HashSet::new();
    let mut is_start_straight = false;
    while !possible_ways.is_empty() {
        let way = possible_ways.pop().unwrap();
        let res = get_path_cords(input, way.0, way.1);
        coords = res.0;
        if coords.len() > 0 {
            is_start_straight = res.1 == Direction::NORTH || way.0 == Direction::SOUTH;
            break;
        }
    }

    let mut area = 0;
    for i in 0..input.len() {
        let mut counting = false;
        for j in 0..input[0].len() {
            if coords.contains(&(i as isize, j as isize)) {
                if input[i][j].0 == Direction::NORTH
                    || (input[i][j].0 == Direction::ANY && is_start_straight)
                {
                    counting = !counting;
                }
            } else if counting {
                area += 1;
            }
        }
    }
    area
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input
        .lines()
        .map(|line| {
            line.chars()
                .map(|c| match c {
                    '|' => (Direction::NORTH, Direction::SOUTH),
                    'L' => (Direction::NORTH, Direction::EAST),
                    '-' => (Direction::EAST, Direction::WEST),
                    'J' => (Direction::NORTH, Direction::WEST),
                    '7' => (Direction::SOUTH, Direction::WEST),
                    'F' => (Direction::SOUTH, Direction::EAST),
                    '.' => (Direction::NONE, Direction::NONE),
                    'S' => (Direction::ANY, Direction::ANY),
                    _ => panic!(),
                })
                .collect::<Vec<_>>()
        })
        .collect::<Vec<_>>()
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

    const INPUT: &str = "7-F7-
.FJ|7
SJLL7
|F--J
LJ.LJ";

    const INPUT_ONE: &str = "...........
.S-------7.
.|F-----7|.
.||.....||.
.||.....||.
.|L-7.F-J|.
.|..|.|..|.
.L--J.L--J.
...........";

    const INPUT_TWO: &str = ".F----7F7F7F7F-7....
.|F--7||||||||FJ....
.||.FJ||||||||L7....
FJL7L7LJLJ||LJ.L-7..
L--J.L7...LJS7F-7L7.
....F-J..F7FJ|L7L7L7
....L7.F7||L7|.L7L7|
.....|FJLJ|FJ|F7|.LJ
....FJL-7.||.||||...
....L---J.LJ.LJLJ...";

    const INPUT_THREE: &str = "FF7FSF7F7F7F7F7F---7
L|LJ||||||||||||F--J
FL-7LJLJ||||||LJL-77
F--JF--7||LJLJ7F7FJ-
L---JF-JLJ.||-FJLJJ7
|F|F-JF---7F7-L7L|7|
|FFJF7L7F-JF7|JL---7
7-L-JL7||F7|L7F-7F7|
L.L7LFJ|||||FJL7||LJ
L7JLJL-JLJLJL--JLJ.L";

    #[test]
    fn part_one_test() {
        let expected = 8;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test_one() {
        let expected = 4;
        let output = part_two(&parse(INPUT_ONE, 2));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test_two() {
        let expected = 8;
        let output = part_two(&parse(INPUT_TWO, 2));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test_three() {
        let expected = 10;
        let output = part_two(&parse(INPUT_THREE, 2));
        assert_eq!(expected, output);
    }
}
