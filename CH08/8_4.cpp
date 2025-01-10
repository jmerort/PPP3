/*
---
E8.4
[4] Do the previous exercise again but implement Name_pairs using a
Name_pair class.
---

This implementation is harder to write and understand than the previous one,
as well as being longer. I think it's just a worse expression of the idea of
the program.

Jan 2024
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


class Name_pair
{
	public:
		Name_pair(){read();}
		Name_pair(string n, double a):name{n},age{a}{}

		
		void read();
		friend std::ostream& operator << (std::ostream&, Name_pair); //operator to print name and age pairs
		friend void sort_pairs (vector <Name_pair>&);

		
	private:
		string name;
		double age;
		
		void read_name();
		void read_age();
};



void Name_pair::read()
{
	read_name();
	read_age();
}



void Name_pair::read_name()
//give a name pair object its name
{	
	cin >> name;	
}



void Name_pair::read_age()
//fill the ages vector member with as many ages as names are currently
{
	cin >> age;
}



std::ostream& operator << (std::ostream& os, Name_pair n)
//print all name and value pairs
{	
	os << n.name << " - " << n.age;
	return os;
}



//----------------------------------------------------------------------



vector <Name_pair> names_ages; //global vector to hold the name pairs



vector <string> read_names ()
{
	//return vector filled with names
	vector <string> names;
	string n;
	
	cout << "Enter names separated by spaces and ended by '|' (e.g. \"John Luke Mark |\"):\n";
	while(cin >> n)
	{
		if (n == "|") break;
		names.push_back(n);
	}
	
	return names;
}



vector <double> read_ages (int siz)
{
	//fill age vector
	vector <double> ages;
	double a{0};
	
	cout << "Enter the ages for each name (e.g.: \"20 45 51\"):\n";
	for (int i{0}; i < siz; i++)
	{
		cin >> a;
		if (!cin) throw (std::runtime_error("Enter a valid name.\n"));
		ages.push_back(a);
	}
	
	return ages;
}



void read_pairs (vector <Name_pair>& v)
{
	vector <string> names{read_names()}; //name and age vectors to be filled
	vector <double> ages{read_ages(names.size())};
	
	//fill Name_pair vector
	int siz {names.size()};
	for (int i{0}; i < siz; i++)
		v.push_back(Name_pair{names[i], ages[i]});
}



void print_pairs (const vector <Name_pair>& v)
{
	int siz{v.size()};
	
	for (int i{0}; i < siz; i++)
		cout << v[i] << "\n";
}



void sort_pairs (vector <Name_pair>& v)
{
	//sort Name_pair vector alphanumerically based on the names
	
	vector <Name_pair> v_sort; //vector in which to insert the sorted elements
	vector <string> names_cp; //vector in which to copy all the names
	
	//copy names into vector
	int siz{v.size()};
	for (int i{0}; i < siz; i++)
		names_cp.push_back(v[i].name);
		
	//sort names vector
	std::sort (names_cp.begin(), names_cp.end());
	
	//fill sort vector with the elements of v in order
	for (int i {0}; i < siz; i++)
    {
        for (int u {0}; u < siz; u++)
        {
            if(names_cp[i] == v[u].name)
				v_sort.push_back(v[u]); 
        }
    }
    
    v = v_sort;
}


int main()
{
	try 
	{	
		read_pairs(names_ages);
		print_pairs(names_ages);
		
		sort_pairs(names_ages);
		print_pairs(names_ages);
		
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
