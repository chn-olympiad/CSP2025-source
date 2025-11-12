#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10,Base=131;
unsigned int pw[N];
int n;
int q;
string s1[N],s2[N];
unsigned int hs1[N],hs2[N];
bool pre[N],suf[N]; 
bool check(vector<unsigned int> hs,int l,int r,unsigned int Hs)
{
//	if(Hs==12937) cout<<(hs[r]-(l!=0?hs[l-1]:0)*pw[r-l+1])<<endl;
	return (hs[r]-(l!=0?hs[l-1]:0)*pw[r-l+1])==(Hs);
}
int solve()
{
	string t1,t2;
	cin>>t1>>t2;
	vector<unsigned int> ht1,ht2;
	ht1.push_back(t1[0]);
	ht2.push_back(t2[0]);
	for(int j=1;j<t1.size();j++)
	{
		ht1.push_back(ht1.back()*Base+t1[j]);
		ht2.push_back(ht2.back()*Base+t2[j]);
	}
	int cnt=0;
	pre[0]=(t1[0]==t2[0]);
	for(int i=1;i<t1.size();i++)
		pre[i]=pre[i-1]&&t1[i]==t2[i];
	suf[t1.size()-1]=(t1.back()==t2.back());
	for(int i=t1.size()-2;i>=0;i--)
		suf[i]=suf[i+1]&&t1[i]==t2[i];
	for(int I=1;I<=n;I++)
	{
		int len1=t1.size(),len2=s1[I].size();
		for(int i=0;i<len1-len2+1;i++)
		{
			bool a=i==0?true:pre[i-1];
			bool b=i==(len1-len2)?true:suf[i+len2];
			
//			if(I==3) cout<<i<<" "<<a<<" "<<b<<" "<<check(ht1,i,i+len2-1,hs1[I])<<" "<<check(ht2,i,i+len2-1,hs2[I])<<endl;
			if(a&&b&&check(ht1,i,i+len2-1,hs1[I])&&check(ht2,i,i+len2-1,hs2[I])) cnt++;
		}
	}
	
	return cnt;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<N;i++) pw[i]=pw[i-1]*Base;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].size();j++)
		{
			hs1[i]=hs1[i]*Base+s1[i][j];
			hs2[i]=hs2[i]*Base+s2[i][j];
		}
	}
	while(q--)
	{
		cout<<solve()<<endl;
	}
	return 0;
}

