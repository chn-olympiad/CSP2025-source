#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[10]={},i;
	cin>>s;
	for(i=0;i<s.size();i++)
		if(s[i]>47&&s[i]<58)
			a[s[i]-48]++;
	for(i=9;i+1;i--)
		while(a[i]--)
		cout<<i;
}
