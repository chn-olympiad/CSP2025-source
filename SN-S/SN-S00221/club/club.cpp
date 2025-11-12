#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e5+10;
int t,n,ans;
struct rd{
	int val,id;
};
struct node{
	rd pm[4];
	int cs_id;
}a[MAXN];
bool cmp(node a,node b){
	return a.pm[1].val-a.pm[2].val>b.pm[1].val-b.pm[2].val;
}
bool cmp1(rd a,rd b){
	return a.val>b.val;
}
int sum[5];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].pm[1].val>>a[i].pm[2].val>>a[i].pm[3].val;
			a[i].pm[1].id=1,a[i].pm[2].id=2,a[i].pm[3].id=3;
			sort(a[i].pm+1,a[i].pm+3+1,cmp1);
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
//			cout<<a[i].pm[1].val<<" ";
			if(sum[a[i].pm[1].id]<n/2){
//				cout<<"fst\n";
				sum[a[i].pm[1].id]++;
				ans+=a[i].pm[1].val;
			}
			else{
//				cout<<"scd\n";
				sum[a[i].pm[2].id]++;
				ans+=a[i].pm[2].val;
			}
		}
		cout<<ans<<"\n";
		sum[1]=sum[2]=sum[3]=0;
	}
	return 0;
}
