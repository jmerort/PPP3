/*
---
E8.2
[2] Design and implement a Name_pairs class holding (name,age) pairs
where name is a string and age is a double. Represent that as a
vector<string> (called name) and a vector<double> (called age) member.
Provide an input operation read_names() that reads a series of names.
Provide a read_ages() operation that prompts the user for an age for each
name. Provide a print() operation that prints out the (name[i],age[i]) pairs
(one per line) in the order determined by the name vector. Provide a
sort() operation that sorts the name vector in alphabetical order and
reorganizes the age vector to match. Implement all “operations” as
member functions. Test the class (of course: test early and often).
---

I decided to prevent the user from changing names and ages separately, 
as I feel like that could cause a lot of problems. Separately changing
the ages might be useful, though. One could spend all day adding more 
stuff to these small programs, but you gotta end at some point...

I reused the sort_pairs() function that I wrote in excercise 7.7.

Jan 2025
@jmerort
*/


#include <iostream>
#include <vector>
#include <algorithm>

using std::vector,
	  std::string,
	  std::cout,
	  std::cin;



//----------------------------------------------------------------------


	  
class Name_pairs
//class to hold a vector of names and another of their corresponding ages
{
	public:
		Name_pairs();
		void read(); //read new name and age pairs into an object
		
		void print(); //print name and age pairs
		void sort(); //sort alphabetically the name pairs and their ages
				
	private:
		vector<string> names;
		vector<double> ages;
		
		void read_names();
		void read_ages();
};



Name_pairs::Name_pairs()
{
	read();
}



void Name_pairs::read()
{
	read_names();
	read_ages();
}


void Name_pairs::read_names()
//fill the names vector member with names entered by keyboard
{
	names.clear(); //reset the object state
	ages.clear(); //to avoid mismatches, we reset age as well
	
	string n;
	cout << "Enter names separated by spaces and ended by '|' (e.g. \"John Luke Mark |\"):\n";
	while(cin >> n)
	{
		if (n == "|") break;
		names.push_back(n);
	}
}



void Name_pairs::read_ages()
//fill the ages vector member with as many ages as names are currently
{
	int siz{names.size()};
	double a{0};
		
	cout << "Enter the ages for each name (e.g.: \"20 45 51\"):\n";
	for (int i{0}; i < siz; i++)
	{
		cin >> a;
		if (!cin) throw (std::runtime_error("Enter a valid name.\n"));
		ages.push_back(a);
	}
}



void Name_pairs::print()
{
	int siz {names.size()};
	for (int i{0}; i < siz; i++)
		cout << names[i] << " - " << ages[i] << " years\n";
}



void Name_pairs::sort()
{	
    // sort names vector in alphabetical order and sort the corresponding ages too   
    vector <string> names_cp{names}; //copy vectors that won't be changed, to be used during age sorting
    vector <double> ages_cp{ages};
	int siz{ages.size()};
	
    std::sort(names.begin(), names.end()); //sort the names

    //Age sorting algorithm: for every name in ages_cp (not sorted), check if it equals any name in ages (sorted) 
    //and, if so, change the corresponding age in ages (to be sorted)
    for (int i {0}; i < siz; i++)
    {
        for (int u {0}; u < siz; u++)
        {
            if(names_cp[i]== names[u])
                ages[u] = ages_cp[i]; 
        }
    }
}



//----------------------------------------------------------------------



int main()
{
	try 
	{	
		Name_pairs list;
		cout << "-NAMES AND AGES-\n";
		list.print();
		
		list.sort();
		cout << "-SORTED NAMES AND AGES-\n";
		list.print();
		
		return 0;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what();
		return 1;
	}
	catch(...)
	{
		std::cerr << "Unknown error.\n";
		return 2;
	}
}
