pub fn dayn(input: &str) -> [u32; 2] {
    return [0, 0];
}

#[cfg(test)]
mod test {
    const INPUT: &str = "";

    #[test]
    fn dayn() {
        let [part1, part2] = super::dayn(INPUT);

        assert_eq!(part1, 0);
        assert_eq!(part2, 0);
    }
}
