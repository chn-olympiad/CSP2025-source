#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
int a[N],b[N],c[N];
vector<int> bj[N];
int main() 
{
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		freopen("club.in","r",stdin);
		freopen("club.out","w",stdout);
		cin>>t;
		while(t--)
		{
			cin>>n;
			for(int i=1;i<=n;i++)
				cin>>a[i]>>b[i]>>c[i];
			bj[1].clear(),bj[2].clear(),bj[3].clear();
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]>=max(b[i],c[i]))
				{
					ans+=a[i];
					bj[1].push_back(a[i]-max(b[i],c[i]));
				}
				else if(b[i]>=max(a[i],c[i]))
				{
					ans+=b[i];
					bj[2].push_back(b[i]-max(a[i],c[i]));
				}
				else if(c[i]>=max(a[i],b[i]))
				{
					ans+=c[i];
					bj[3].push_back(c[i]-max(b[i],a[i]));
				}
			}
			int op=0;
			if(bj[1].size()>n/2) op=1;
			else if(bj[2].size()>n/2) op=2;
			else if(bj[3].size()>n/2)op=3;
			if(op)
			{
				sort(bj[op].begin(),bj[op].end());
				int cnt=bj[op].size()-n/2;
				for(int i=0;i<cnt;i++)
					ans-=bj[op][i];
			}
			cout<<ans<<"\n";
		}
		return 0;
}

