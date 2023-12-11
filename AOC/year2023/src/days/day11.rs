type ParseResult = Vec<Vec<char>>;

fn solve(input: &ParseResult, times: u64) -> u64 {
    let mut empty_rows = vec![];
    for row_idx in 0..input.len() {
        if input[row_idx].iter().all(|x| x == &'.') {
            empty_rows.push(row_idx);
        }
    }

    let mut empty_cols = vec![];
    for col_idx in 0..input[0].len() {
        if input.iter().map(|line| line[col_idx]).all(|x| x == '.') {
            empty_cols.push(col_idx);
        }
    }

    let mut galaxy_cords = vec![];
    for (row_idx, row) in input.iter().enumerate() {
        for (col_idx, col) in row.iter().enumerate() {
            if col == &'#' {
                galaxy_cords.push((row_idx, col_idx));
            }
        }
    }

    let mut dist: u64 = 0;
    for i in 0..galaxy_cords.len() {
        let source = galaxy_cords[i];
        for j in i + 1..galaxy_cords.len() {
            let dest = galaxy_cords[j];

            let lx = source.0.min(dest.0);
            let rx = source.0.max(dest.0);
            let ly = source.1.min(dest.1);
            let ry = source.1.max(dest.1);
            let ex = empty_rows.iter().filter(|&r| r > &lx && r < &rx).count() as u64;
            let ey = empty_cols.iter().filter(|&r| r > &ly && r < &ry).count() as u64;

            let x = source.0.abs_diff(dest.0) as u64 - ex;
            let y = source.1.abs_diff(dest.1) as u64 - ey;
            let d = x + y + ex * times + ey * times;

            dist += d;
        }
    }
    dist
}

fn part_one(input: &ParseResult) -> u64 {
    solve(input, 2)
}

fn part_two(input: &ParseResult) -> u64 {
    solve(input, 1000000)
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input
        .lines()
        .map(|line| line.chars().collect::<Vec<_>>())
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

    const INPUT: &str = "...#......
.......#..
#.........
..........
......#...
.#........
.........#
..........
.......#..
#...#.....";

    #[test]
    fn part_one_test() {
        let expected = 374;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 82000210;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
