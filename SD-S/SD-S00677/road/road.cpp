#include<bits/stdc++.h>
using namespace std;
struct sides{
	int u;
	int v;
	int w;
	int village;
};
bool bj(sides a,sides b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int cities[n+1];
	int villages[k];
	bool vil[k]={0};
	for(int i=0;i<n;i++){
		cities[i+1]=i+1;
	}
	sides roads[m+k*n*(n-1)/2];
	for(int i=0;i<m;i++){
		cin>>roads[i].u>>roads[i].v>>roads[i].w;
		roads[i].village=-1;
	}
	int cnt=m;
	for(int i=0;i<k;i++){
		int c,a[n+1];
		cin>>c;
		villages[i]=c;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				roads[cnt].u=j;
				roads[cnt].v=k;
				roads[cnt].w=a[j]+a[k]+c;
				roads[cnt].village=i;
				cnt++;
			}
		}
	}
	sort(roads,roads+cnt,bj);//											1
	int ans=0; 
	for(int i=0;i<cnt;i++){
		int a=roads[i].u,b=roads[i].v;
		while(a!=cities[a]){
			a=cities[a];
		}
		while(b!=cities[b]){
			b=cities[b];
		}
		if(a!=b){
			cities[b]=a;
			ans+=roads[i].w;
			if(roads[i].village!=-1){
				ans-=villages[roads[i].village]*vil[roads[i].village];
				vil[roads[i].village]=1;
			}
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

