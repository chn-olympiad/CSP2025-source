#include<bits/stdc++.h>
const int N=1e5+5;

using namespace std;

int a[N][4];
int getd(int i,int j){return a[i][j]-max(a[i][1+j%3],a[i][1+(j+1)%3]);}
struct node
{
	int i,j;
	bool operator<(const node &x)const{return getd(i,j)>getd(x.i,x.j);}
};
int cnt[4],ch[N];
priority_queue<node> q;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		int n,ans=0;cin>>n;
		for(int i=1;i<=3;++i) cnt[i]=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=3;++j)
				cin>>a[i][j];
		for(int i=1;i<=n;++i)
		{
			if(a[i][1]>=max(a[i][2],a[i][3])) ans+=a[i][1],ch[i]=1,cnt[1]++;
			else if(a[i][2]>=max(a[i][1],a[i][3])) ans+=a[i][2],ch[i]=2,cnt[2]++;
			else ans+=a[i][3],ch[i]=3,cnt[3]++;
		}
		int p;
		if(cnt[1]>=max(cnt[2],cnt[3])) p=1;
		else if(cnt[2]>=max(cnt[1],cnt[3])) p=2;
		else p=3;
		//cout<<"p:"<<p<<endl;
		for(int i=1;i<=n;++i)
			if(ch[i]==p) q.push({i,ch[i]});
		while(cnt[p]>n/2)
		{
			//cout<<q.top().i<<" "<<q.top().j<<" "<<getd(q.top().i,q.top().j)<<endl;
			ans-=getd(q.top().i,q.top().j);q.pop();cnt[p]--;
		}
		cout<<ans<<"\n";
		while(!q.empty()) q.pop();
	}
	return 0;
}
