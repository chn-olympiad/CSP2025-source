#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr int N = 1e6+5;
int n,m,k;
LL a[N];


int f[N];
int find(int x) {
	if(x==f[x]) return f[x];
	return f[x]=find(f[x]);
}
void merge(int a,int b) {
	int fa=find(a),fb=find(b);
	if(fa!=fb) {
		f[fa]=fb;
	}
}

struct EE{ 
	int from, to;
	LL w;
};
struct Cmp{
	bool operator () (EE ee1,EE ee2) {
		return ee1.w>ee2.w;
	}
};
priority_queue<EE,vector<EE>,Cmp> que;
LL ans=0;
void kru() {
	int cnt=0;
	
	while(!que.empty()) {
		int a = que.top().from,b=que.top().to;
		LL val = que.top().w;
		que.pop();
		if(find(a)==find(b)) continue;
		merge(a,b);
		ans+=val;
		cnt++;
		if(cnt==n-1) {
			return;
		}
		
	}
	
	return;
}

int main() 	{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i;
	if(k==0) {
		for(int i=1;i<=m;i++) {
			int u,v; LL w; scanf("%d %d %lld",&u,&v,&w);
			que.push(EE{u,v,w});

		}
		kru();
		cout<<ans<<endl;	
	} else{
		for(int i=1;i<=m;i++) {
			int u,v;LL w; scanf("%d %d %lld",&u,&v,&w);
			que.push(EE{u,v,w});	
		}
		
		
		for(int i=1;i<=k;i++) {
			int C; scanf("%d" , &C);
			for(int j=1;j<=n;j++) {
				scanf("%lld" , &a[j]);
			}
			for(int j=1;j<=n;j++) {
				for(int kk=1;kk<=n;kk++) {
					if(kk==j) continue;
					LL sum=a[j]+a[kk]+C;
					que.push(EE{j,kk,sum});	
				}
			}
		}
		
		kru();
		cout<<ans<<endl;
		
	}
	
	
	
	return 0;

}
