#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans=0;
struct node{
	int u,v,w;
}a[2000000];
bool cmp(node a,node b){
	return a.w<=b.w;
}
int b[10005];
int c,z[10005];
int num=0;
void kruscal(){
	for(int i=1;i<=m;i++){
		if(num==n-1){
			return;
		}
		if(b[a[i].u]==b[a[i].v]){
			continue;
		}
		num++;
		ans+=a[i].w;
		for(int j=1;j<=n;j++){
			if(b[j]==b[a[i].u]){
				b[j]=b[a[i].v];
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=n;i++){
		b[i]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>c;
		int flag=0;
		for(int j=1;j<=n;j++){
			cin>>z[j];
			if(z[j]==0){
				flag=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(z[j]!=0){
				m++;
				a[m].u=flag;
				a[m].v=j;
				a[m].w=z[j];
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	kruscal();
	cout<<ans;
	return 0;
}
