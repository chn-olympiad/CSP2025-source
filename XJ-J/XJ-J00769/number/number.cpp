#include<bits/stdc++.h>
using namespace std;
long long int n,i,v[100005]={0},t=0;
string a;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	while(i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			v[i]=a[i];
			t++;
		}
		if(a[i]=='/0')
		break;
	}
	sort(v+1,v+1+t,greater<int>());
	for(i=1;i<=t;i++)
	cout<<v[i];
}
