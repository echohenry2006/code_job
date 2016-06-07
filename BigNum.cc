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
        
        BigNum(const BigNum &rhs){
            *this=rhs;
        }
        friend bool operator>(const BigNum &lhs, const BigNum &rhs);
        friend bool operator>=(const BigNum &lhs, const BigNum &rhs);
        friend bool operator<(const BigNum &lhs, const BigNum &rhs);
        friend bool operator<=(const BigNum &lhs, const BigNum &rhs);
        friend bool operator==(const BigNum &lhs, const BigNum &rhs);

        BigNum& operator=(const BigNum &rhs);
        BigNum& operator+=(const BigNum &rhs);
        BigNum& operator-=(const BigNum &rhs);
        friend BigNum operator-(const BigNum &rhs);
        friend BigNum operator+(const BigNum &rhs);
        friend ostream& operator<<(ostream& os,const BigNum &obj);
        friend BigNum operator+(const BigNum &lhs, const BigNum &rhs);
        friend BigNum operator-(const BigNum &lhs, const BigNum &rhs);
    private:
        int len;
        int sign;
        vector<int> data;
        int comp(const BigNum &rhs) const;

};

BigNum::BigNum(const char* str){
    
    len=0;
    sign=0;
    data.clear();
    
    if(str[0]=='-')
        sign=-1;
    else 
        sign=1;
    
    int i=0;
    while(1){
        if(str[i]=='0' || str[i] =='-' || str[i] =='+'){
            i++;
            continue;
        }
        else
            break;
    }

    for(;;i++){
        if(str[i]=='\0')break;
        
        if(str[i]>='0' && str[i]<='9'){
            data.push_back((int)(str[i]-'0'));
            len++;
        }
    }

    if(data.size()==0){
        data.push_back(0);
        len=1;
    }

}

bool operator>(const BigNum &lhs, const BigNum &rhs){
    return lhs.comp(rhs)>0;
}

bool operator>=(const BigNum &lhs, const BigNum &rhs){
    return lhs.comp(rhs)>=0;
}
        
bool operator<(const BigNum &lhs, const BigNum &rhs){
    return lhs.comp(rhs)<0;
}
        
bool operator<=(const BigNum &lhs, const BigNum &rhs){
    return lhs.comp(rhs)<=0;
}
bool operator==(const BigNum &lhs, const BigNum &rhs){
    return lhs.comp(rhs)==0;
}
ostream& operator<<(ostream& os, const BigNum &obj){
    int len=obj.data.size();
    if(obj.sign==-1)os<<"-";
    for(int i=0;i<len;i++)
        os<<obj.data[i];
    return os; 
}

int BigNum::comp(const BigNum &rhs) const{
    if(sign!=rhs.sign)
        return sign-rhs.sign;
    if(sign==0)
        return 0;
    if(data.size()>rhs.data.size())
        return sign*1;
    else if(data.size()==rhs.data.size()){
        for(int i=0;i<data.size();i++)
            if(data[i]!=rhs.data[i])
                return sign*(data[i]-rhs.data[i]);

        return 0;
    }
    else
        return -1*sign;
}
    


BigNum& BigNum::operator=(const BigNum &rhs){
    data=rhs.data;
    len=rhs.len;
    sign=rhs.sign;
    return *this;
}

BigNum operator-(const BigNum &rhs){
    BigNum a(rhs);
    a.sign=-a.sign;
    return a;
}

BigNum& BigNum::operator-=(const BigNum &rhs){
    return *this+=-rhs;
}

BigNum& BigNum::operator+=(const BigNum &rhs){
    if(sign==0)
        return *this=rhs;
    if(rhs.sign==0)
        return *this;

    vector<int> out;
    //int carry=0;
    int ln=len;
    int rn=rhs.len;
    int minn=ln<rn?ln:rn;
    int maxn=ln>rn?ln:rn;

    if(sign==rhs.sign){

        int tmp;
        int i;
        int carry=0;
        //cout<<minn<<maxn<<endl;
        for(i=0;i<minn;i++){
            tmp=carry+data[ln-i-1]+rhs.data[rn-i-1];
            out.insert(out.begin(),1,tmp%10);
            carry=tmp/10;
        }
        if(ln<rn){
            for(;i<maxn;i++){
                tmp=carry+rhs.data[rn-i-1];
                out.insert(out.begin(),1,tmp%10);
                carry=tmp/10;
            }
            if(carry>0)
                out.insert(out.begin(),1,carry);
        }
        else{
            for(;i<maxn;i++){
                tmp=carry+data[ln-i-1];
                out.insert(out.begin(),1,tmp%10);
                carry=tmp/10;
            }
            if(carry>0)
                out.insert(out.begin(),1,carry);
        }
        data=out;
        len=data.size();
    }
    else{
        if( (sign>0 && (*this > -rhs)) || (sign<0 && (*this < -rhs))){
            int tmp;
            int i;
            int carry=0;
            for(i=0;i<rn;i++){
                tmp=data[ln-i-1]-rhs.data[rn-i-1]+carry;
                //cout<<"tmp+++"<<tmp<<endl;
                carry=tmp<0?-1:0;
                tmp=tmp<0?10+tmp:tmp;
                //cout<<"tmpis"<<tmp<<endl;
                //cout<<"carry"<<carry<<endl;
                out.insert(out.begin(),1,tmp);
            }
            for(;i<ln;i++){
                tmp=data[ln-i-1]+carry;
                carry=tmp<0?-1:0;
                tmp=tmp<0?10+tmp:tmp;
                out.insert(out.begin(),1,tmp);
            }
            while(!out.empty()){
                if(out.front()!=0)break;
                out.erase(out.begin());
            }
            if(out.size()==0)out.push_back(0);
            len=out.size();
            data=out;

        }
        else{
            sign=rhs.sign;
            int tmp;
            int i;
            int carry=0;
            for(i=0;i<ln;i++){
                tmp=rhs.data[rn-i-1]-data[ln-i-1]+carry;
                carry=tmp<0?-1:0;
                tmp=tmp<0?10+tmp:tmp;
                out.insert(out.begin(),1,tmp);
            }
            for(;i<rn;i++){
                tmp=rhs.data[rn-i-1]+carry;
                carry=tmp<0?-1:0;
                tmp=tmp<0?10+tmp:tmp;
                out.insert(out.begin(),1,tmp);
            }
            while(!out.empty()){
                if(out.front()!=0)break;
                out.erase(out.begin());
            }
            if(out.size()==0)out.push_back(0);
            len=out.size();
            data=out;
        }
    }
    return *this;
}

           

BigNum operator-(const BigNum &lhs, const BigNum &rhs){
    BigNum a(lhs);
    a-=rhs;
    return a;
}

BigNum operator+(const BigNum &lhs, const BigNum &rhs){
    BigNum a(lhs);
    a+=rhs;
    return a;
}

int main(int argc, char** argv){
    //vector<int> aa(3,9);
    //vector<int> bb(4,1);
    //if(aa>bb)cout<<"a>b"<<endl;
    BigNum a("111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
    BigNum b("-0999");
    //cout<<-b<<endl;
    //if(a<(-b))
    //    cout<<"-a>b"<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    return 0;
}



