#include<bits/stdc++.h>
using namespace std;
int c[10];
char ch;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>ch)c[ch-'0']++;
	for(int i=9;i>=0;--i)while(c[i]--)cout<<i;
	return 0;
}
