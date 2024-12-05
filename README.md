# EE-552-Project-2

[Student Database](https://www.kaggle.com/datasets/markmedhat/student-scores)

### Todo

[ ] Add NB gender

[ ] Add Age

[ ] Add Grade (Freshman/ Sophmore/ Junior Senior)

[ ]  CGPA (calculate through subject scores)

[ ] College Application

### Program Structure

- Create Base Abstract Class 

    - Will have Struct with each of the column as attributes.
    - protected vector to store all structs
    - Function to load data from csv and store in vector (probably should be done in constructor)
    - abstract view function (overriden by inheriting classes as required)
    - a search function takes in student name (first, last) and returns the matching queries

- Create Admin Class
    - Inherits Base Class
    - Approprriate Definitions for inherited funcs
    - a login function that takes in username and password
    - a ordered \<string,string\> map stores username as key and pwd as value
    - view function will show all the columns here, appropriate looping to show only 10 rows at a time unless prompted.

- Create Faculty Class
    - Inherits Base Class
    - Approprriate Definitions for inherited funcs
    - a login function that takes in username and password
    - will have a subject attribute that stores the faculties subject/s
    - a ordered \<string,string\> map stores username as key and pwd as value
    - view function will show students name, email, and grade in their subject and CGPA
    - view function can be sorted either by name or score.

- Create Student Class
    - Inherits Base Class
    - Approprriate Definitions for inherited funcs
    - login function ??
    - view function, shows only student names, Grade and email.

- A separate class for data analysis

    There is no easy way to plot withing terminal lets create a signal m x n subplots and display single popup

    - will show pie chart for career aspiration
    - a joint bar graph of grade vs age
    - pie chart for part time status
    - pie chart gender
    - Add any other visulaization u fell important


- Main File

    - Menu Drive
    - on launch should welcome and prompt for user type input and visualizations 
    - depending on user input if prompted for view create object pointer and provide with options
        - complete display
        - search
        - back
    - if selected visualization display the plot and loop back the menu

### Concepts Covered
1. Class (Abstract/Inheritance)
2. File Handling
3. Vectors
4. Ordered Map
5. pointers
6. Structs
7. loops
