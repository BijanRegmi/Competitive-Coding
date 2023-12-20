use std::collections::BinaryHeap;

type ParseResult = Vec<Vec<u64>>;

#[derive(Clone, Debug, PartialEq, Eq)]
struct Node {
    x: i64,
    y: i64,
    dir: u8,
    cnt: u64,
    cost: u64,
}

impl Ord for Node {
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.cost.cmp(&self.cost)
    }
}

impl PartialOrd for Node {
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

fn solve(input: &ParseResult, min: u64, max: u64) -> u64 {
    let mut queue: BinaryHeap<Node> = BinaryHeap::new();
    queue.push(Node {
        x: 0,
        y: 0,
        dir: 1,
        cnt: 1,
        cost: 0 as u64,
    });
    queue.push(Node {
        x: 0,
        y: 0,
        dir: 2,
        cnt: 1,
        cost: 0 as u64,
    });
    let mut visited: Vec<(i64, i64, u8, u64)> = Vec::new();
    let target = (input[0].len() as i64 - 1, input.len() as i64 - 1);

    while !queue.is_empty() {
        let n = queue.pop().unwrap();
        if (n.x, n.y) == target && n.cnt >= min {
            return n.cost;
        }
        if visited.contains(&(n.x, n.y, n.dir, n.cnt)) {
            continue;
        }
        for dir in 0..4 as u8 {
            if dir.abs_diff(n.dir) == 2 {
                continue;
            }

            let new_xy = match dir {
                0 => (n.x, n.y - 1),
                1 => (n.x + 1, n.y),
                2 => (n.x, n.y + 1),
                3 => (n.x - 1, n.y),
                _ => unreachable!(),
            };
            // If out of bounds
            if new_xy.0 < 0
                || new_xy.1 < 0
                || new_xy.0 >= input[0].len() as i64
                || new_xy.1 >= input.len() as i64
            {
                continue;
            }
            // If reached max flow in that direction
            if n.cnt == max && n.dir == dir {
                continue;
            }
            // If still at minimum
            if n.cnt < min && n.dir != dir {
                continue;
            }
            let new_node = Node {
                x: new_xy.0,
                y: new_xy.1,
                dir,
                cnt: if n.dir == dir { n.cnt + 1 } else { 1 },
                cost: n.cost + input[new_xy.1 as usize][new_xy.0 as usize],
            };
            queue.push(new_node);
        }
        visited.push((n.x, n.y, n.dir, n.cnt));
    }

    0
}

fn part_one(input: &ParseResult) -> u64 {
    solve(input, 1, 3)
}

fn part_two(input: &ParseResult) -> u64 {
    solve(input, 4, 10)
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input
        .lines()
        .map(|l| {
            l.chars()
                .map(|c| c.to_digit(10).unwrap_or(0) as u64)
                .collect()
        })
        .collect()
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

    const INPUT_TWO: &str = "111111111111
999999999991
999999999991
999999999991
999999999991";

    const INPUT: &str = "2413432311323
3215453535623
3255245654254
3446585845452
4546657867536
1438598798454
4457876987766
3637877979653
4654967986887
4564679986453
1224686865563
2546548887735
4322674655533";

    #[test]
    fn part_one_test() {
        let expected = 102;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test_a() {
        let expected = 94;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test_b() {
        let expected = 71;
        let output = part_two(&parse(INPUT_TWO, 2));
        assert_eq!(expected, output);
    }
}
