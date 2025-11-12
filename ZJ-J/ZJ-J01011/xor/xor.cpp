#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],pre[500010];
struct point{
	int l,r;
}ans[500010];
bool cmp(point x,point y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	int cnt=0,anss=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((pre[j]^pre[i-1])==k){
				ans[++cnt].l=i;
				ans[cnt].r=j;
			}
		}
	}
	sort(ans+1,ans+1+cnt,cmp);
	int rr=0;
	for(int i=1;i<=cnt;i++){
		if(ans[i].l>rr){
			anss++;
			rr=ans[i].r;
		}
	}
	cout<<anss;
	return 0;
}
