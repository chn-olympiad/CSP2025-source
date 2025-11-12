#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1;
int n,q;
string s1[N],s2[N];
string t1,t2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>s1[i]>>s2[i];
	for(int v=1;v<=q;++v)
	{
		cin>>t1>>t2;
		int ans=0;
		for(int k=1;k<=n;++k)
			for(int i=0;i<t1.size();++i)
				if(t1.substr(i,s1[k].size())==s1[k])
				{
//					cout<<i<<" "<<k<<"\n";
					string a=t1.substr(0,i),b=t1;
					b.erase(0,i+s1[k].size());
//					cout<<a<<" "<<s2[k]<<" "<<b<<"\n";
					if(a+s2[k]+b==t2) ++ans;
				}
//		cout<<"ans=";
		cout<<ans<<"\n"; 
	}
}
