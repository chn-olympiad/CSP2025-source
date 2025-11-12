#include<bits/stdc++.h>
using namespace std;
long long n,m,c[501],b[501],sum,ans;//c耐心 b题目 
bool p[501],lu[501],flag;//录为1 
string a;
const int mo=998244353;
//998244353
long long jc(int x)
{
	int u=1;
	for(int i=x;i>=1;i--) u=(u*i)%mo;
	return u;
}
void pailie(int x,int y)//当前天数 需录取 
{
	if(x>n) return;
	int temp,s; s=y;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==0)
		{if(b[x]==1)
			{if(x>c[i])
				{
					temp=0;
					for(int j=x-c[i];j<x;j++) temp+=lu[j];
					if(temp!=0) {lu[x]=1; s=y-1;}
				}
			 else {lu[x]=1; s=y-1; }
		}
			if(s==0) {ans=(ans+jc(n-x))%mo;}
			else {p[i]=1;pailie(x+1,s);p[i]=0;lu[x]=0;}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.ans","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		b[i]=a[i-1]-'0';
		sum+=b[i]; 
		if(c[i]==0) flag=1;
	}
	if(m==n){if(sum!=n||flag!=0) cout<<0; else cout<<jc(n); return 0;}
	if(m>sum){cout<<0; return 0;}
	pailie(1,m);
	cout<<ans;
	return 0;
 }

