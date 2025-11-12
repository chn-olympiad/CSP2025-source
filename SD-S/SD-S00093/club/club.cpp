//Ô¤¼Æ£º100pts 

#include<bits/stdc++.h>
using namespace std;
int read();

const int N=1e5+2;
int T,n,t[3],t2[3];
struct node{
	int a[4],b[4],now;
}s[N]; 
long long ans;
priority_queue<pair<int,int> >pq[3];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			s[i].b[0]=s[i].b[1]=s[i].b[2]=s[i].now=-1;
			s[i].b[3]=3,s[i].a[3]=20001;
			t[0]=read();t[1]=read();t[2]=read();
			s[i].a[0]=t2[0]=t[0],t2[1]=s[i].a[1]=t[1],t2[2]=s[i].a[2]=t[2];
			sort(t,t+3);
			for(int j=0;j<3;j++)
			{
				if(t2[j]==t[2]&&s[i].b[0]==-1)
					s[i].b[0]=j;
				else if(t2[j]==t[1]&&s[i].b[1]==-1)
					s[i].b[1]=j;
				else
					s[i].b[2]=j;
			}
			int tt1=s[i].a[s[i].b[1]]-s[i].a[s[i].b[0]];
			s[i].now=s[i].b[0];
			pq[s[i].b[0]].push({tt1,i});
			if(pq[s[i].now].size()>n/2)
			{
				int tt2=pq[s[i].now].top().second;
				pq[s[i].now].pop();
				s[tt2].now=s[tt2].b[1];
				pq[s[tt2].b[1]].push({0,tt2});
			}
		}
		for(int i=0;i<3;i++)
		{
			while(!pq[i].empty())
			{
				int tt1=pq[i].top().second;
				pq[i].pop();
				ans+=s[tt1].a[s[tt1].now];
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
int read()
{
	int val=0,sgn=1;
	char ch=getchar/*_unlocked*/();
	for(;!isdigit(ch);ch=getchar/*_unlocked*/())
		if(ch=='-')
			sgn=-1;
	for(;isdigit(ch);ch=getchar/*_unlocked*/())
		val=val*10+ch-48;
	return val*sgn;
}
