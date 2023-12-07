use std::{cmp::Ordering, collections::HashMap};

#[derive(Copy, Clone, Debug)]
enum HandType {
    FiveKind = 6,
    FourKind = 5,
    FullHouse = 4,
    ThreeKind = 3,
    TwoPair = 2,
    OnePair = 1,
    HighCard = 0,
}

#[derive(Debug)]
struct Hand {
    hand: String,
    bid: u32,
    hand_type: HandType,
}

fn get_hand_type(hand: &str) -> HandType {
    let mut histogram = HashMap::<char, u32>::new();

    hand.chars().for_each(|c| {
        let h = histogram.entry(c).or_insert(0);
        *h += 1;
    });

    let len = histogram.len();

    if len == 1 {
        return HandType::FiveKind;
    } else if len == 2 {
        if histogram.iter().any(|(_key, &val)| val == 4) {
            return HandType::FourKind;
        } else {
            return HandType::FullHouse;
        }
    } else if len == 3 {
        if histogram.iter().any(|(_key, &val)| val == 3) {
            return HandType::ThreeKind;
        } else {
            return HandType::TwoPair;
        }
    } else if len == 4 {
        return HandType::OnePair;
    } else {
        return HandType::HighCard;
    }
}

fn get_hand_type_part_two(hand: &str) -> HandType {
    if !hand.contains('J') {
        return get_hand_type(&hand);
    }

    let mut histogram = HashMap::<char, u32>::new();

    hand.chars().for_each(|c| {
        let h = histogram.entry(c).or_insert(0);
        *h += 1;
    });

    let j_count = *histogram.get(&'J').unwrap();
    histogram.remove(&'J');
    let x = histogram.iter().max_by(|a, b| a.1.cmp(&b.1));
    if x.is_none() {
        return HandType::FiveKind;
    }
    let key_v = x.unwrap();
    histogram.insert(*key_v.0, *key_v.1 + j_count);

    let len = histogram.len();

    if len == 1 {
        return HandType::FiveKind;
    } else if len == 2 {
        if histogram.iter().any(|(_key, &val)| val == 4) {
            return HandType::FourKind;
        } else {
            return HandType::FullHouse;
        }
    } else if len == 3 {
        if histogram.iter().any(|(_key, &val)| val == 3) {
            return HandType::ThreeKind;
        } else {
            return HandType::TwoPair;
        }
    } else if len == 4 {
        return HandType::OnePair;
    } else {
        return HandType::HighCard;
    }
}

pub fn day7(input: &str) -> [u32; 2] {
    let strengths: HashMap<char, u32> = HashMap::from([
        ('A', 14),
        ('K', 13),
        ('Q', 12),
        ('J', 11),
        ('T', 10),
        ('9', 9),
        ('8', 8),
        ('7', 7),
        ('6', 6),
        ('5', 5),
        ('4', 4),
        ('3', 3),
        ('2', 2),
    ]);

    let mut hands = input
        .lines()
        .map(|line| {
            let x = line.split_whitespace().collect::<Vec<_>>();
            Hand {
                hand: x[0].to_string(),
                bid: x[1].parse::<u32>().unwrap_or(0),
                hand_type: get_hand_type(x[0]),
            }
        })
        .collect::<Vec<_>>();

    hands.sort_by(|a, b| {
        let a_val = a.hand_type as u32;
        let b_val = b.hand_type as u32;
        if a_val < b_val {
            Ordering::Less
        } else if a_val > b_val {
            Ordering::Greater
        } else {
            for it in a.hand.chars().zip(b.hand.chars()) {
                let a_strength = strengths[&it.0];
                let b_strength = strengths[&it.1];
                if a_strength == b_strength {
                    continue;
                }
                return a_strength.cmp(&b_strength);
            }
            Ordering::Equal
        }
    });

    let part_one_answer: u32 = hands
        .iter()
        .enumerate()
        .map(|(idx, h)| (idx + 1) as u32 * h.bid)
        .sum();

    let mut hands_part_two = input
        .lines()
        .map(|line| {
            let x = line.split_whitespace().collect::<Vec<_>>();
            Hand {
                hand: x[0].to_string(),
                bid: x[1].parse::<u32>().unwrap_or(0),
                hand_type: get_hand_type_part_two(x[0]),
            }
        })
        .collect::<Vec<_>>();

    hands_part_two.sort_by(|a, b| {
        let a_val = a.hand_type as u32;
        let b_val = b.hand_type as u32;
        if a_val < b_val {
            Ordering::Less
        } else if a_val > b_val {
            Ordering::Greater
        } else {
            for it in a.hand.chars().zip(b.hand.chars()) {
                if it.0 == it.1 {
                    continue;
                }

                if it.0 == 'J' {
                    return Ordering::Less;
                } else if it.1 == 'J' {
                    return Ordering::Greater;
                }

                let a_strength = strengths[&it.0];
                let b_strength = strengths[&it.1];
                return a_strength.cmp(&b_strength);
            }
            Ordering::Equal
        }
    });

    let part_two_answer: u32 = hands_part_two
        .iter()
        .enumerate()
        .map(|(idx, h)| (idx + 1) as u32 * h.bid)
        .sum();

    return [part_one_answer, part_two_answer];
}

#[cfg(test)]
mod test {
    const INPUT: &str = "32T3K 765
T55J5 684
KK677 28
KTJJT 220
QQQJA 483";

    #[test]
    fn day7() {
        let [part1, part2] = super::day7(INPUT);

        assert_eq!(part1, 6440);
        assert_eq!(part2, 5905);
    }
}
