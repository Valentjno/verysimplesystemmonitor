#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "split.cpp"

using namespace std;

class Ram{

public:	
	int get_total(){
		vector<string> v;
		string s;
		stringstream ss;
		int ret;
		ifstream file("/proc/meminfo");
		if(file.is_open()){
			getline(file,s);
			v = split(s, ' ');
			s = v.at(v.size() - 2);
			istringstream(s) >> ret;
		}
		file.close();
		return ret;
	}

	int get_used(){
		vector<string> v;
		string s;
		stringstream ss;
		int ret;
		ifstream file("/proc/meminfo");
		if(file.is_open()){
			for(int i = 0; i < 2; i++)
				getline(file,s);
			getline(file,s);
			v = split(s, ' ');
			s = v.at(v.size() - 2);
			istringstream(s) >> ret;
		}
		file.close();
		return ret;

	}


	int get_used_percent(){
		return (get_used()/get_total())*100;
	}

	

	Ram(){}
};




