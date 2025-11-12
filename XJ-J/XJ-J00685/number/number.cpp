#include<bits/stdc++.h>
using namespace std;
long long int a[10000][10000],t=0,i,j,v=0;
char s[10000];
int main()
{
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	scanf("%llf",&s);
	for(i=1;i<=INT_MAX;i++)
	{
		for(j=1;j<=INT_MAX;j++)
		{
			if(s[i]<s[j])
			{
				if(s[i]>='1'&&s[i]<='9')
				t+=s[i];
				if(s[j]>='1'&&s[j]<='9')
				v+=s[j];
			}
		}
	} 
	cout<<t;
	//ДњТы 
	return 0;
}  
