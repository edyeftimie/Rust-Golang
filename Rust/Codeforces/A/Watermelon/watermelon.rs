use std::io;

fn main() {
    let weight = {
        let mut input = String::new();
        io::stdin()
            .read_line(&mut input) // read a line from the standard input
            .unwrap(); // handle the Result
        input
            .trim() // remove the trailing newline
            .parse::<i32>() // parse the string into an integer
            .unwrap() // handle the Result
    };
    if weight % 2 == 0 && weight >= 4 {
        println!("YES");
    } else {
        println!("NO");
    }
}