use std::env;
use std::fs;

mod days;

fn main() {
    let args: Vec<String> = env::args().collect();
    let day = args[1].as_str();

    let input_file = format!("src/inputs/day{day}");
    let input = fs::read_to_string(input_file).expect("Must have input file");

    println!("AOC Day {}", day);

    let output = match day {
        "1" => days::day1(&input),
        "2" => days::day2(&input),
        "3" => days::day3(&input),
        &_ => unimplemented!(),
    };

    println!("Part_One: {}", output[0]);
    println!("Part_Two: {}", output[1]);
}
