use std::env;

mod days;

fn main() {
    let args: Vec<String> = env::args().collect();
    let day = &args[1];
    match day.as_str() {
        "1" => days::day1(),
        "2" => days::day2(),
        &_ => unimplemented!(),
    }
}
