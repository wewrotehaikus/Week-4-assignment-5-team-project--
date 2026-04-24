## How to Compile and Run

### Requirements
- A C++ compiler that supports C++11 or later (g++ recommended)
- Terminal / Command Prompt

### Compile
From the directory containing all source files, run:

    g++ -o final_project main.cpp BinaryIO.cpp Analyzers.cpp SortSearch.cpp

### Run
    ./final_project (on Mac and Linux)
    Note: If you are using Windows, run the program by typing `final_project` or `final_project.exe` without the `./` prefix.*

### Expected Output
The program will generate a binary file called data.bin in the same
directory, then print four lines of analysis results to the console.
Results will vary each run since the data is randomly generated.
