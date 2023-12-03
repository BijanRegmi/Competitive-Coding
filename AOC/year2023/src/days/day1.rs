fn determine_first_p1(line: &str) -> u32 {
    line.chars()
        .find(|c| c.is_digit(10))
        .map(|c| c.to_digit(10).unwrap_or(0))
        .unwrap_or(0)
}

fn determine_last_p1(line: &str) -> u32 {
    line.chars()
        .rev()
        .find(|c| c.is_digit(10))
        .map(|c| c.to_digit(10).unwrap_or(0))
        .unwrap_or(0)
}

const NUMS: [&str; 9] = [
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
];

fn determine_first_p2(line: &str) -> u32 {
    let mut i = 0;
    while i < line.len() {
        let x = line.chars().nth(i).unwrap().to_digit(10);
        if let Some(digit) = x {
            return digit;
        }

        for n in 3..6 {
            let digit = line.get(i..i + n);
            if let Some(num) = digit {
                if let Some(idx) = NUMS.iter().position(|n| *n == num) {
                    return (idx + 1) as u32;
                }
            }
        }
        i += 1;
    }
    return 0;
}

fn determine_last_p2(line: &str) -> u32 {
    let mut j = line.len() - 1;
    loop {
        let x = line.chars().nth(j).unwrap().to_digit(10);
        if let Some(digit) = x {
            return digit;
        }

        for n in 3..6 {
            if j < n {
                continue;
            }
            let digit = line.get(j - n + 1..j + 1);
            if let Some(num) = digit {
                if let Some(idx) = NUMS.iter().position(|n| *n == num) {
                    return (idx + 1) as u32;
                }
            }
        }
        j -= 1;
    }
}

pub fn day1(input: &str) -> [u32; 2] {
    let part_one_output: u32 = input
        .lines()
        .map(|s| determine_first_p1(s) * 10 + determine_last_p1(s))
        .sum();

    let part_two_output: u32 = input
        .lines()
        .map(|s| determine_first_p2(s) * 10 + determine_last_p2(s))
        .sum();

    return [part_one_output, part_two_output];
}
