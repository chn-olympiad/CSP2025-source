#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;

int n,q;

//map<long long,long long> s;

map<string,string> s;

const int mod=998244353;
const int ji=1e5+7;

long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%mod;
//			a=a*a%mod;
		}
		a=a*a%mod;
		b>>=1; 
	}
	return res;
}

string a;
string b;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		string tem,tam;
		cin>>tem;
		cin>>tam;
		s[tem]=tam;
//		int len=strlen(tem);
//		long long h=0;
//		for(int i=0;i<tem;i++)
//		{
//			h=(h+ksm(ji,(tem[i]-'a'))*(tem[i]-'a')%mod)%mod;
//		}
//		long long d=0;
//		cin>>tem;
//		len=strlen(tem);
//		for(int i=0;i<tem;i++)
//		{
//			d=(d+ksm(ji,(tem[i]-'a'))*(tem[i]-'a')%mod)%mod;
//		}		
	}
	long long ans=0;
	for(int i=1;i<=q;i++)
	{
		ans=0;
		cin>>a>>b;
//		cout<<"["<<a<<"] ["<<b<<"]\n";
		int len=a.size();
//		cout<<len<<" ";
		int l=0,r=len-1;
		for(l=0;l<len;l++)
		{
			if(a[l]!=b[l])
			{
				break;
			}
		}
		for(r=len-1;r>=l;r--)
		{
			if(a[r]!=b[r])
			{
				break;
			}
		}
//		cout<<l<<" "<<r<<"\n";
		for(int j=0;j<=l;j++)
		{
			for(int k=r;k<len;k++)
			{
				string x=a.substr(j,k-j+1);
				string y=b.substr(j,k-j+1);
				if(s[x]==y)
				{
					ans++;
//					cout<<j<<" "<<k<<" \n";
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 2
 xabcx xadex
 ab cd
 bc de
 aa bb
 xabcx xadex
 aaaa bbbb
 */

