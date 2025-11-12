#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int u,v,w;
}a[100000];
bool cmp(node q,node p){
	return q.w<p.w;
}
int t[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+1+m,cmp);
	int sum=0;
	for(int i=1;i<=m;i++){
		int f=0;
		t[a[i].v]=1,t[a[i].u]=1;
		sum+=a[i].w;
		for(int j=1;j<=n;j++){
			if(t[j]==0)f=1;
		}
		if(f==1){
			cout<<sum;
			return 0;
		}
	}
	return 0;
} 
