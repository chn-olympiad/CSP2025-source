#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int a[100000];
	for(int i=1;i<=100000;i++)
	{
		if(n[i]>='a'&&n[i]<='z') 
		    a[i]=n[i]-'0';
	}
	sort(a+1,a+100000+1,0);
	cout<<a;
	return 0;
 } 
