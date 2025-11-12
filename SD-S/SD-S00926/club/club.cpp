#include<bits/stdc++.h>
#define ll long long
#define debug cout<<"debug"<<endl;
#define endl '\n'
#define debug_endl cout<<endl;
//#define i128 __int128
//#define MOD (1000000007)
//#define eps (1e-6)
using namespace std;
const int MAXN=1e5+10;
int t;
int n;
ll a[MAXN][4];
int idx[MAXN],cnt[4],now,maxn[MAXN],smaxn[MAXN];
bool cmp(int i,int j){
	return (a[i][maxn[i]]-a[i][smaxn[i]])>(a[j][maxn[j]]-a[j][smaxn[j]]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		ll ans=0;
		for(int i=1;i<=n;++i){
			idx[i]=i;
			maxn[i]=smaxn[i]=0;
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
				if(a[i][smaxn[i]]<=a[i][j]){
					smaxn[i]=j;
				}
				if(a[i][maxn[i]]<=a[i][smaxn[i]]){
					swap(smaxn[i],maxn[i]);
				}
			}
		}
		sort(idx+1,idx+n+1,cmp);
		for(int i=1;i<=n;++i){
			int j=maxn[idx[i]];
			if(cnt[j]==n/2){
				j=smaxn[idx[i]];
			}
			++cnt[j];
			ans+=a[idx[i]][j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
10
2020 14533 18961/ 4428
2423 15344 16322/ 978
1910 6224 16178   9954
2038 9963 19722/  9759
8375 10557 5444   2182
3518 14615 17976/ 3361
6188 13424 16615/ 3191
8769 509 4394     4375
958 3195 9953     6758
16441 5313 10926/ 
*/ 

