/* 
UNIT 2 - DRILL

[1] Write a program that produces a simple form letter based on user
input. Begin by typing the code from §2.1 prompting a user to enter
his or her first name and writing “Hello, first_name” where first_name
is the name entered by the user. Then modify your code as follows:
change the prompt to “Enter the name of the person you want to write
to” and change the output to “Dear first_name,”. Don’t forget the
comma.
[2] Add an introductory line or two, like “How are you? I am fine. I miss
you.” Be sure to indent the first line. Add a few more lines of your
choosing – it’s your letter.
[3] Now prompt the user for the name of another friend and store it in
friend_name. Add a line to your letter: “Have you seen friend_name
lately?”
[4] Prompt the user to enter the age of the recipient and assign it to an int
variable age. Have your program write “I hear you just had a birthday
and you are age years old.” If age is 0 or less or 110 or more, call
simple_error("you’re kidding!") using simple_error() from PPP_support.
[5] Add this to your letter:
If your friend is under 12, write “Next year you will be age+1.” If
your friend is 17, write “Next year you will be able to vote.” If
your friend is over 70, write “Are you retired?”
Check your program to make sure it responds appropriately to each
kind of value.
[6] Add “Yours sincerely,” followed by two blank lines for a signature,
followed by your name.

28-Oct-2024
@jmerort
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include<cmath>


int main()
{
    std::string first_name = " ",
                friend_name = " ";
    int age = -1;

    std::cout << "Enter your name: \n";
    std::cin >> first_name;
    std::cout << "Input your friend's name: \n";
    std::cin >> friend_name;
    std::cout <<"Enter the age of the recipient: \n";
    std::cin >> age;

    if(age < 1 or age >= 110)
    {
        perror("You're kidding! :-)\n");
        return 0;
    }

    std::cout << "  Dear " << first_name << ",\n"
              << "I recieved your text yesteday, and I wanted to tell you that I'm happy to hear from you. ¿How is everything going?\n"
              << "By the way, have you seen " <<  friend_name << " lately?\n";

    std::cout << "I see today's your birthday, and you're now " << age << " years old. Congrats!\n";
    if(age < 12)
    {
        std::cout << "Next year you'll be " << age + 1 << " years old.\n";
    }
    else if (age == 17)
    {
        std::cout << "Next year, you'll be allowed to vote.\n";
    }
    else if (age >= 70)
    {
        std::cout << "I hope you're enjoying retirement.\n";
    }

    std::cout << "Sincerely, \n\n@jmerort \n";

    return 0;
}