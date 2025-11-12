#include<bits/stdc++.h>
using namespace std;
int T,q,n,sl,sr,nl;
string st;
struct Node
{
	int l,r,add;
};
Node e[200010];
int dp[5000010];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>st;
			int m=st.size();
			int it=st.find('b');
			e[i].l=it;
			e[i].r=m-it-1;
			cin>>st;
			m=st.size();
			it=st.find('b');
			e[i].add=it-e[i].l;
		}
		for(int i=1;i<=q;i++)
		{
			memset(dp,0,sizeof(dp));
			cin>>st;
			int c=st.size();
			int it=st.find('b');
			sl=it;
			dp[sl]=1;
			cin>>st;
			it=st.find('b');
			nl=it;
			queue<int> q;
			q.push(sl);
			for(int j=1;j<=n;j++)
			{
				int m=q.size();
				for(int k=1;k<=m;k++)
				{
					int t=q.front();
					if(t>=e[j].l&&t<=c-e[j].r)
					{
						dp[t+e[j].add]+=dp[t];
						q.push(t+e[j].add);
					}
				}
			}
			cout<<dp[nl];
		}
	}
	return 0;
}
