#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include<vector>
#define ll long long
using namespace std;
int len[200007],p[200007],summ[200007][3],sum[3][5000007];
vector<int>v[20007];
vector<int>v2[27];
int mod=557139977;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	p[0]=1;
//	cout<<"&&";
	for(int i=1;i<=5e6;i++)
	{
		p[i]=p[i-1]*26%mod; 
	}
	int n,q;
	cin>>n>>q;
//	cout<<"&&";
	for(int i=1;i<=n;i++)
	{
		string s1,s2;
		cin>>s1>>s2;
//		cout<<s1<<" "<<s2<<endl; 
		getchar();
		int ln=s1.size();
		len[i]=ln;
		if(ln>=3)
		{
			int x=s1[0]*p[2]+s1[1]*p[1]+s1[2]-'a'*(p[2]+p[1]+1);
			v[x].push_back(i);
		}
		else
		{
			v2[s1[0]-'a'].push_back(i);
		}
		ll sum1=0,sum2=0;
		for(int j=0;j<ln;j++)
		{
			sum1=(sum1*26+s1[j]-'a'+mod)%mod;
			sum2=(sum2*26+s2[j]-'a'+mod)%mod;
		}
		summ[i][1]=sum1;
		summ[i][2]=sum2;
//		cout<<summ[i][1]<<" "<<summ[i][2]<<endl;
	}
//	cout<<"hh"<<endl;
//	ll sum6=0;
//	cout<<"a"; 
	while(q--)
	{
		ll ans=0;
		string s1,s2;
		cin>>s1>>s2;
		getchar();
		int ln=s1.size();
		sum[1][0]=s1[0]-'a';
		sum[2][0]=s2[0]-'a';
//		cout<<"a";
		for(int i=1;i<ln;i++)
		{
			sum[1][i]=(sum[1][i-1]*26+s1[i]-'a'+mod)%mod;
			sum[2][i]=(sum[2][i-1]*26+s2[i]-'a'+mod)%mod;
		}
		for(int i=0;i<ln;i++)
		{
			for(int j=0;j<v2[s1[i]-'a'].size();j++)
			{
	//			cout<<"r2"<<endl;
				int k=v2[s1[i]-'a'][j];
				int a=(sum[1][i+len[k]-1]-(1ll*sum[1][i-1]*p[len[k]])%mod+mod)%mod;
				if(a==summ[k][1])
				{
					int shengyu=(sum[1][ln-1]-1ll*a*p[ln-i-len[k]]+mod)%mod;
					
					if((shengyu+1ll*summ[k][2]*p[ln-i-len[k]])%mod==sum[2][ln-1]) ans++;
				}
			}
//			cout<<endl;
			int x=s1[i]*p[2]+s1[i+1]*p[1]+s1[i+2]-'a'*(p[2]+p[1]+1);
			for(int j=0;j<v[x].size();j++)
			{
//				cout<<j;
				int k=v[x][j];
//				if(k==1) cout<<"&&"<<endl;
				int a=(sum[1][i+len[k]-1]-(1ll*sum[1][i-1]*p[len[k]])%mod+mod)%mod;
//				if(k==1) cout<<a<<endl;
				if(a==summ[k][1])
				{
					int shengyu=(sum[1][ln-1]-1ll*a*p[ln-i-len[k]]+mod)%mod;
//					if(k==1) cout<<summ[k][2]*p[ln-i-len[k]]<<" "<<shengyu<<endl;
					if((shengyu+1ll*summ[k][2]*p[ln-i-len[k]])%mod==sum[2][ln-1]) ans++;
				}
			}
		}
		printf("%d\n",ans);
//	sum6+=ans;
//		cout<<"y"; 
	}
//	cout<<sum6<<endl;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

