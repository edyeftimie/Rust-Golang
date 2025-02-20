//https://www.infoarena.ro/problema/adunare
use std::fs;
use std::io::Error;

/// Read the content of a file and return a Vec<String> where each element is a line from the file
///
/// # Arguments
/// * `filename` - A string slice that holds the name of the file
///
/// # Returns
/// * A Result that holds a Vec<String> if everything is ok, or an std::io::Error if something went wrong
fn read_lines_from_file(filename: &str) -> Result<Vec<String>, std::io::Error> {
    let content = fs::read_to_string(filename)?;
    let lines: Vec<String> = content
        .lines() // split the content by lines
        .map(|s| s.to_string()) // convert each &str to String
        .collect(); // collect the strings into a Vec<String>
    Ok(lines) // return the Vec<String> if everything is ok
}

/// Transform a string into an integer
///
/// # Arguments
/// * `line` - A string slice that holds the number
///
/// # Returns
/// * An integer that is the number from the string
fn tranform_string_in_int(line: &str) -> Result<i32, std::num::ParseIntError> {
    //u32 - unsigned 32-bit integer
    //i32 - signed 32-bit integer
    return line
        .trim() // remove leading and trailing whitespaces
        .parse() // parse the string into a number
}

/// Main function
/// 
/// Read the content of a file, transform the strings into integers, add them and write the result in a file
fn main() -> Result<(), Box<dyn std::error::Error>> {
    let file_path = "adunare.in";

    let lines = match read_lines_from_file(file_path) {
        Ok(lines) => lines,
        Err(err) => {
            eprintln!("Error: {}", err);
            return Err(Box::new(err)); // return an error
        }
    };

    if lines.len() != 2 {
        eprintln!("The file should have 2 lines");
        let err: Error = Error::new(std::io::ErrorKind::InvalidData, "The file should have 2 lines");
        return Err(Box::new(err));
    }

    let a = match tranform_string_in_int(&lines[0]) {
        Ok(a) => a,
        Err(err) => {
            eprintln!("Error: {}", err);
            return Err(Box::new(err));
        }
    };

    let b = match tranform_string_in_int(&lines[1]) {
        Ok(b) => b,
        Err(err) => {
            eprintln!("Error: {}", err);
            return Err(Box::new(err));
        }
    };

    let result = a + b;

    if let Err(e) = fs::write("adunare.out", result.to_string()) {
        eprintln!("Error writing to file: {}", e);
        return Err(Box::new(e)); // Return error if writing fails
    }

    Ok(()) // Return Ok if everything is ok
}