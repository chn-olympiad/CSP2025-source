#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10100];
int fs,mc;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	fs=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==fs)
		{
			mc=i;
			break;
		}
	}
	int h;
	if(mc%n==0)
	{
		cout<<mc/n;
		h=mc/n;
	}
	else
	{
		cout<<mc/n+1;
		h=mc/n+1;
	}
//	cout<<endl<<mc<<" "<<h<<endl;
	cout<<" ";
	if(h%2==0)
	{
		if(mc%n==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n-mc%n+1;
		}
	}
	else
	{
		if(mc%n!=0)
		{
			cout<<mc%n;
		}
		else cout<<n;
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
