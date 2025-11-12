#include<bits/stdc++.h>
using namespace std;
struct Node{
	int v[5]={0},maxval=0,cnt0=0;
}a[100005];
bool cmp(Node x,Node y){
	if(x.cnt0!=y.cnt0) return x.cnt0>y.cnt0;
	return x.maxval>y.maxval;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int q=1;q<=t;q++){
		int n;
		vector<int> d(4);
		cin>>n;
		for(int i=1;i<=n;i++){
			int maxx=-1,cnt=0;
			for(int j=1;j<=3;j++){
				cin>>a[i].v[j];
				cnt+=a[i].v[j]==0;
				maxx=max(a[i].v[j],maxx);
			}
			a[i].cnt0=cnt;
			a[i].maxval=maxx;
		}
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		for(int i=1;i<=n;i++){
			int maxj,maxx=-1;
			for(int j=1;j<=3;j++){
				if(a[i].v[j]>maxx&&d[j]<(n/2)){
					maxx=a[i].v[j];
					maxj=j;
				}
			}
			d[maxj]++;
			ans+=maxx;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//这个是club2的第一个小测试 
//1
//10
//2020 14533 18961
//2423 15344 16322
//1910 6224 16178
//2038 9963 19722
//8375 10557 5444
//3518 14615 17976
//6188 13424 16615
//8769 509 4394
//958 3195 9953
//16441 5313 10926



//10
//2038 9963 19722
//2020 14533 18961
//3518 14615 17976
//16441 5313 10926
//6188 13424 16615

//2423 ,15344, .16322.<---
//1910 .6224. ,16178,<---

//8375 10557 5444
//958 3195 9953
//8769 509 4394

