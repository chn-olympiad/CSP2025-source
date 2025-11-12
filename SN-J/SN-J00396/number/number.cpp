#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[1000],ans=0,cnt=0;
	char c[1000000];
	for(int i=0;i<=50;i++)
	{
		cin>>c[i];
		if(int(c[i])>=49&&int(c[i])<=57)
			a[i]=int(c[i])-48;
			cnt++;
		if(int(c[i])==48)
			ans++;
			cnt++;
	}
	sort(a,a+cnt);
	for(int i=cnt;i>=0;i--)
	{
		if(a[i]!=0)
			cout<<a[i];
	}
	for(int i=0;i<ans;i++)
		cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
