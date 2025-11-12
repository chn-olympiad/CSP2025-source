#include<bits/stdc++.h>
using namespace std;
#define uint unsigned int
const int base = 131;
#define PII pair<uint,uint>
#define F first
#define S second
 
const int N = 2e5 + 10;
const int M = 5e6 + 10;

int n,Q;
uint Hsh[M][2],Hs[M][2];
uint pw[M];
string L1,L2;
map<PII,int>mp;
uint get_Hsh(int l,int r,int k){return Hs[r][k]-1ll*Hs[l-1][k]*pw[r-l+1];}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>Q;
	string s1,s2;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++)
			Hsh[i][0]=base*Hsh[i][0]+s1[j]-'a'+1;
		for(int j=0;j<s2.size();j++)
			Hsh[i][1]=base*Hsh[i][1]+s2[j]-'a'+1;
//		cout<<Hsh[i][0]<<" "<<Hsh[i][1]<<"\n";
		mp[make_pair(Hsh[i][0],Hsh[i][1])]++;
	}
	pw[0]=1;
	for(int i=1;i<M;i++) pw[i]=pw[i-1]*base;
	while(Q--)
	{
		cin>>L1>>L2;
		int pr,bc;
		int len=L1.size();
		L1="#"+L1+"#";
		L2="$"+L2+"$";
		for(int i=1;i<=len;i++)
			Hs[i][0]=base*Hs[i-1][0]+L1[i]-'a'+1;
		for(int i=1;i<=len;i++)
			Hs[i][1]=base*Hs[i-1][1]+L2[i]-'a'+1;
		for(int i=1;i<=len+1;i++)
			if(L1[i]!=L2[i]){pr=i-1;break;}
		for(int i=len;i>=0;i--)
			if(L1[i]!=L2[i]){bc=i+1;break;}
		int ans=0;
		for(int l=1;l<=pr+1;l++)
			for(int r=bc-1;r<=len;r++)
			{
				if(l>r) continue;
//				cout<<l<<" "<<r<<" "<< get_Hsh(l,r,0)<<" "<<get_Hsh(l,r,1)<<"\n";
				PII k=make_pair(get_Hsh(l,r,0),get_Hsh(l,r,1));
				ans+=mp[k];
			}
		cout<<ans<<"\n";
	}
	return 0;
}
