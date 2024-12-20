#include "faculty.h"
#include <iomanip>
#include <algorithm>

// Constructor - loads data from Base class and initializes faculty login credentials
faculty::faculty() : Base()
{
    faculty_login["faculty1"] = "123456"; // Faculty login
    faculty_login["faculty2"] = "234567";
    faculty_login["faculty3"] = "345678";
    faculty_login["faculty4"] = "456789";
    faculty1.push_back("math_score");
    faculty2.push_back("history_score");
    faculty3.push_back("physics_score");
    faculty4.push_back("chemistry_score");
    faculty1.push_back("biology_score");
    faculty2.push_back("english_score");
    faculty3.push_back("geography_score");
}


/// @brief login function for faculty class
/// @param email email of the faculty
/// @param password password of the faculty
/// @return success or failure of the login
bool faculty::login(std::string email, std::string password)
{
    // Find the email in the student_login map
    auto it = faculty_login.find(email);
    // Check if email exists and password matches
    if (it != faculty_login.end() && it->second == password)
    {
        std::cout << "Login successful!" << std::endl;
        faculty_username = email;
        return true;
    }
    // If login fails
    std::cout << "Invalid email or password." << std::endl;
    return false;
}



/// @brief get the students list
/// @return vector of students
std::vector<Student> faculty::get_students()
{
    return this->students;
}



/// @brief displays the student data for faculty corresponding to their subject
/// @param stud vector of students
void faculty::view(std::vector<Student> &stud)
{
    std::cout << "Faculty view" << std::endl;
    int size = stud.size();
    int start = 0, end = start + 10;
    std::string choice;
    while (start < size)
    {
        if (end > size)
        {
            end = size;
        }
        this->clearScreen();
        std::vector <std::string> sub;
        if(faculty_username == "faculty1")
            for(auto ele : faculty1)
            {
                sub.push_back(ele);
            }
        else if(faculty_username == "faculty2")
            for(auto ele : faculty2)
            {
                sub.push_back(ele);
            }
        else if(faculty_username == "faculty3")
            for(auto ele : faculty3)
            {
                sub.push_back(ele);
            }
        else if(faculty_username == "faculty4")
            for(auto ele : faculty4)
            {
                sub.push_back(ele);
            }
        std::ostringstream formattedOutput;
        if(sub.size() == 2)
        {
            formattedOutput << std::setw(20) << std::right << sub[0]
                        << std::setw(20) << std::right << sub[1];
        }
        else
        {
            formattedOutput << std::setw(20) << std::right << sub[0];
        }
        std::cout <<
        std::setw(20) << std::right << "First Name" << 
        std::setw(20) << std::right << "Last Name" << 
        std::setw(30) << std::right << "Email" << formattedOutput.str() << 
        std::setw(12) << "Grade" << 
        std::setw(12) << "CGPA" <<std::endl;
        for (int i = start; i < end; i++)
        {
            std::ostringstream score;
            for(int k = 0; k<sub.size(); k++)
            {
                if(sub[k] == "math_score")
                    score << std::setw(20) << std::right << stud[i].math_score ;
                else if(sub[k] == "history_score")
                    score << std::setw(20) << std::right << stud[i].history_score ;
                else if(sub[k] == "physics_score")
                    score << std::setw(20) << std::right << stud[i].physics_score ;
                else if(sub[k] == "chemistry_score")
                    score << std::setw(20) << std::right << stud[i].chemistry_score ;
                else if(sub[k] == "biology_score")
                    score << std::setw(20) << std::right << stud[i].biology_score ;
                else if(sub[k] == "english_score")
                    score << std::setw(20) << std::right << stud[i].english_score ;
                else if(sub[k] == "geography_score")
                    score << std::setw(20) << std::right << stud[i].geography_score ;
            }
            std::cout <<
            std::setw(20) << std::right << stud[i].first_name.substr(0, 20) << 
            std::setw(20) << std::right << stud[i].last_name.substr(0, 20) << 
            std::setw(30) << std::right << stud[i].email.substr(0, 30) << 
            score.str() << 
            std::setw(12) << std::right << stud[i].Grade.substr(0, 20) << 
            std::setw(12) <<std:: right << stud[i].CGPA << 
            std::endl;
        }

         int current_page = (start / 10) + 1;
        int total_pages = (size + 9) / 10;
        std::cout << "Page " << current_page << " of " << total_pages << std::endl;
        std::cout << "Press 'n' for next page, 'p' for previous page, 'b' to quit, or enter page number to jump: ";
        std::cin >> choice;

        if (choice == "n")
        {
            if (end < size)
            {
                start += 10;
                end += 10;
            }
            else
            {
                std::cout << "You are on the last page." << std::endl;
            }
        }
        else if (choice == "p")
        {
            if (start >= 10)
            {
                start -= 10;
                end -= 10;
            }
            else
            {
                std::cout << "You are on the first page." << std::endl;
            }
        }
        else if (choice == "b")
        {
            break;
        }
        else
        {
            try
            {
                int page = std::stoi(choice);
                if (page >= 1 && page <= total_pages)
                {
                    start = (page - 1) * 10;
                    end = start + 10;
                    if (end > size)
                        end = size;
                }
                else
                {
                    std::cout << "Invalid page number." << std::endl;
                }
            }
            catch (const std::invalid_argument &e)
            {
                std::cout << "Invalid choice." << std::endl;
            }
        }
    }
}

/// @brief sorts the students based on the criteria
/// @param by_grade whether to sort by grade
/// @param by_last_name whether to sort by last name
/// @param by_cgpa whether to sort by CGPA
/// @param students vector of students
void faculty ::sort_student(bool by_grade, bool by_last_name, bool by_cgpa, std::vector<Student> &students)
{
    sort(students.begin(), students.end(), [=](const Student a, const Student b) {
        if (by_grade && a.Grade != b.Grade) {
            // Priority order: freshman < junior < senior
            auto gradeRank = [](const std::string& grade) {
                if (grade == "Freshman") return 1;
                if(grade == "Sophomore") return 2;
                if (grade == "Junior") return 3;
                if (grade == "Senior") return 4;
                return 0;
            };
            return gradeRank(a.Grade) < gradeRank(b.Grade);
        }
        if (by_cgpa && a.CGPA != b.CGPA) {
            return a.CGPA < b.CGPA; // Priority order: A < B < C < D
        }
        if (by_last_name) {
            return a.last_name < b.last_name; // Alphabetical order
        }
        return false; // Equal elements
    });
}


/// @brief search the student based on the name
/// @param name full name of the student
/// @return vector of students matching the name
std::vector<Student> faculty::search_student(const std::string& name)
{
   std::string first_name, last_name; 
    std::vector<Student> searches; // Store search results
    std::stringstream ss(name);
    ss >> first_name >> last_name; // Extract first and last name from name
    
    // Search for best match first and add to searches
    for (auto student : students)
    {
        if (student.first_name == first_name && student.last_name == last_name)
        {
            searches.push_back(student);
        }
    }

    
    // Search for partial match and add to searches
    for (auto student : students)
    {
        if ((student.first_name == first_name || student.last_name == last_name) && 
        (student.first_name != first_name || student.last_name != last_name))
        {
            searches.push_back(student);
        }
    }

    if (searches.empty())
    {
        std::cout << "No student found with the name.\nNote: Searches are case sensitive" << name << std::endl;
    }
    return searches;
}

/// @brief filter students based on grade and CGPA
/// @param students vector of students
/// @param grade grade to filter by
/// @param cgpa cgpa to filter by
/// @return vector of students matching the filter criteria
std::vector<Student> faculty::filter_student(std::vector<Student> students, std::string grade ,  char cgpa)
{
    std::vector<Student> filtered_students;
    
    // exact matches
    for (auto student : students)
    {


        if((student.Grade == grade) && 
           (student.CGPA == cgpa))
           {
                filtered_students.push_back(student);
           }
    }
    if (filtered_students.empty())
    {
        std::cout << "No student found with the filter criteria" << std::endl;
    }
    return filtered_students;
}
