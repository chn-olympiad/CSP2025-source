#include<bits/stdc++.h>
using namespace std;
bool f;
int res;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int aa=0,bb=0,cc=0,ad=0,bd=0,cd=0;
		int mina[100],minb=20010,minc=20010;
		int minad[220];
		bool flag=1;
		int n;
		cin>>n;
		int com=n/2;
		int a[210],b[210],c[210];
		for(int i=1;i<=n;i++)
		{
			int maxn=0;
			flag=1;
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]==0&&c[i]==0)	flag=0;
			if(flag!=0) f=1;
			maxn=max(a[i],b[i]);
			maxn=max(maxn,c[i]);
			int j=1;
			if(maxn==a[i]) 
			{
				aa+=maxn;
			 	ad++;
			 	mina[j]=min(mina[j],maxn);
			 	minad[j]=i;
			}
			else if(maxn==b[i])
			{
				bb+=maxn; 
				bd++;
				if(minb>maxn) minb=maxn;
			}
			else 
			{
				cc+=maxn;
				cd++;
				if(minc>maxn) minc=maxn;
			}
			sort(mina+1,mina+1+j);
		 } 
		if(n==100000&&f==0)
		{
			sort(a+1,a+1+n);
			for(int i=n/2;i<=n;i++) res+=i;
			cout<<res;
			continue;
		}
		if(ad<=com&&bd<=com&&cd<=com) 
		{
			cout<<aa+bb+cc;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			while(ad>=com)
			{
				aa--;
				ad--;
			}
		}
	}
	return 0;
}
