#include <bits/stdc++.h>
using namespace std;
int f[100010],ffy[100010],ans,t,m,i,j,k,fx,fy,n,x;
struct no{
	int x,y,z;
}a[2000010];
int find(int x){
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
bool cmp(no q,no h){return q.z<h.z;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n+k;i++) f[i]=i;
	for(i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	for(i=1;i<=k;i++){
		cin>>x;
		for(j=1;j<=n;j++) scanf("%d",&ffy[j]);
		for(j=1;j<=n;j++)
			for(k=1;k<=n;k++)
				a[++m].x=j,a[m].y=k,a[m].z=x+ffy[j]+ffy[k]+x;
	}
	sort(a+1,a+m+1,cmp);
	for(i=1;i<=m;i++){
		fx=find(a[i].x);fy=find(a[i].y);
		if(fx!=fy){
			t++;
			f[fy]=fx;
			ans+=a[i].z;
			if(t==n) break;
		}
	}
	printf("%d",ans);
	return 0;
}

//32+ TLE and WA
