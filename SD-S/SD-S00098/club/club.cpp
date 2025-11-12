#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
struct e{
	int x,i;
};
struct node{
	e x[3];
}a[100010];
bool cmp1(e x,e y){
	return x.x>y.x;
}
bool cmp(node x,node y){
	return x.x[1].x-x.x[2].x>y.x[1].x-y.x[2].x;
}
int cnt[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].x[j].x;
				a[i].x[j].i=j;
			}
			sort(a[i].x+1,a[i].x+4,cmp1);
		}
		sort(a+1,a+n+1,cmp);
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int now=a[i].x[j].i;
				if(cnt[now]+1<=n/2){
					ans+=a[i].x[j].x;
					cnt[now]++;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
