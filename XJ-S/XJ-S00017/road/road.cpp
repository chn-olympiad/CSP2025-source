#include<bits/stdc++.h>
using namespace std;
long long n,m,k,sum;
bool ct[11];
struct road{
	long long u,v,w;
}r[10001];
struct vtc{
	long long c;
	long long a[10001];
}c[11];
bool cmp(road a,road b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++)cin>>r[i].u>>r[i].v>>r[i].w;
	for(long long i=1;i<=k;i++){
		cin>>c[i].c;
		for(long long j=1;j<=n;j++)cin>>c[i].a[j];
	}
	sort(r+1,r+m+1,cmp);
	for(long long i=1;i<m;i++){
		long long u=r[i].u,v=r[i].v,w=r[i].w,tf=1;
		for(long long j=1;j<=k;j++){
			if(ct[j]&&c[j].a[u]+c[j].a[v]<w){
				sum+=c[j].a[u]+c[j].a[v];
				tf=0;
			}
			else if(!ct[j]&&c[j].a[u]+c[j].a[v]+c[j].c<w){
				sum+=c[j].a[u]+c[j].a[v]+c[j].c;
				ct[j]=1;
				tf=0;
			}
		}
		if(tf)sum+=w;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
