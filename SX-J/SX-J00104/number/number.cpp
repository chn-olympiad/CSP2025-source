#include<bits/stdc++.h>//T1_100 fuckCCf fuckCSP-J
using namespace std;
const int N=1e6+10;
#define ll long long
string s;
ll len,k;
int a[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,cmp);
	int f=-1;
	for(int i=1;i<=k;i++)
	{
		if(a[i]!=0)
		{
			f=i;
			break;
		}
	}
	if(f==-1) cout<<'0';
	else
	{
		for(int i=f;i<=k;i++)
		{
			cout<<a[i];
		}
	}
	return 0;
}