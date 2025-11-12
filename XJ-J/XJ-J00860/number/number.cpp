#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[1000005]; 
	int i,k=0,a[1000005]={0};
	for(i=1;i<=1000005;i++)
	{
		cin>>s[i];
		
		if(s[i]>='0'&&s[i]<='9')
		a[++k]=(int)s[i];
	}
	sort(a,a+1+k);
	for(i=k;i>=1;i--)
	cout<<a[i];

    return 0;
} 
