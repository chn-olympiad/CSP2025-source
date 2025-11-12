#include<bits/stdc++.h>
using namespace std;

constexpr bool isprime(int x){
    for(int i=2;i*i<=x;i++)if(x%i==0)return false;
    return true;
}

int main(){
    vector<int> vec;
    vec.push_back(5);
    while(vec.back()<5e5){
        int x=vec.back()*1.5;
        while(!isprime(x))x++;
        vec.push_back(x);
    }
    for(int i:vec)printf("%d,",i);
    return 0;
}