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
    }
    int get_used(){
        
    }
};
