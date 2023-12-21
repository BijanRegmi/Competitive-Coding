type ParseResult<'a> = &'a str;

fn shoelace_area(coord: Vec<(i64, i64)>) -> i64 {
    let mut area = 0;
    coord.windows(2).for_each(|v| {
        let a = v[0];
        let b = v[1];
        area += a.0 * b.1 - a.1 * b.0;
    });
    area /= 2;
    area
}

fn part_one(input: &ParseResult) -> u64 {
    let mut coord: Vec<(i64, i64)> = vec![];
    coord.push((0, 0));

    let mut current = (0, 0);
    let mut boundary_points = 0;

    input.lines().for_each(|line| {
        let parts = line.split_whitespace().collect::<Vec<_>>();
        let dist = parts[1].parse::<i64>().unwrap();
        boundary_points += dist;
        current = match parts[0] {
            "U" => (current.0, current.1 - dist),
            "R" => (current.0 + dist, current.1),
            "D" => (current.0, current.1 + dist),
            "L" => (current.0 - dist, current.1),
            _ => unreachable!(),
        };
        coord.push(current);
    });

    let area = shoelace_area(coord);

    let internal_points = area - boundary_points / 2 + 1; // Pick's theorem
    (internal_points + boundary_points) as u64
}

fn part_two(input: &ParseResult) -> u64 {
    let mut coord: Vec<(i64, i64)> = vec![];
    coord.push((0, 0));

    let mut current = (0, 0);
    let mut boundary_points = 0;

    input.lines().for_each(|line| {
        let hex = line.split("#").last().unwrap();
        let dist = i64::from_str_radix(&hex[..5], 16).unwrap();
        boundary_points += dist;
        current = match &hex[5..6] {
            "3" => (current.0, current.1 - dist),
            "0" => (current.0 + dist, current.1),
            "1" => (current.0, current.1 + dist),
            "2" => (current.0 - dist, current.1),
            _ => unreachable!(),
        };
        coord.push(current);
    });

    let area = shoelace_area(coord);

    let internal_points = area - boundary_points / 2 + 1; // Pick's theorem
    (internal_points + boundary_points) as u64
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input
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

    const INPUT: &str = "R 6 (#70c710)
D 5 (#0dc571)
L 2 (#5713f0)
D 2 (#d2c081)
R 2 (#59c680)
D 2 (#411b91)
L 5 (#8ceee2)
U 2 (#caa173)
L 1 (#1b58a2)
U 2 (#caa171)
R 2 (#7807d2)
U 3 (#a77fa3)
L 2 (#015232)
U 2 (#7a21e3)";

    #[test]
    fn part_one_test() {
        let expected = 62;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 952408144115;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
