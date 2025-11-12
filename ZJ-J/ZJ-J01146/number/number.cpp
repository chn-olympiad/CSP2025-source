#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int i=0;
	for(int j=0;j<s.size();j++){
		if(s[j]>='0'&&s[j]<='9')a[++i]=s[j]-'0';
	}
	sort(a+1,a+i+1);
	for(int j=i;j>=1;j--)cout<<a[j];
	return 0;
} 
