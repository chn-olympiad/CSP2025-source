#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	long long z=0,x[12]={},c=0,v=0;
	cin>>a;
	z=a.size();
	for(int i=0;i<=z;i++)
	{
		if(a[i]>='0' || a[i]<='9')
		{
			x[a[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--)
	{
		for( ;x[i]>0;)
		{
			c=c*10+i;
			x[i]--;
		}
	}
	cout<<c;
	return 0;
}
