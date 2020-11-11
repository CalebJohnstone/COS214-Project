*************************
Folder contents:
*************************

Report:
- "COS214 Project Report - Byte Me.pdf": The report detailing the design of our project (Task 3).
- "Doxygen" - A directory containing Doxygen documentation for the project.
- "Full Class Diagram.png" - the full UML class diagram for the project. Also included in the report PDF.
- "Individual Class Diagrams" - A directory of individual classes from the full diagram. All classes are also included in the report PDF.
- "Design Patterns" - Extracts from the full class diagram showing each design pattern used. Note that Decorator and Prototype share a diagram. All extracts are also included in the report PDF.

System:
- "makefile" - makefile used to run the program.
- "main.cpp" - the main file that determines the properties of a season and then runs it. See the Editing section below.
- "Car" - a directory containing all source files for the structure of cars
- "Season" - a directory containing all source files for the running of a season
- "Team" - a directory containing all source files for the running of teams

*************************
Running the program
*************************

Compile:
- Navigate to the System folder, and compile the code with "make".
- The makefile compiles and links all source files in all subdirectories and creates a binary called "main".
Run:
- The program can be run with the command "make run".

*************************
Editing
*************************

The project does not need any data files to run. Teams and races can be added/removed by modifying main.cpp. When runSeason() is called, the entire season will run with the teams and races that were entered.

*************************
GitHub commits
*************************
Due to an issue with pushing that occurred near the end of the project, most files do not have a long history with multiple contributors. An accurate history of changes can be seen in the commit log at https://github.com/MichaelJHarvey/bytemeproject/commits/master