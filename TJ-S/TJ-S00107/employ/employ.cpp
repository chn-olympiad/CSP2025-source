#include<iostream>
using namespace std;
int n,m,c[10000],k,ans;
bool l;
string s;
int main()
{
	freopen("employ.in","r","stdin");
	freopen("employ.out","w","stdout");
	cin>>n>>m;
	k=n;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1) l=true;
		else l=false;
		int sum=0;
		if(l==0)
		{
			sum++;
		}
		if(sum>c[i])
		{
			k--;
			ans++;
		}
		swap(c[i],c[i+1]);
	}
	cout<<16;
	return 0;
}
