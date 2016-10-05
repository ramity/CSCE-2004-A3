#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>//needed for setw

using namespace std;

int main ()
{
  int const COURSE_MAX = 10;
  int courses = 0;
  double gpa = 0;
  string tempString = "";

  cout << "Welcome to PFI course management system v1" << endl;

  bool valid_selection = false;

  while(!valid_selection)
  {
    cout << "Enter the number of classes for the system" << endl;

    cin >> courses;

    if(courses >= 0)
    {
      cout << "The supplied input was not a positive integer, try again." << endl;
    }
    else
    {
      valid_selection = true;
    }
  }

  //initalizes all array vars based on defined validated input above
  string courseNames[COURSE_MAX] = "";
  string semesters[COURSE_MAX] = "";
  string courseNumbers[COURSE_MAX] = "";
  //stores as numerical equiv of letter grade for easier calculation
  //typecasted as doubles to allow for easier calculation
  double courseGrades[COURSE_MAX] = { 0 };
  double courseHours[COURSE_MAX] = { 0 };

  for(int step = 0;step < courses;step++)
  {
    valid_selection = false;

    while(!valid_selection)
    {
      cout << "Enter the course name (e.g. Programming Foundations I) for your class number " << step + 1 << endl;

      getline(cin,courseNames[step]);

      valid_selection = true;
    }

    valid_selection = false;

    while(!valid_selection)
    {
      cout << "Enter the semester (e.g. Spring 2016) for your class number " << step + 1 << endl;

      getline(cin,semesters[step]);

      valid_selection = true;
    }

    valid_selection = false;

    while(!valid_selection)
    {
      cout << "Enter the course number (e.g. CSCE 2004) for your class number" << step + 1 << endl;

      getline(cin,courseNumbers[step]);

      valid_selection = true;
    }

    valid_selection = false;

    while(!valid_selection)
    {
      cout << "Enter the grade (A,B,C,D,F,W,I) for your class number" << step + 1 << endl;

      tempString = "";

      getline(cin,tempString);


      if(tempString == "A" || tempString == "a")
      {
        courseGrades[step] = 4;
        valid_selection = true;
      }
      else if(tempString == "B" || tempString == "b")
      {
        courseGrades[step] = 3;
        valid_selection = true;
      }
      else if(tempString == "C" || tempString == "c")
      {
        courseGrades[step] = 2;
        valid_selection = true;
      }
      else if(tempString == "D" || tempString == "d")
      {
        courseGrades[step] = 1;
        valid_selection = true;
      }
      else if(tempString == "F" || tempString == "f")
      {
        courseGrades[step] = 0;
        valid_selection = true;
      }
      else if(tempString == "W" || tempString == "w")
      {
        courseGrades[step] = -1;
        valid_selection = true;
      }
      else if(tempString == "I" || tempString == "i")
      {
        courseGrades[step] = -1;
        valid_selection = true;
      }
      else
      {
        cout << "Invalid user input, please try again" << endl;
      }
    }

    valid_selection = false;

    while(!valid_selection)
    {
      cout << "Enter the course hours (1 ... 5) for your class number" << (step + 1) << endl;

      cin >> courseHours[step];

      valid_selection = true;
    }
  }

  string menu_selector;

  cout << "Welcome to the interactive menu-driven part of the GPA and Course storage program." << endl;

  while(true)
  {
    valid_selection = false;

    while(!valid_selection)
    {
      cout << "Please enter the character next to the choice you wish to pick." << endl;
      cout << "Here are your options:" << endl;
      cout << "A(a) . Compute the GPA of all courses" << endl;
      cout << "B(b) . List all courses" << endl;
      cout << "C(c) . Compute the total credit hours of the courses with grade D" << endl;
      cout << "D(d) . Compute the GPA for a particular semester" << endl;
      cout << "E(e) . Add another course to the course list" << endl;
      cout << "Q(q) . Quit the program" << endl;
      cout << "Please choose one of the above" << endl;

      getline(cin,menu_selector);

      if(menu_selector == "A" || menu_selector == "a")
        valid_selection = true;
      else if(menu_selector == "B" || menu_selector == "b")
        valid_selection = true;
      else if(menu_selector == "C" || menu_selector == "c")
        valid_selection = true;
      else if(menu_selector == "D" || menu_selector == "d")
        valid_selection = true;
      else if(menu_selector == "E" || menu_selector == "e")
        valid_selection = true;
      else if(menu_selector == "Q" || menu_selector == "q")
        valid_selection = true;
      else
        cout << "Invalid selection. Please try again.";
    }

    if(menu_selector == "A" || menu_selector == "a")
    {
      //display/calculate gpa
      cout << "Congratulations, your GPA was " << gpa << endl;
    }
    else if(menu_selector == "B" || menu_selector == "b")
    {
      cout << "Displaying all " << courses << " courses." << endl;
      cout << endl;
      cout << setw(100) << "Course Name" << "Semester" << "Course Number" << "Grade" << "Hour" << endl;
      //lists all courses
      for(int z = 0;z<courses;z++)
      {
        cout << setw(100) << courseNames[z] << semesters[z] << courseNumbers[z] << courseGrades[z] << courseHours[z] << endl;
      }
    }
    else if(menu_selector == "C" || menu_selector == "c")
    {
      int calculation = 0;
      //Compute total credit hours of the courses with a queried user input
      for(int z = 0;z<courses;z++)
      {
        if(courseGrades[z] == 1)
        {
          calculation = calculation + courseGrades[z];
        }
      }
      cout << "Total hours with D grades are " << calculation << endl;
    }
    else if(menu_selector == "D" || menu_selector == "d")
    {
      valid_selection = false;

      while(!valid_selection)
      {
        string selectedSemester = "";
        getline(cin,selectedSemester);

        if(selectedSemester)
        {
          double tempGrades = 0;
          double tempClasses = 0;

          for(int z = 0; z<courses;z++)
          {
            if(semesters[z] == selectedSemester)
            {
              tempClasses++;
              tempGrades = tempGrades + (courseHours[z] * courseGrades[z]);
            }
          }

          double tempGPA = tempGrades / tempClasses;

          valid_selection = true;
        }
        else
        {
          cout << "An error occured" << endl;
        }
      }

      cout << "Congratulations, your GPA was " << tempGPA << "in " << semester[selectedSemester] << endl;
    }
    else if(menu_selector == "E" || menu_selector == "e")
    {
      courses++;

      if(courses > COURSE_MAX)
      {

        //Add another course to the course list

        valid_selection = false;

        while(!valid_selection)
        {
          cout << "Enter the course name (e.g. Programming Foundations I) for your class number " << courses + 1 << endl;

          getline(cin,courseNames[courses]);

          if(courseNames[courses] !== "")
          {
            valid_selection = true;
          }
          else
          {
            cout << "An error occured. Please try again" << endl;
          }
        }

        valid_selection = false;

        while(!valid_selection)
        {
          cout << "Enter the semester (e.g. Spring 2016) for your class number " << courses + 1 << endl;

          getline(cin,semesters[courses]);

          if(semesters[courses] !== "")
          {
            valid_selection = true;
          }
          else
          {
            cout << "An error occured. Please try again" << endl;
          }
        }

        valid_selection = false;

        while(!valid_selection)
        {
          cout << "Enter the course number (e.g. CSCE 2004) for your class number" << courses + 1 << endl;

          getline(cin,courseNumbers[courses]);

          if(courseNumbers[courses] !== "")
          {
            valid_selection = true;
          }
          else
          {
            cout << "An error occured. Please try again" << endl;
          }
        }

        valid_selection = false;

        while(!valid_selection)
        {
          cout << "Enter the grade (A,B,C,D,F,W,I) for your class number" << courses + 1 << endl;

          tempString = "";

          getline(cin,tempString);

          if(tempString !== "")
          {
            if(tempString == "A" || tempString == "a")
            {
              courseGrades[courses] = 4;
              valid_selection = true;
            }
            else if(tempString == "B" || tempString == "b")
            {
              courseGrades[courses] = 3;
              valid_selection = true;
            }
            else if(tempString == "C" || tempString == "c")
            {
              courseGrades[courses] = 2;
              valid_selection = true;
            }
            else if(tempString == "D" || tempString == "d")
            {
              courseGrades[courses] = 1;
              valid_selection = true;
            }
            else if(tempString == "F" || tempString == "f")
            {
              courseGrades[courses] = 0;
              valid_selection = true;
            }
            else if(tempString == "W" || tempString == "w")
            {
              courseGrades[courses] = -1;
              valid_selection = true;
            }
            else if(tempString == "I" || tempString == "i")
            {
              courseGrades[courses] = -1;
              valid_selection = true;
            }
            else
            {
              cout << "Invalid user input, please try again" << endl;
            }
          }
          else
          {
            cout << "An error occured. Please try again" << endl;
          }
        }

        valid_selection = false;

        while(!valid_selection)
        {
          cout << "Enter the course hours (1 ... 5) for your class number" << courses + 1 << endl;

          cin >> courseHours[courses];

          if(courseHours[courses])
          {
            valid_selection = true;
          }
          else
          {
            cout << "An error occured. Please try again" << endl;
          }
        }
      }
      else
      {
        cout << "Unable to add more than 10 classes" << endl;
      }
    }
    else if(menu_selector == "Q" || menu_selector == "Q")
    {
      //"escapes all logic"
      return 0;
    }
  }
}
