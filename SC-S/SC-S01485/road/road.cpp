#include<bits/stdc++.h>
using namespace std;
struct st{
	int u,v;
	long long w;
};
int cmp(st p1,st p2){
	return p1.w<p2.w;
}
int f[10015];
int find(int x){
	if(x!=f[x]){
		f[x]=find(f[x]);
	}
	return f[x];
}
void merge(int x,int y){
	x=find(x);
	y=find(y);
	f[y]=f[x];
	return;
}
st a[1100005];
long long kx[11][10005]; 
int main(){
	freopen("road.in","r",stdin);
		freopen("road.out","w",stdout);
	int n,m,k,xa=0;
	for(int i=1;i<=10014;i++){
		f[i]=i;
	}
	cin>>n>>m>>k;
	int n0=n;
	for(int i=1;i<=n;i++){
		cin>>a[m].u>>a[m].v>>a[m].w;
	}
//	cout<<"!";
	for(int i=1;i<=k;i++){
		cin>>kx[i][0];
		if(kx[i][0]!=0){
			xa=1;
		}
		for(int j=1;j<=n;j++){
			cin>>kx[i][j];
		}
	}
//	cout<<"!";
	if(xa==0){
	//	cout<<"!";
		long long ansa=0;
		for(int i=1;i<=k;i++){
			n++;
			for(int j=1;j<=n0;j++){
				m++;
				a[m].u=n;
				a[m].v=i;
				a[m].w=kx[i][j];
			}
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			if(find(a[i].u)!=find(a[i].v)){
				merge(a[i].u,a[i].v);
				ansa+=a[i].w;
			}
		}
		cout<<ansa;
		return 0;
	}
//	cout<<"!";
	return 0;
}