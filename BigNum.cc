#include<iostream>
#include<string>
#include<vector>
#include<cmath>


using namespace std;

class BigNum{
    public:
        BigNum();
        BigNum(const char* str);
        BigNum(const string &str);
        BigNum(const int &m);
    private:
        int len;
        int sign;
        vector<int> data;

}





int main(int argc, char** argv){
    return 0;
}



