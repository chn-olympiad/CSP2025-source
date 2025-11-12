#include<bits/stdc++.h>
using namespace std;
long long int i,a[1000004],n=0;
char c[1000006];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>c;
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]<='9'&&c[i]>='0')
		{
			n++; 
			a[n]=((long long int)(c[i]));
			if(a[n]==48) a[n]=0;
			if(a[n]==49) a[n]=1;
			if(a[n]==50) a[n]=2;
			if(a[n]==51) a[n]=3;
			if(a[n]==52) a[n]=4;
			if(a[n]==53) a[n]=5;
			if(a[n]==54) a[n]=6;
			if(a[n]==55) a[n]=7;
			if(a[n]==56) a[n]=8;
			if(a[n]==57) a[n]=9;
		}
	}
	sort(a+1,a+1+n);
	for(i=n;i>0;i--)
	{
		cout<<a[i];
	}
	return 0;
} 
