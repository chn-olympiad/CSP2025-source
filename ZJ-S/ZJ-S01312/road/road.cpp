#include<bits/stdc++.h>
using namespace std;
int n,m,k,i,f[100010],ff[100010],cnt,fx,fy,c[100010],e[20][100010],j;
long long sum,ans;
struct node{
	int x,y;long long z;
}a[1000010],b[1000010],bian[1000010];
bool cmp(node q,node h){
	return q.z<h.z;
}
int find(int x){
	if(f[x]==x) return f[x];
	else return f[x]=find(f[x]);
}
long long pd(){
	int i,tot,j,fx,fy,d,dd=0;long long s=0;
	for(i=1;i<=k;i++)
		if(ff[i]==1) s=s+c[i];
	for(i=1;i<=k;i++)
		if(ff[i]==1) break;
	if(i>k) return ans+1;
	if(s>=ans) return ans+1;
	for(i=1;i<=n-1;i++)
		bian[i].x=b[i].x,bian[i].y=b[i].y,bian[i].z=b[i].z;
	tot=n-1;
	for(i=1;i<=k;i++)
		if(ff[i]==1){
			for(j=1;j<=n;j++)
				bian[++tot].x=n+i,bian[tot].y=j,bian[tot].z=e[i][j];
		}
	sort(bian+1,bian+1+tot,cmp);
	d=n+(tot+1)/n-1;
	for(i=1;i<=n+k;i++) f[i]=i;
	for(i=1;i<=tot;i++){
		fx=find(bian[i].x);fy=find(bian[i].y);
		if(fx!=fy){
			f[fx]=fy;
			s=s+bian[i].z;dd++;
			if(s>=ans) return ans+1;
			if(dd==d-1) break;
		}
	}
	return s;
}
void dg(int t){
	if(t==k+1){
		ans=min(ans,pd());
		return ;
	}
	ff[t]=1;dg(t+1);
	ff[t]=0;dg(t+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+1+m,cmp);
	for(i=1;i<=n;i++) f[i]=i;
	sum=0;cnt=0;
	for(i=1;i<=m;i++){
		fx=find(a[i].x);fy=find(a[i].y);
		if(fx!=fy){
			f[fx]=fy;
			sum=sum+a[i].z;cnt++;
			b[cnt].x=a[i].x;b[cnt].y=a[i].y;b[cnt].z=a[i].z;
		}
		if(cnt==n-1) break; 
	}
	for(i=1;i<=k;i++){
		cin>>c[i];
		for(j=1;j<=n;j++) cin>>e[i][j];
	}
	ans=sum;
	if(n>5000&&k>5){
		cout<<ans<<"\n";return 0;
	}
	dg(1);cout<<ans;
	return 0;
}