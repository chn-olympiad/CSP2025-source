#include<bits/stdc++.h>
#define MAXN 100005
#define mod
#define int long long
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<"\n"
#define look_memory cerr<<abs(&M2-&M1)/1024.0/1024.0<<"\n";
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

bool M1;
int T,n,nn;
int a[MAXN][5];
vector<int> vec[5];
priority_queue<int,vector<int>,greater<int> > q;

void clear(){
	for(int i=1;i<=3;i++) vec[i].clear();
	while(!q.empty()) q.pop();
}

bool M2;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int Time=clock();
	T=read();
	while(T--){
		n=read();
		nn=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
			}			
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]) vec[1].push_back(i);
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]) vec[2].push_back(i);
			else vec[3].push_back(i);
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		for(int i=1;i<=3;i++){
			int sz=vec[i].size();
			if(sz>nn){
				for(auto j:vec[i]){
					sort(a[j]+1,a[j]+4);
					q.push(a[j][3]-a[j][2]);
				}
				int num=sz-nn;
				for(int j=1;j<=num;j++){
					int tmp=q.top();
					q.pop();
					ans-=tmp;
				}
			}
		}
		printf("%lld\n",ans);
		clear();
	}
	look_memory;
	look_time;
	return 0;
}
