#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re register
const int maxn=1e5+10;
int n;
int a[maxn][5];
int mx[maxn],mx2[maxn];
ll ans;
pair<int,int>b[maxn];
int num[5];
inline void solve(){
	cin>>n;
	ans=num[1]=num[2]=num[3]=0;
	for(int i=1;i<=n;++i){
		mx[i]=mx2[i]=0;
		for(int j=1;j<=3;++j){
			cin>>a[i][j];
			if(a[i][j]>a[i][mx[i]]){
				mx2[i]=mx[i];
				mx[i]=j;
			}else if(a[i][j]>a[i][mx2[i]]){
				mx2[i]=j;
			}
		}
		b[i].first=a[i][mx[i]]-a[i][mx2[i]];
		b[i].second=mx[i];
		ans+=a[i][mx[i]];
		++num[mx[i]];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i){
		if(num[b[i].second]>(n>>1)){
			--num[b[i].second];
			ans-=b[i].first;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}
/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

147325
*/