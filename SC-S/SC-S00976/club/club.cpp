#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll t,n;
ll ans,cnt1 = 1,cnt2 = 1,cnt3 = 1,n1 = 1,n2 = 1,n3 = 1;
pair<int,int> a[N],b[N],c[N];
bool vis[N],flg1,flg2,flg3;
bool cmp(pair<int,int> x,pair<int,int> y){
	if(x.first == y.first) return x.second < y.second;
	return x.first > y.first;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans = 0;
		cnt1 = cnt2 = cnt3 = 1;
		n1 = n2 = n3 = 1;
		flg1 = flg2 = flg3 = 1;
		for(int i = 1;i <= n;i++){
			vis[i] = 0;
			cin>>a[i].first>>b[i].first>>c[i].first;
			a[i].second = b[i].second = c[i].second = i;
		}
		sort(a+1,a+n+1,cmp);sort(b+1,b+n+1,cmp);sort(c+1,c+n+1,cmp);
		while(cnt1 + cnt2 + cnt3 - 3 <= n && (flg1 || flg2 || flg3)){
			while(cnt1 + cnt2 + cnt3 - 3 <= n && (flg1 || flg2 || flg3)){
				if(n1 >= n) flg1 = 0;
				if(n2 >= n) flg2 = 0;
				if(n3 >= n) flg3 = 0;
				if(a[n1].first >= b[n2].first && a[n1].first >= c[n3].first && flg1){
					if(cnt1 > n/2){
						flg1 = 0;
						continue;
					}
					else if(vis[a[n1].second]){
						n1++;
						continue;
					}
					else{
						ans += a[n1].first;
						vis[a[n1].second] = 1;
						cnt1++;n1++;
						break;
					}
				}
				else if(b[n2].first >= a[n1].first && b[n2].first >= c[n3].first && flg2){
					if(cnt2 > n/2){
						flg2 = 0;
						continue;
					}
					else if(vis[b[n2].second]){
						n2++;
						continue;
					}
					else{
						ans += b[n2].first;
						vis[b[n2].second] = 1;
						cnt2++;n2++;
						break;
					}
				}
				else{
					if(cnt3 > n/2){
						flg3 = 0;
						continue;
					}
					else if(vis[c[n3].second]){
						n3++;
						continue;
					}
					else{
						ans += c[n3].first;
						vis[c[n3].second] = 1;
						cnt3++;n3++;
						break;
					}
				}
			}
			//cout<<ans<<endl;
			//cout<<cnt1<<" "<<cnt2<<" "<<cnt3<<endl;
			//cout<<n1<<" "<<n2<<" "<<n3<<endl;
			if(cnt1 + cnt2 + cnt3 - 3 >= n) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}