use std::collections::HashSet;

#[derive(Debug)]
struct Card {
    matches: usize,
    num_instance: u32,
}

pub fn day4(input: &str) -> [u32; 2] {
    let mut cards: Vec<Card> = vec![];

    for line in input.lines() {
        let x = line.split(": ").nth(1);
        if let Some(nums) = x {
            let num_arr = nums.split(" | ").collect::<Vec<&str>>();
            let winning_sets: HashSet<u32> = HashSet::from_iter(
                num_arr[0]
                    .split_whitespace()
                    .filter_map(|s| s.parse::<u32>().ok()),
            );
            let on_hand: HashSet<u32> = HashSet::from_iter(
                num_arr[1]
                    .split_whitespace()
                    .filter_map(|s| s.parse::<u32>().ok()),
            );
            let matches = winning_sets
                .intersection(&on_hand)
                .collect::<Vec<&u32>>()
                .len();
            cards.push(Card {
                matches,
                num_instance: 1,
            })
        }
    }

    let part_one_answer = cards
        .iter()
        .map(|card| {
            if card.matches == 0 {
                0
            } else {
                1 << (card.matches - 1)
            }
        })
        .sum::<u32>();

    for i in 0..cards.len() {
        for j in (i + 1)..(i + cards[i].matches + 1) {
            cards[j].num_instance += cards[i].num_instance;
        }
    }

    let part_two_answer = cards.iter().map(|card| card.num_instance).sum::<u32>();

    return [part_one_answer, part_two_answer];
}

#[cfg(test)]
mod test {
    const INPUT: &str = "Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53
Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19
Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1
Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83
Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36
Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11";

    #[test]
    fn day4() {
        let [part1, part2] = super::day4(INPUT);

        assert_eq!(part1, 13);
        assert_eq!(part2, 30);
    }
}
