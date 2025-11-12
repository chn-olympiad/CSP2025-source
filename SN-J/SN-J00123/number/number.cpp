//SN-J00123刘柏睿蒲城县尧山中学
#include<bits/stdc++.h>
using namespace std;
int n;
string st;
string num;
int main()
{
    freopen("number1.in","r",stdin);
    freopen("number1.out","w",stdout);
    string st;
    cin>>st;
    string num=st;
    n=0;
    while(st[n]<st[n+1]){
        st[n+1]=num[n],st[n]=num[n+1];
        n++;
    }
	cout<<st;
    return 0;
}

