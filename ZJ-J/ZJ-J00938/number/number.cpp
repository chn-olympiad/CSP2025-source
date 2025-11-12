#include<bits/stdc++.h>
using namespace std;
int p[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9')p[s[i]-'0']++;
	for(int j=9;j>=0;j--)
		for(int i=1;i<=p[j];i++)putchar(j+'0');
}

