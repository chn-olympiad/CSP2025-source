#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1005][1005],c[1005],b[1005][1005];
struct edge {
	long long u,v,w;
} e[3000005],v[3000005];
long long tmp[100005];
long long ku2() {
	long long ans=0,cnt=1;
	memset(tmp,0,sizeof(tmp));
	for(int i=1; cnt<n+k&&i<=m+n*k; i++) {
//		if(i>m&&cnt<n)i=1;
//		cout<<cnt<<" "<<i<<endl;
		if(!tmp[e[i].u]||!tmp[e[i].v]) {
			cnt+=!tmp[e[i].u]+!tmp[e[i].v];
			ans+=e[i].w;
			tmp[e[i].u]=1;
			tmp[e[i].v]=1;
		}
	}
	return ans;
}
bool cmp(edge a,edge b) {
	return a.w<b.w;
}
long long min(long long a,long long b) {
	return a<b?a:b;
}
bool tptp[15];
long long dfs(int step,int sum) {
//	cout<<step<<" "<<sum<<endl;
	if(step>k) {
		for(int i=1; i<=m; i++)e[i].u=v[i].u,e[i].v=v[i].v,e[i].w=v[i].w;
		for(int i=1; i<=k; i++)n+=tptp[i];
		long long cnt=m;
		for(int l=1; l<=k; l++) {
			if(tptp[l]) {
				for(int i=1; i<=n; i++) {
					cnt+=1;
					e[cnt].u=i;
					e[cnt].v=n+l;
					e[cnt].w=a[l][i];
				}
			}
		}
//		for(int i=1; i<=cnt; i++) {
//			cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
//		}
		sort(e+1,e+cnt+1,cmp);
		long long k=ku2()+sum;
		return k;
	}
	long long res=INT_MAX;
	tptp[step]=1;
	res=min(res,dfs(step+1,sum+c[step]));
	tptp[step]=0;
	res=min(res,dfs(step+1,sum));
	return res;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(int i=1; i<=m; i++)v[i].u=e[i].u,v[i].v=e[i].v,v[i].w=e[i].w;
	bool flag=1;
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]!=0)flag=0;
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	if(flag==1) {
		n+=k;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++)b[i][j]=LONG_MAX;
		}
		long long cnt=m;
		for(int l=1; l<=k; l++) {
			for(int i=1; i<=n; i++) {
				cnt+=1;
				e[cnt].u=i;
				e[cnt].v=n+l;
				e[cnt].w=a[l][i];
			}
		}
//		for(int i=1; i<=cnt; i++) {
//			cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
//		}
		sort(e+1,e+cnt+1,cmp);
		long long k=ku2();
		cout<<k;
		return 0;
	}
	cout<<dfs(1,0);
//	sort(e+1,e+m+1,cmp);
//	cout<<ku2(m);
	return 0;
}
