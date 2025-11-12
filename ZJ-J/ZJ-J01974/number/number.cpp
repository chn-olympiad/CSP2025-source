#include<bits/stdc++.h>
#define rint register int
using namespace std;
string s;int a[11]={};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for(rint i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(rint i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}
    return 0;
}
/*
    Code is far away from
bug with the animal protecting
    神兽保佑，代码无bug
*/
