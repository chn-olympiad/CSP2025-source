#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
	long long w;
};
node a[20000100];
int n,m,k,c,x,b[2001010];
bool flag[2000100],csp;
long long sum,cnt;
bool cmp(node aa,node bb){
	return aa.w<bb.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	if(k) csp=1;
	for(int i=1;i<=k;i++){
		cin>>c;
		if(c!=0) csp=0;
		for(int j=1;j<=n;j++){
			cin>>b[j];
			if(b[j]!=0){
				csp=0;
			}
		}
		for(int j=1;j<n;j++){
			for(int jj=j+1;jj<=n;jj++){
				a[++m].x=j;
				a[m].y=jj;
				a[m].w=c+b[jj]+b[j];
			}
		}
	}
	if(csp==1){
		cout<<0;
		return 0;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(flag[a[i].x]==1&&flag[a[i].y]==1) continue;
		flag[a[i].x]=1;
		flag[a[i].y]=1;
		sum+=a[i].w;
		cnt++;
		if(cnt==n-1) break;
	}
	cout<<sum;
	return 0;
}
