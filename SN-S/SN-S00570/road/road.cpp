#include<bits/stdc++.h>
using namespace std;
struct f{
	int u,v,w;
}a[1100000];
bool cmp(f x,f y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","r",stdout);
	int n,m,k,ans=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		for(int j=0;j<n;j++){
			int d;
			cin>>d;
		}
	}
	sort(a,a+m,cmp);
	for(int i=0;i<n-1;i++){
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}

