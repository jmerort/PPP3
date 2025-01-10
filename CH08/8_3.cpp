/*
---
E8.3
[3] Replace Name_pair::print() with a (global) operator << and define == and !=
for Name_pairs.
---

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
		
		void sort(); //sort alphabetically the name pairs and their ages
		friend std::ostream& operator << (std::ostream&, Name_pairs); //operator to print name and age pairs
		
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



std::ostream& operator << (std::ostream& os, Name_pairs n)
//print all name and value pairs
{	
	int siz {n.names.size()};
	for (int i{0}; i < siz; i++)
		os << n.names[i] << " - " << n.ages[i] << " years\n";
	
	return os;
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
		cout << "-NAMES AND AGES-\n" << list;
		
		list.sort();
		cout << "-SORTED NAMES AND AGES-\n" << list;
		
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
