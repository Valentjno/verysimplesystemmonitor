#include <iostream>
#include <fstream.h>
#include <vector>
using namespace std;
#include "split
class Cpu{
private:
    int state;
    int work_jiffies_0; 
    int work_jiffies_1;
    int total_jiffies_0;
    int total_jiffies_1;
public:
    Cpu(int state){
        this->state=state;
    work_jiffies_0; 
    work_jiffies_1;
    total_jiffies_0;
    total_jiffies_1;
    }
    
    int get_used(){
       ifstream openfile("/proc/stat");
       vector<string> v;       
       string cpu="cpu";
       cpu.concat(state);
        while(!openfile.eof()){
           stringstream s;
           int n;
           v=split(Openfile.getline()," ");          
           if(v.at(0)==cpu){
                    work_jiffies_0=work_jiffies_1;
                    total_jiffies_0=total_jiffies_1;
                    for(int i=1;i<=3;i++){
                        s.str(v.at(i));
                        s>>n;
                        work_jiffies_1+=n;  
                    }                    
                    for(int i=1;i<=10;i++){
                        s.str(v.at(i));
                        s>>n;
                        total_jiffies_1+=n;
                    }           
            }
       }
    return (int)(((float)(work_jiffies_1 - work_jiffies_0) / (float)(total_jiffies_1 - total_jiffies_0))* 100);
    }
};
