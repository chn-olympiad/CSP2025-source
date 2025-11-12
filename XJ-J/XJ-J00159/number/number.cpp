#include<bits/stdc++.h>
using namespace std;
//1000005
int a[1000005];
char b[1000005];
bool cmp(int x,int y)
{
	if(x>y) return true;
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string c;
	int i,j,n,lena=0;
	cin>>c;
	for(i=0;i<=c.size()-1;i++)
	{
		if(c[i]>='0'&&c[i]<='9')
		{
			a[++lena]=c[i]-48;//Whats your mission in CSP !
		}
	}
	sort(a+1,a+lena+1,cmp);
	for(i=1;i<=lena;i++)
	{
		cout<<a[i];
	}
	return 0;
}
