#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int t,n,a[maxn][5],cnt[5],ans,b[5][maxn];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t ;
	while(t--){
		cin >> n ;
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		for(int i=1;i<=n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3] ;
		for(int i=1;i<=n;i++){
			int mx=-1,idx=0,tmp=-1;
			if(a[i][1]>mx) mx=a[i][1],idx=1;
			if(a[i][2]>mx) mx=a[i][2],idx=2;
			if(a[i][3]>mx) mx=a[i][3],idx=3;
			if(idx!=1) tmp=max(tmp,a[i][1]);
			if(idx!=2) tmp=max(tmp,a[i][2]);
			if(idx!=3) tmp=max(tmp,a[i][3]);
			b[idx][++cnt[idx]]=mx-tmp,ans+=mx;
//			cout << " " << b[idx][++cnt[idx]] << " " << idx << "\n" ;
		}if(max({cnt[1],cnt[2],cnt[3]})>n/2){
			int tmp=0;
			if(cnt[1]>n/2) tmp=1;
			if(cnt[2]>n/2) tmp=2;
			if(cnt[3]>n/2) tmp=3;
//			cout << "k" << tmp << " " << ans << " " << cnt[tmp] << "\n" ;
//			for(int i=1;i<=cnt[tmp];i++) cout << " " << b[tmp][i] ;
			sort(b[tmp]+1,b[tmp]+cnt[tmp]+1);
			for(int i=1;i<=cnt[tmp]-n/2;i++) ans-=b[tmp][i];
//			cout << "\n" ;
		}cout << ans << "\n" ;
	}return 0;
}

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
//
//
//3 2 3 3 2 3 2 1 3 1
//3 3 3 3 2 3 3 1 3 1
