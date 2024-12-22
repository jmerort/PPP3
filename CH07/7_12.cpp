/*
---
E7.12
[12] Improve print_until_s() from §7.4.2. Test it. What makes a good set of test
cases? Give reasons. Then, write a print_until_ss() that prints until it sees
a second occurrence of its quit argument.
---

The given function seems to work properly for normal inputs. I improved it by passing
its parameters as constant references, to avoid copying unnecesary variables.

Dec 2024
@jmerort
*/

#include <iostream>
#include <vector>

using std::vector,
      std::string,
      std::cout;


void print_until_s(const vector<string>& v, const string& quit)
// print until the string called "quit" is found
{
    for (string s : v) 
    {
        if (s==quit) return;
        cout << s << '\n';
    }
}



void print_until_ss(const vector<string>& v, const string& quit)
// print until the second instance of the string called "quit" is found
{
    bool first = false; //to check for the first instance of the word
    for (string s : v) 
    {
        if(s==quit && first) return;
        if (s==quit) first = true;
        cout << s << '\n';
    }
}



int main()
{
    vector <string> test_1 {"Me", "topo", "con", "el", "topo", "que", "se", "come", "la", "hierba"},
                    test_2 {""};

    //tests of print_until_s
    cout << "--PRINT_UNTIL_S TESTS--\n"
         << "-Regular test:\n";
    print_until_s(test_1, "come");

    cout << "-First word test:\n";
    print_until_s(test_1, "Me");

    cout << "-Empty quit-word test:\n";
    print_until_s(test_1, "");

    cout << "-Empty sentence test:\n";
    print_until_s(test_2,"");


    //tests of print_until_s
    cout << "--PRINT_UNTIL_SS TESTS--\n"
         << "-Regular test:\n";
    print_until_ss(test_1, "topo");

    cout << "-Non repeated word test:\n";
    print_until_ss(test_1, "Me");

    cout << "-Empty quit-word test:\n";
    print_until_ss(test_1, "");

    cout << "-Empty sentence test:\n";
    print_until_ss(test_2,"");
    
    return 0;
}