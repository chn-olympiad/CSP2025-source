#include<bits/stdc++.h>
using namespace std;
string t1,t2;
struct node
{
	string s1,s2;
} s[200005];
int cmp(node a,node b)
{
	return a.s1<b.s1;
}
queue<int> q[5000006];
int vis[200005];
long long bfs(int u,string ing)
{
//	cout<<u<<endl;
	int i,j,k,cd;
	long long ans=0;
	for(i=u;i<t1.size();i++)
	{
//		cout<<i<<" "<<ing<<endl;
		for(j=1;j<=q[i].size();j++)
		{
			if(vis[q[i].front()]==0)
			{
				vis[q[i].front()]=1;
				for(k=0;k<s[q[i].front()].s2.size() ;k++)
				{
					ing[i+k]=s[q[i].front()].s2[k];
//					cout<<"..."<<ing<<"..."<<endl;
				}
				ans+=bfs(s[q[i].front()].s1.size()+i-1,ing);
				vis[q[i].front()]=0;
				for(k=0;k<s[q[i].front()].s2.size();k++)
				{
					ing[i+k]=t1[i+k];
				}
			}
			cd=q[i].front();
			q[i].pop();
			q[i].push(cd);
		}
	}
	if(ing==t2) ans++;
	return ans;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>s[i].s1>>s[i].s2;
	}
	sort(s+1,s+n+1,cmp);
//	cout<<s[1].s1<<s[2].s1<<s[3].s1;
	while(m--)
	{
		cin>>t1>>t2;
		for(i=0;i<t1.size();i++)
		{
			while(q[i].size()) q[i].pop();
		}
		if(t1.size()!=t2.size()) cout<<0<<endl;
		else
		{
			for(i=0;i<t1.size();i++)
			{
				int l=1,r=n,mid;
				{
					while(l<r)
					{
						mid=(l+r)/2;
						if(s[mid].s1[0]<t1[i]) l=mid+1;
						else r=mid;
					}
					for(j=l;s[j].s1[0]==t1[i];j++)
					{
						for(k=0;k<s[j].s1.size();k++)
						{
							if(t1[i+k]!=s[j].s1[k]||t2[i+k]!=s[j].s2[k]) 
							{
//								cout<<t1[i+k]<<"!="<<s[j].s1[k]<<"||"<<t2[i+k]<<"!="<<s[j].s2[k]<<endl;
								break;
							}
//							else cout<<t1[i+k]<<"=="<<s[j].s1[k]<<"&&"<<t2[i+k]<<"=="<<s[j].s2[k]<<endl;
						}
						if(k==s[j].s1.size()) q[i].push(j);
					}
				}
			}
//			for(j=0;j<t1.size();j++) cout<<q[j].size()<<" ";
//			cout<<endl;
			cout<<bfs(0,t1)<<endl;
		}
	}
	return 0;
}
