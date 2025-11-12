#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int f[100001];
	for(int i=0;i<=1000000;i++){
		f[i]=-1;
	}
	cin>>s;
	int m=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9'){
			f[i]=s[i];
			m++;
		}
	}
	for(int i=0;i<s.length();i--)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			f[i]=s[i];
			m++;
		}
	}
	sort(f+1,f+m);
	for(int i=m-1;i>=1;i--)
	{
	cout<<f[i];	
	}
	return 0;
};
