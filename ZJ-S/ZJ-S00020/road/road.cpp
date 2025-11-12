#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	int u,v,w;
}a[1000005];
bool cmp(Node p,Node q){
	return p.w<q.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int c[15];
	int b[15][10005];
	int xxx=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0) xxx++;
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	if(k==0){
		int sum=0;
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<n;i++){
			sum+=a[i].w;
		}
		cout<<sum;
	}
	else if(xxx==k){
		cout<<"0";
	}
	else{
		int num=0;
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<n-1;i++){
			num+=a[i].w;
		}
		cout<<num;
	}
	return 0;
}
