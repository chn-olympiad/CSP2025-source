#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[114514][5];
int fi[114514];
int se[114514];
struct node{
	int fi,se;
	int dif,i;
}b[114514];
bool cmp(node x,node y){
	return x.dif>y.dif;
}
main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				fi[i]=1;
				if(a[i][2]>=a[i][3])se[i]=2;
				else se[i]=3;
			}
			else if(a[i][2]>=a[i][3]&&a[i][2]>=a[i][1]){
				fi[i]=2;
				if(a[i][1]>=a[i][3])se[i]=1;
				else se[i]=3;
			}
			else{
				fi[i]=3;
				if(a[i][1]>=a[i][2])se[i]=1;
				else se[i]=2;
			}
		}
		for(int i=1;i<=n;i++){
			b[i].fi=fi[i];
			b[i].se=se[i];
			b[i].dif=a[i][fi[i]]-a[i][se[i]];
			b[i].i=i;
//			cout<<b[i].fi<<" "<<b[i].se<<" "<<b[i].dif<<" "<<b[i].i<<endl;
		}
		sort(b+1,b+n+1,cmp);
		int cnt[5]={0,0,0,0};
		int lim=n/2,ans=0;
		for(int i=1;i<=n;i++){
			if(cnt[b[i].fi]>=lim){
				ans+=a[b[i].i][b[i].se];
				cnt[b[i].se]++;
			}
			else{
				ans+=a[b[i].i][b[i].fi];
				cnt[b[i].fi]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//give me 100 pts plz! qwq! 
