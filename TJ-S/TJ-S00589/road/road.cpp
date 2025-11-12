#include<bits/stdc++.h>
using namespace std;
struct ab{
	int a1,a2,pay;
}a[1000005];
bool cmp(ab x,ab y){
	return x.pay<y.pay;
}
bool ans[10005][10005]={0};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long cu=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].pay;
	}
	sort(a+1,a+1+m,cmp);
	int need=0;
	for(int i=1;i<=m;i++){
		if(ans[a[i].a1][a[i].a2]==1) continue;
		cu+=a[i].pay;
		ans[a[i].a1][a[i].a2]=1;
		ans[a[i].a2][a[i].a1]=1;
	}
	cout<<cu;
	return 0;
}
