use std::fs;

fn read_numbers_from_file(filename: &str) -> Result<Vec<i32>, std::io::Error> {
    let content = fs::read_to_string(filename)?;
    let line = content
        .split_whitespace() // split the line by whitespaces
        .map(|s| s.parse::<i32>()
        .unwrap()) // parse each number from the line
        .collect(); // collect the numbers into a Vec<i32>
    Ok(line) // return the Vec<i32> if everything is ok
}

fn main() {
    let file_path = "cmmdc.in";

    let numbers = match read_numbers_from_file(file_path) {
        Ok(numbers) => numbers,
        Err(err) => {
            eprintln!("Error: {}", err);
            return;
        }
    };

    if numbers.len() != 2 {
        eprintln!("The file should have 2 numbers");
        return;
    }

    let mut a = numbers[0];

    let mut b = numbers[1];

    if a < b {
        a = a + b;
        b = a - b;
        a = a - b;
    }

    while b != 0 {
        let r = a % b;
        a = b;
        b = r;
    }

    if a == 1 {
        a = 0;
    }

    let content = a.to_string();
    match fs::write("cmmdc.out", content) {
        Ok(_) => (),
        Err(err) => eprintln!("Error: {}", err),
    }
}