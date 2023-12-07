use std::collections::HashMap;

type ParseResult<'a> = &'a str;

fn part_one(input: ParseResult) -> u32 {
    let mut sum: u32 = 0;

    let lines = input.lines().collect::<Vec<&str>>();
    let line_len: usize = lines[0].len();

    let valid_symbols = ['*', '=', '+', '/', '&', '#', '%', '-', '$', '@'];

    let is_symbol = |ch: Option<char>| match ch {
        None => false,
        Some(x) if valid_symbols.contains(&x) => true,
        Some(_) => false,
    };

    let is_part_number = |row: usize, start_idx: usize, end_index: usize| {
        let i = if start_idx != 0 {
            start_idx - 1
        } else {
            start_idx
        };
        let j = if end_index != line_len - 1 {
            end_index + 1
        } else {
            end_index
        };

        // Check same row left
        if start_idx != i && is_symbol(lines[row].chars().nth(i)) {
            return true;
        }

        // Check same row right
        if end_index != j && is_symbol(lines[row].chars().nth(j)) {
            return true;
        }

        // Check upper row
        if row != 0 {
            for n in i..j + 1 {
                if is_symbol(lines[row - 1].chars().nth(n)) {
                    return true;
                }
            }
        }

        // Check lower row
        if row != lines.len() - 1 {
            for n in i..j + 1 {
                if is_symbol(lines[row + 1].chars().nth(n)) {
                    return true;
                }
            }
        }

        return false;
    };

    lines.iter().enumerate().for_each(|(line_idx, line)| {
        let mut start_idx = None;
        let mut end_idx: usize;
        let mut char_itr = line.chars().enumerate().peekable();
        while let Some((char_idx, ch)) = char_itr.next() {
            if ch.is_ascii_digit() {
                start_idx = start_idx.or(Some(char_idx));
                end_idx = char_idx;
                let next_char = char_itr.peek();

                let mut update_sum = || {
                    sum += if is_part_number(line_idx, start_idx.unwrap(), end_idx) {
                        let num = line
                            .get(start_idx.unwrap()..end_idx + 1)
                            .unwrap_or("0")
                            .parse::<u32>()
                            .unwrap_or(0);
                        num
                    } else {
                        0
                    };
                    start_idx = None;
                };

                match next_char {
                    None => update_sum(),
                    Some((_, nch)) if !nch.is_ascii_digit() => update_sum(),
                    Some(_) => {}
                }
            }
        }
    });
    return sum;
}

fn part_two(input: ParseResult) -> u32 {
    let lines = input.lines().collect::<Vec<&str>>();
    let line_len: usize = lines[0].len();

    let is_symbol = |ch: Option<char>| match ch {
        None => false,
        Some(x) if x == '*' => true,
        Some(_) => false,
    };

    let mut part_nums = HashMap::<(usize, usize), Vec<u32>>::new();

    let mut insert_to_hash = |i: usize, j: usize, value: u32| {
        let key = (i, j);
        let x = part_nums.get_mut(&key);
        match x {
            None => {
                part_nums.insert(key, vec![value]);
            }
            Some(v) => {
                v.push(value);
            }
        };
    };

    let mut update_hash_map = |row: usize, start_idx: usize, end_index: usize| {
        let num = lines[row]
            .get(start_idx..end_index + 1)
            .unwrap_or("0")
            .parse::<u32>()
            .unwrap_or(0);

        let i = if start_idx != 0 {
            start_idx - 1
        } else {
            start_idx
        };
        let j = if end_index != line_len - 1 {
            end_index + 1
        } else {
            end_index
        };

        // Check same row left
        if start_idx != i && is_symbol(lines[row].chars().nth(i)) {
            insert_to_hash(i, row, num);
        }

        // Check same row right
        if end_index != j && is_symbol(lines[row].chars().nth(j)) {
            insert_to_hash(j, row, num);
        }

        // Check upper row
        if row != 0 {
            for n in i..j + 1 {
                if is_symbol(lines[row - 1].chars().nth(n)) {
                    insert_to_hash(n, row - 1, num);
                }
            }
        }

        // Check lower row
        if row != lines.len() - 1 {
            for n in i..j + 1 {
                if is_symbol(lines[row + 1].chars().nth(n)) {
                    insert_to_hash(n, row + 1, num);
                }
            }
        }
    };

    lines.iter().enumerate().for_each(|(line_idx, line)| {
        let mut start_idx = None;
        let mut end_idx: usize;
        let mut char_itr = line.chars().enumerate().peekable();
        while let Some((char_idx, ch)) = char_itr.next() {
            if ch.is_ascii_digit() {
                start_idx = start_idx.or(Some(char_idx));
                end_idx = char_idx;
                let next_char = char_itr.peek();

                match next_char {
                    None => {
                        update_hash_map(line_idx, start_idx.unwrap(), end_idx);
                        start_idx = None;
                    }
                    Some((_, nch)) if !nch.is_ascii_digit() => {
                        update_hash_map(line_idx, start_idx.unwrap(), end_idx);
                        start_idx = None;
                    }
                    Some(_) => {}
                }
            }
        }
    });

    part_nums
        .iter()
        .filter(|(_, v)| v.len() == 2)
        .map(|(_, v)| {
            let mut prod = 1;
            for n in v {
                prod *= *n;
            }
            prod
        })
        .sum::<u32>()
}

fn parse(input: &str, _part: u8) -> ParseResult {
    input
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

    const INPUT: &str = "467..114..
...*......
..35..633.
......#...
617*......
.....+.58.
..592.....
......755.
...$.*....
.664.598..";

    #[test]
    fn part_one_test() {
        let expected = 4361;
        let output = part_one(&parse(INPUT, 1));
        assert_eq!(expected, output);
    }

    #[test]
    fn part_two_test() {
        let expected = 467835;
        let output = part_two(&parse(INPUT, 2));
        assert_eq!(expected, output);
    }
}
