#include<bits/stdc++.h>
using namespace std;
int l,i,j=0,c[100004];
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(i=0;i<l;i++)
		if(s[i]>='0'&&s[i]<='9')
		{
			j++;
			c[j]=s[i]-'0';
		}
	for(i=1;i<=j;i++)
		if(c[i]==9)
			cout<<c[i];
	for(i=1;i<=j;i++)
		if(c[i]==8)
			cout<<c[i];
	for(i=1;i<=j;i++)
		if(c[i]==7)
			cout<<c[i];
	for(i=1;i<=j;i++)
		if(c[i]==6)
			cout<<c[i];
	for(i=1;i<=j;i++)
		if(c[i]==5)
			cout<<c[i];
	for(i=1;i<=j;i++)
		if(c[i]==4)
			cout<<c[i];
	for(i=1;i<=j;i++)
		if(c[i]==3)
			cout<<c[i];
	for(i=1;i<=j;i++)
		if(c[i]==2)
			cout<<c[i];
	for(i=1;i<=j;i++)
		if(c[i]==1)
			cout<<c[i];
	for(i=1;i<=j;i++)
		if(c[i]==0)
			cout<<c[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
