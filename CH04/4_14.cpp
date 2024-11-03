/*
---
E4.14
[14] Read (day-of-the-week,value) pairs from standard input. For example:

Tuesday 23 Friday 56 Tuesday −3 Thursday 99

Collect all the values for each day of the week in a vector<int>. Write out
the values of the seven day-of-the-week vectors. Print out the sum of the
values in each vector. Ignore illegal days of the week, such as Funday,
but accept common synonyms such as Mon and monday. Write out the
number of rejected values.
---

2 Nov 2024
@jmerort
*/

#include <iostream>
#include <vector>

int main()
{
    try
    {
        std::vector <int> mondays {},
                          tuesdays {},
                          wednesdays {},
                          thursdays {},
                          fridays {},
                          saturdays {},
                          sundays {};

        std::vector <std::string> rejects {};

        std::string name {" "};
        
        int val {0},
            sum {0};
        

        std::cout << "Enter some day of the week and value pairs or enter \"C 0\" to continue (e.g.: \"monday 12 Thursday -35 Sunday 12\")\n";
        
        while(true)
        {
            std::cin >> name >> val;
            if (!std::cin)
                throw (std::runtime_error("invalid input."));
            else if (name == "monday" or name == "Monday" or name == "Mon")
                mondays.push_back(val);
            else if (name == "tuesday" or name == "Tuesday" or name == "Tues")
                tuesdays.push_back(val);
            else if (name == "wednesday" or name == "Wednesday" or name == "Wed")
                wednesdays.push_back(val);
            else if (name == "thursday" or name == "Thursday" or name == "Thur")
                thursdays.push_back(val);
            else if (name == "friday" or name == "Friday" or name == "Fri")
                fridays.push_back(val);
            else if (name == "saturday" or name == "Saturday" or name == "Sat")
                saturdays.push_back(val);
            else if (name == "sunday" or name == "Sunday" or name == "Sun")
                sundays.push_back(val);
            else if (name == "C" or name == "c") //to continue 
                break;
            else
                rejects.push_back(name);
        }

        std::cout << "--Sum of the values of each day--\n";
        std::cout << "Mondays: ";
        for (int i = 0; i < mondays.size(); ++i)
            sum += mondays[i];
        std::cout << sum << ".\n";
        sum = 0;

        std::cout << "Tuesdays: ";
        for (int i = 0; i < tuesdays.size(); ++i)
            sum += tuesdays[i];
        std::cout << sum << ".\n";
        sum = 0;

        std::cout << "Wednesdays: ";
        for (int i = 0; i < wednesdays.size(); ++i)
            sum += wednesdays[i];
        std::cout << sum << ".\n";
        sum = 0;

        std::cout << "Thursdays: ";
        for (int i = 0; i < thursdays.size(); ++i)
            sum += thursdays[i];
        std::cout << sum << ".\n";
        sum = 0;

        std::cout << "Fridays: ";
        for (int i = 0; i < fridays.size(); ++i)
            sum += fridays[i];
        std::cout << sum << ".\n";
        sum = 0;

        std::cout << "Saturdays: ";
        for (int i = 0; i < saturdays.size(); ++i)
            sum += saturdays[i];
        std::cout << sum << ".\n";
        sum = 0;

        std::cout << "Sundays: ";
        for (int i = 0; i < sundays.size(); ++i)
            sum += sundays[i];
        std::cout << sum << ".\n";
        sum = 0;
        
        std::cout << "Rejected names: (";
        for (int i = 0; i < rejects.size(); ++i)
            std::cout << rejects[i] << ", ";
        std::cout << ")\n--END--\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
    }
    catch(...)
    {
        std::cerr << "Error: unknown error.\n";
    }
}