#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node1{
	int u;
	int v;
	int w;
}a[1000005];
struct node2{
	int b1,c,d;
}b[15];
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		ans+=a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].b1>>b[i].c>>b[i].d;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
} 
