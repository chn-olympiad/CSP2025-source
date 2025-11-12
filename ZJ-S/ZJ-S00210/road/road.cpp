#include <bits/stdc++.h>
using namespace std;
long long n,m,k,i,x,y,z,s,t,w,ans,fx,fy,b[1010][1010],f[100010],j,c[100010];
struct no{
	int x,y,z;
}a[100010];
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
bool cmp(no q,no h){
	return q.z<h.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[++t].x=x;a[t].y=y;a[t].z=z;
	}
	for(i=1;i<=k;i++)
		for(j=1;j<=n+1;j++){
			if(j==1) cin>>c[j],s+=c[j];
			else cin>>b[j][++w],s+=b[j][w];
		}
	sort(a+1,a+1+t,cmp);
	for(i=1;i<=n;i++){
		x=a[i].x;y=a[i].y;z=a[i].z;
		fx=find(x);fy=find(y);
		if(fx!=fy){
			f[fy]=fx;ans+=z;
		}
		sort(a+1,a+1+t,cmp);
	}
	if(s==0&&k!=0){
		cout<<0;return 0;
	}
	cout<<ans;
	return 0;
}

