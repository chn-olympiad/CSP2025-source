#include<bits/stdc++.h>
using namespace std;
long long c,d[100005];

char o;

int main()
{
	string a,b;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	
	for(int i=1;i<=a.size;i++)
	{
		if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0')
		d[i]=a[i];
	}
	c=a.size;
	sort(d+1,d+c+1);
	cout<<d;
	return 0;
}
