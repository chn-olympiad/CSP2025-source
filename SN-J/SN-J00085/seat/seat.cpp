#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s[N];
double n,m;
bool cmp(int m,int n)
{
	for(int i=1;i<=m*n;i++)
	{
		if(s[i]<s[i+1]){
			return s[i]<s[i+1];
		}
		if(s[i]>s[i+1]){
			return s[i]>s[i+1];
		}
	}
}
int main()
{
	
	cin>>n>>m;
	int o=n*m;
	for(int i=1;i<=o;i++)
	{
		cin>>s[1];
	}
	
	return 0;
}
