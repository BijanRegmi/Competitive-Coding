use std::env;
use std::fs;

mod days;

fn main() {
    let args: Vec<String> = env::args().collect();
    let day = args[1].as_str();

    let input_file = format!("src/inputs/day{day}");
    let input = fs::read_to_string(input_file).expect("Must have input file");

    println!("AOC Day {}", day);

    use std::time::Instant;
    let now = Instant::now();

    let output_u32 = match day {
        "1" => days::day1(&input),
        "2" => days::day2(&input),
        "3" => days::day3(&input),
        "4" => days::day4(&input),
        "6" => days::day6(&input),
        &_ => [0, 0],
    };

    if output_u32[0] != 0 && output_u32[1] != 0 {
        println!("Part_One: {}", output_u32[0]);
        println!("Part_Two: {}", output_u32[1]);
        let elapsed = now.elapsed();
        println!("Time: {:.2?}", elapsed);
    }

    let output_u64 = match day {
        "5" => days::day5(&input),
        &_ => [0, 0],
    };

    if output_u64[0] != 0 && output_u64[1] != 0 {
        println!("Part_One: {}", output_u64[0]);
        println!("Part_Two: {}", output_u64[1]);
        let elapsed = now.elapsed();
        println!("Time: {:.2?}", elapsed);
    }
}
