#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[120005][5],ans,cnt[120005],mx,ma[120005],mai[120005],deltai[120005][2],b[5];
pair <int,int> kk[5];
pair <int,int> k[120005];
bool cmp1(pair<int,int> aa, pair<int,int> bb){
	return aa.first>bb.first;
}
bool cmp2(pair<int,int> aa,pair<int,int> bb){
	return aa.second<bb.second;
}
void miin(){
	cin>>n;
	mx=n/2;
	ans=0;
	for (int i=1;i<=3;i++) {
		mai[i]=0;
	}
	for(int i=1;i<=n;i++){
		cnt[i]=0;
		for (int j=1;j<=3;j++){
			cin>>a[i][j];
			pair <int,int> p;
			p=make_pair(a[i][j],j);
			kk[j]=p;
		}
		sort(kk+1,kk+4,cmp1);
		ma[i]=kk[1].first;
		k[i].second=kk[1].first-kk[2].first;
		k[i].first=kk[1].second;
		mai[kk[1].second]++;//max i
	}
	sort(k+1,k+n+1,cmp2);
	for (int i=1;i<=n;i++){
		ans+=ma[i];
	}
	for (int i=1;i<=3;i++){
		if (mai[i]>mx){
			int p=1;
			for (int j=1;j<=mai[i]-mx;){
				if (k[p].first==i){
					j++;
					ans-=k[p].second;
				}p++;
			}
			break;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while (T--){
		miin();
	}
	return 0;
} 
