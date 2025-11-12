#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int t,n,a[N][5],b[N];
long long ans;
void dfs(int x,int cnt1,int cnt2,int cnt3,long long sum){
	if (!(cnt1<=(n/2)&&cnt2<=(n/2)&&cnt3<=(n/2))) return;
	if (x==(n+1)){
		if (cnt1<=(n/2)&&cnt2<=(n/2)&&cnt3<=(n/2)) ans=max(ans,sum);
		return;
	}
	dfs(x+1,cnt1+1,cnt2,cnt3,sum+a[x][1]);
	dfs(x+1,cnt1,cnt2+1,cnt3,sum+a[x][2]);
	dfs(x+1,cnt1,cnt2,cnt3+1,sum+a[x][3]);
	return;
}
bool px(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
		}
		if (n>30){
			sort(b+1,b+1+n,px);
			long long sum=0;
			for (int i=1;i<=n/2;i++){
				sum+=b[i];
			}
			cout<<sum<<"\n";
			return 0;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}