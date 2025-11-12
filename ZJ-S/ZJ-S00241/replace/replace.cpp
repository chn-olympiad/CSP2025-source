#include<bits/stdc++.h>
using namespace std;
int t;
int n,a[5],mr,trn[100005];
long long ans;
int mb[100005][5];
int inthr(int x){
	if(x>3) return x%3;
	return x;
}
void solve(){
	ans=0,mr=0;
	for(int i=1;i<=3;i++) a[i]=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> mb[i][1] >> mb[i][2] >> mb[i][3];
		ans+=max(mb[i][1],max(mb[i][2],mb[i][3]));
		if(mb[i][1]>=mb[i][2]&&mb[i][1]>=mb[i][3]) a[1]++;
		else if(mb[i][1]<=mb[i][2]&&mb[i][2]>=mb[i][3]) a[2]++;
		else a[3]++;
	}
	if(a[1]>n/2) mr=1;
	else if(a[2]>n/2) mr=2;
	else if(a[3]>n/2) mr=3;
	if(mr==0){
		cout << ans << '\n';
		return;
	}int cnt=0;
	for(int i=1;i<=n;i++){
		if(mb[i][mr]<mb[i][inthr(mr+1)]||mb[i][mr]<mb[i][inthr(mr+2)]) continue;
		trn[++cnt]=min(mb[i][mr]-mb[i][inthr(mr+2)],mb[i][mr]-mb[i][inthr(mr+1)]);
	}sort(trn+1,trn+a[mr]+1);
	for(int i=1;i<=a[mr]-(n/2);i++){
		ans-=trn[i];
	}cout << ans << '\n';
	return;
}
int main(){
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
