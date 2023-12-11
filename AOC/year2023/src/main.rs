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

    match day {
        "1" => days::day1::run(&input),
        "2" => days::day2::run(&input),
        "3" => days::day3::run(&input),
        "4" => days::day4::run(&input),
        "5" => days::day5::run(&input),
        "6" => days::day6::run(&input),
        "7" => days::day7::run(&input),
        "8" => days::day8::run(&input),
        "9" => days::day9::run(&input),
        "10" => days::day10::run(&input),
        "11" => days::day11::run(&input),
        &_ => unimplemented!(),
    }

    let elapsed = now.elapsed();
    println!("Time: {:.2?}", elapsed);
}
