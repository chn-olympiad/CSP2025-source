#include<bits/stdc++.h>
using namespace std;
long long int i,j,a[1000005],len,k,t=0;
char s[1000005];
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++j]=s[i]-'0';
			t++;
		}
	}
	sort(a+1,a+1+j,greater<int>());
	for(k=1;k<=j;k++)
	{
		cout<<a[k];
	}
	return 0;
} 
