#include <bits/stdc++.h>
using namespace std;
long long n,m,k,i,x,y,z,t,g[20],j,f[10010],ert,sl[10010];
struct no{
	long long x,y,z,er;
}a[1100010];
bool cmp(no q,no h){
	return q.z<h.z;
}
int find(int w){
	if(f[w]!=w) f[w]=find(f[w]);
	return f[w];
}
int pd(){
	long long i,k=0,tot=0;
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=t;i++)
		if(find(a[i].x)!=find(a[i].y)&&a[i].er==0){
			tot+=a[i].z;
			k++;
			f[find(a[i].x)]=find(a[i].y);
			if(k==n-1) break;
		}
	return tot;
}
int pd2(){
	long long i,k=0,tot=0;
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=t;i++)
		if(find(a[i].x)!=find(a[i].y)||a[i].x==a[i].y&&a[i].er==1){
			if(a[i].er==1)
				if(sl[a[i].x]==0) sl[a[i].x]=1,k--;
				else tot-=g[a[i].x];
			tot+=a[i].z;
			k++;
			if(k==n-1) break;
		}
		return tot;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		++t,a[t].x=x,a[t].y=y,a[t].z=z;
	}
	for(i=1;i<=k;i++){
		cin>>g[i];
		for(j=1;j<=n;j++)
			cin>>x,++t,a[t].x=i,a[t].y=j,a[t].z=g[i]+x,a[t].er=1;
	}
	sort(a+1,a+1+t,cmp);
	cout<<min(pd(),pd2());
	return 0;
}
