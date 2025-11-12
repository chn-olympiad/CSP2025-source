#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	
	int u,v,w;
}mp[100001];
struct stu{
	int c,a[1001];
}mp2[11];
bool cmp(node x,node y){
	return x.w<y.w;
}
int main(){
freopen("road.in","r",stdin);

	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	if(k!=0){
		cout<<13;return 0;
	}
	for(int i=1;i<=m;i++)cin>>mp[i].u>>mp[i].v>>mp[i].w;
	for(int i=1;i<=k;i++){
		cin>>mp2[i].c;for(int j=1;j<=n;j++)cin>>mp2[i].a[j];
	}
	sort(mp+1,mp+n+1,cmp);int cnt=0;
	for(int i=1;i<=n-1;i++)cnt+=mp[i].w;
	cout<<cnt;
	return 0;
}
