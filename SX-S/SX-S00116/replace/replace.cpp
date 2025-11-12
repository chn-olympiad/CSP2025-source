#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s1[N],s2[N],t1,t2;
long long n,maxx;
int v[N];
int bfs()
{
	long long result=0;
	string qx;
	queue<string> q;
	q.push(t1);
	while(!q.empty())
	{
		qx=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(qx.find(0,s1[i])!=string::npos)
			{

			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>s1[i]>>s2[i];
	}
	for(int i=1; i<=q; i++) {
		cin>>t1>>t2;
		cout<<t1.find(0,s1[i]);
		memset(v,0,sizeof(v));
		int k=bfs();
		cout<<k;
	}
	return 0;
}