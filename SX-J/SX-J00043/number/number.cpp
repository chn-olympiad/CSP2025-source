#include<bits/stdc++.h>
using namespace std;
int a[11],b[1000001],t=0,c;
string s,s1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		c=a[i];
		while(c--){
			t++;
			b[t]=i;
			cout<<b[t];
		}
		t=0;
	}
	return 0;
}