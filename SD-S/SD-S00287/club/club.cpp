#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
struct node{
	int d,pos;
};
int T,n,d,pre[8];
int cnt[8],a[N][4];
ll ans;
vector<node> e[N];
priority_queue<int,vector<int>,greater<int>> q[7];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool cmp(node a,node b){
	return a.d>b.d;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read(); 
	while(T--){
		for(int i=1;i<=3;i++)
			cnt[i]=0,pre[i]=0;
		ans=0;	
		n=read();
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<=3;i++){
			while(!q[i].empty())
				q[i].pop();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				e[i].push_back({a[i][j],j});
			}
		}
		for(int i=1;i<=n;i++)
			sort(e[i].begin(),e[i].end(),cmp);
		for(int i=1;i<=n;i++){
			if(cnt[e[i][0].pos]<(n/2)){
				ans+=e[i][0].d;
				cnt[e[i][0].pos]++;
				q[e[i][0].pos].push(e[i][0].d);
			}
			else if(e[i][0].d>q[e[i][0].pos].top()){
				ans-=q[e[i][0].pos].top();q[e[i][0].pos].pop();
				ans+=e[i][0].d;
				q[e[i][0].pos].push(e[i][0].d);
			}
			else {
				ans+=e[i][0]+e[i-1][1];
				cnt[e[i][1]]++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}	  
