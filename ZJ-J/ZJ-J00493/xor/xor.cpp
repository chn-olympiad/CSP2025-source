#include<bits/stdc++.h>
using namespace std;
string er[500010];
bool ji[500010][21];
string kl;
int a,n,k;
int ans;
void zhuan(int l)
{
	for(int i=0;i<=20;i++)
	{
		ji[l][i]=ji[l-1][i];
	}
	int j=20;
	while(j>=0)
	{
		if(a>=pow(2,j))
		{
			a-=pow(2,j);
			er[l]+='1';
			ji[l][j]=(!ji[l][j]);
		}
		else er[l]+='0';
		j--;
	}
}
void dfs(int l,int r,int q)
{
	bool f=0;
	if(r>n||l<=0||r<l) return;
	int e,t,qw;
	for(int i=q;i<=r-1;i++)
	{	
		if(f==1) 	
		break;
		for(int j=l;j<=r-i;j++)
		{
			string z;
			for(int p=20;p>=0;p--)
			z+=(ji[i+j][p]+ji[j-1][p])%2+'0';
			if(z==kl) 
			{
				f=1;
				ans++;
				e=i+j+1;
				t=j-1;
				qw=q;
				break;
			}
			
		}
	}
	if(f==1)
	{
		dfs(r,e,qw);
		dfs(t,r,qw+1);
	}
	
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int q=20;
	while(q>=0)
	{
		if(k>=pow(2,q))
		{
			k-=pow(2,q);
			kl+='1';
		}
		else kl+='0';
		q--;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		zhuan(i); 
	}
	dfs(1,n,0);
//	for(int i=1;i<=n;i++)
//	{	
//		for(int j=0;j<=n-i;j++)
//		{
//			string z;
//			if(j==0)
//			{
//				for(int p=20;p>=0;p--)
//				z+=(ji[i][p])+'0';
//				if(a==kl) ans++;
//				continue;
//			}
//			for(int p=20;p>=0;p--)
//			z+=(ji[i+j][p]+ji[i][p])%2+'0';
//			cout<<"z:"<<z<<endl;
//			if(z==kl) 
//			{
//				ans++;
//				i=j+1;
//				break;
//			}
//		}
//	}
	cout<<ans;
	return 0;
}
/*
^为异或 
1 1=>0
1 0=>1
0 0=>0
交换律，结合律成立 
已证得越短越好 
*/

