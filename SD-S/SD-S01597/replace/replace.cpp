#include<bits/stdc++.h>
using namespace std;
#define int long long
int const N=2e5+5,M=5e6+5,P=1e9+7,PP=998442353;
int n,q,cnt,idx,b[M];
string s1,s2;
unordered_map<int,int> tt;
map<int,vector<int>> mp;
int HS(string s,int l,int r)
{
	if(l>r)
		return 0;
	int hs=0;
	for(int i=l;i<=r;i++)
		hs=(hs*13331+s[i])%P;
	return hs;
}
int hs(int a,int b,int c,int l1,int l2)
{
	return (a+2*b+c+131*l1+17*l2)%PP*(a+2)%PP*(b+5)%PP*(c+23)%PP*(l1+3)%PP*(l2+7)%PP;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	int s,t;
	b[0]=1;
	for(int i=1;i<M;i++)
		b[i]=b[i-1]*13331%P;
	for(int i=1;i<=n;i++)
	{
		cin>>s1>>s2;
		if(s1==s2)
			continue;
		for(int j=0;j<s1.size();j++)
			if(s1[j]!=s2[j])
			{
				s=j;
				break;
			}
		for(int j=s1.size()-1;~j;j--)
			if(s1[j]!=s2[j])
			{
				t=j;
				break;
			}
		int h1=HS(s1,0,s-1),h2=HS(s1,t+1,s1.size()-1);
		int h3=HS(s1,s,t),h4=HS(s2,s,t);
		int l1=s,l2=t-s;
		int hh=hs(h1,h3,h4,l1,l2);
		mp[hh].emplace_back(h2);
//		cout<<i<<" "<<s<<" "<<t<<" "<<l1<<" "<<l2<<" "<<hh<<" : "<<h1<<" "<<h2<<" "<<h3<<" "<<h4<<"\n";
	}
//	cout<<"QQQ:\n";
	while(q--)
	{
		cin>>s1>>s2;
		for(int j=0;j<s1.size();j++)
			if(s1[j]!=s2[j])
			{
				s=j;
				break;
			}
		for(int j=s1.size()-1;~j;j--)
			if(s1[j]!=s2[j])
			{
				t=j;
				break;
			}
		tt.clear();
		int h1=0,h2=0,an=0;
		int h3=HS(s1,s,t),h4=HS(s2,s,t);
//		cout<<" "<<s<<" "<<t<<" "<<" : "<<h1<<" "<<h2<<" "<<h3<<" "<<h4<<"\n";
		for(int i=t+1;i<s1.size();i++)
		{
			h2=(h2*13331+s1[i])%P;
			tt[h2]++;
//			cout<<h2<<" ";
		}
//		cout<<"\n";
		tt[0]=1;
		for(int i=s,lo=0;i>=0;i--,lo++)
		{
			if(i!=s)
				h1=(h1+b[lo-1]*s1[i])%P;
//			cout<<h1<<" ";
			vector<int> f=mp[hs(h1,h3,h4,lo,t-s)]; 
			for(int x:f)
			{
				an+=tt[x];
			}
		}
		cout<<an<<"\n";
	}
	return 0;
}

