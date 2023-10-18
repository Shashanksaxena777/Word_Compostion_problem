## Compounded Words Finder

### Overview

This C++ program finds the longest and second longest compounded words from a given list of words. A compounded word is one that can be constructed by concatenating shorter words also found in the same list. The program takes user input to select the input file (either "Input_01.txt" or "Input_02.txt") and ignore **Input_03.txt** file (it was created by me for testing purposes), processes the words, and outputs the results, including the time taken to process the input.

### How to Execute

1. **Prerequisites:**
   - Make sure you have a C++ compiler installed on your system.
   - Ensure the input files ("Input_01.txt" and "Input_02.txt") are available in the same directory as the program.

2. **Compile and Run:**
   - Compile the program using your C++ compiler.

3. **Input:**
   - Select the input file option (1 or 2) when prompted.
   - The program will process the selected input file.

4. **Output:**
   - The program will display the longest and second longest compounded words found in the selected input file.
   - The processing time will also be shown.

### Design and Approach

- The program reads words from the input file and stores them in a vector.
- Words are sorted in descending order of length to optimize search.
- A recursive function is used to check if a word can be formed by concatenating shorter words.
- The program iterates through the sorted words list, finding the longest and second longest compounded words.

### Additional Notes

- The program handles input file errors and invalid user options.
- A clean and modular design allows for easy understanding and modification.
- Ensure input files are correctly formatted with one word per line and no extra spaces.

**Note:** For detailed explanations of the code logic and functions, please refer to the comments within the source code.

---
