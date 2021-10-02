// Longest Substring Without Repeating Characters
// Kshitij Chitnis (m0rphtail)

// Approach:
// The l and r are the left and right indices of the window, respectively. 
// We start with l and r at 0, representing a window one item wide and then move r to the right item by item. 
// We check the set to see if we’ve seen the item before and if so we get the size of the window (r - l) and update longest if applicable. 
// When we find an item we’ve already seen we remove the character at position l and move it the right, continuing until we remove the item at r from the set. 
// We then start again.

// Time complexity: O(n)
// Space complexity: O(n)

// Imports
use std::cmp::max;
use std::collections::HashSet;

// Solution function
fn length_of_longest_substring(s: String) -> i32 {
    let chars: Vec<char> = s.chars().collect();
    if chars.len() < 2 {
        return chars.len() as i32;
    }

    let mut l: usize = 0;
    let mut r: usize = 0;
    let mut longest: usize = 0;

    let mut seen: HashSet<char> = HashSet::with_capacity(26);

    while r < chars.len() {
        if seen.contains(&chars[r]) {
            seen.remove(&chars[l]);
            l += 1;
        } else {
            longest = max(longest, r - l);
            seen.insert(chars[r]);
            r += 1;
        }
    }
    (longest + 1) as i32
}

//Driver code
fn main() {
    println!("{}", length_of_longest_substring(String::from("abcabcabc"))); //Expected: 3
    println!("{}", length_of_longest_substring(String::from("bbbbb"))); //Expected: 1
    println!("{}", length_of_longest_substring(String::from("pwwkew"))); //Expected: 3
}
