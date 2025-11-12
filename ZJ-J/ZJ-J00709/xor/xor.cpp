#include<bits/stdc++.h>
using namespace std;

int n,k,temp;
bool b[500010][21];
bool x[500010][21];
int fc[1050000];

struct nod
{
	int l,r;
}h[500010];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int k;
	temp=k;
	int step=0;
	while(temp>0)
	{
		step++;
		if(temp%2==1) b[0][step]=true;
		else b[0][step]=false;
		temp=temp/2;
	}
	int a;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		temp=a;
		step=0;
		while(temp>0)
		{
			step++;
			if(temp%2==1) b[i][step]=true;
			else b[i][step]=false;
			temp=temp/2;
		}
		for(int j=1;j<=20;j++)
		{
			if(b[0][j]!=b[i][j]) x[i][j]=true;
			else x[i][j]=false; 
		}
		int num=0;
		for(int j=20;j>=1;j--)
		{
			num*=2;
			num+=x[i][j];
		}
	}
	step=0;
	cout<<0<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=20;j++)
//		{
//			if(b[i][j]==true) cout<<1;
//			else cout<<0;
//		}
//		cout<<endl;
//	}
	return 0;
}