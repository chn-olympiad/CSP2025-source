#include<bits/stdc++.h>
using namespace std;
long long s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	string s,s1;
	for(int i=1;i<=s.length();i++)
	{
		if(i==0||i==1||i==2||i==3||i==4||i==5||i==6||i==7||i==8||i==9)
		{
			s1.length()+i;
		}
	}
	for(int i=1;i<=s1.length();i++)
	{
		if(s1[i]<s1[i+1])
		{
			int t=s1[i];
			s1[i]=s1[i+1];
			s1[i+1]=t;
		}
	}
	for(int i=1;i<=s1.length();i++)
	{
		cout<<s1[i];
	}
	return 0;
}
