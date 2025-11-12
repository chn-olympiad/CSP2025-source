#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

int cnt=0,num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if('0'<=a[i]&&a[i]<='9'){
            num[cnt++]=a[i]-48;
        }
    }
    sort(num,num+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<num[i];
    }
    return 0;
}

              
              
              
        
