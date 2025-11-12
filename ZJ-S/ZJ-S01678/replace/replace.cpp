#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e6+5,base=131;
const long long Mod=1e9+7;
long long n,q,pw[M];
vector<long long>hash1[N],hash2[N];
vector<long long>hash3,hash4;
string s1[N],s2[N];
long long get(int l,int r)
{
	if(!l) return hash3[r];
	return ((hash3[r]-hash3[l-1]*pw[r-l+1]%Mod)%Mod+Mod)%Mod;
};
long long get2(int l,int r)
{
	if(!l) return hash4[r];
	return ((hash4[r]-hash4[l-1]*pw[r-l+1]%Mod)%Mod+Mod)%Mod;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(n<=100&&q<=100)
	{
		for(int i=1;i<=n;++i) cin>>s1[i]>>s2[i];
		while(q--)
		{
			int sum=0;
			string t1,t2;
			cin>>t1>>t2;
			for(int i=1;i<=n;++i)
			{
				for(int j=0;j<t1.size()-s1[i].size()+1;++j)
				{
					bool flag=1;
					for(int k=0;k<s1[i].size();++k)
					if(t1[j+k]!=s1[i][k])
					{
						flag=0;
						break;
					}
					if(!flag) continue;
					string s="";
					for(int k=0;k<j;++k) s+=t1[k];
					s+=s2[i];
					for(int k=j+s1[i].size();k<t1.size();++k) s+=t1[k];
					if(s==t2)
					{
						sum++;
						break;
					}
				}
			}
			cout<<sum<<"\n";
		}
		return 0;
	}
	pw[0]=1;
	for(int i=1;i<M;++i) pw[i]=pw[i-1]*base,pw[i]%=Mod;
	for(int i=1;i<=n;++i)
	{
		cin>>s1[i]>>s2[i];
		hash1[i].push_back(s1[i][0]);
		hash2[i].push_back(s2[i][0]);
		for(int j=1;j<s1[i].size();++j)
		{
			hash1[i].push_back((hash1[i].back()*base+s1[i][j])%Mod);
			hash2[i].push_back((hash2[i].back()*base+s2[i][j])%Mod);
		}
	}
	while(q--)
	{
		hash3.clear();
		hash4.clear();
		int sum=0;
		string t1,t2;
		cin>>t1>>t2;
		hash3.push_back(t1[0]);
		hash4.push_back(t2[0]);
		for(int j=1;j<t1.size();++j)
		{
			hash3.push_back((hash3.back()*base+t1[j])%Mod);
			hash4.push_back((hash4.back()*base+t2[j])%Mod);
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<t1.size()-s1[i].size()+1;++j)
			{
				if(!j||get(0,j-1)==get2(0,j-1))
				{
					if(get(j,j+s1[i].size()-1)==hash1[i].back()&&get2(j,j+s1[i].size()-1)==hash2[i].back())
					{
						if(j==t1.size()-1||get(j+s1[i].size(),t1.size()-1)==get2(j+s1[i].size(),t1.size()-1))
						sum++;
						break;
					}
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
