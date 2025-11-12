#include<bits/stdc++.h>
using namespace std;
int m,n,k;
struct node{
	int v1,v2,w;
}a[10001];
bool cmp(node e,node f){
	return e.w<f.w;
}
bool t[10001];
struct ne{
	int c,b;
}x[10001];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].v1>>a[i].v2>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>x[i].b;
		for(int j=1;j<=m;j++){
			cin>>x[i].c;
		}
	}
	sort(a+1,a+1+n,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(t[i]==false){
			ans+=a[i].w;
			t[a[i].v1]=true;
			t[a[i].v2]=true;
		}
	}
	cout<<ans<<endl;
	return 0;
}
