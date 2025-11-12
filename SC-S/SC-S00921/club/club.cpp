#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=1e5+100;
ll n,ans,cnt[10],id;
struct psn{
	int max1,max2,to;
}a[N];
priority_queue <int,vector<int>,greater<int>> q;
int T;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		ans=id=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int k;
				cin>>k;
				if(k>a[i].max1){
					a[i].max2=a[i].max1;
					a[i].max1=k;
					a[i].to=j;
				}else if(k>a[i].max2) a[i].max2=k;
			}
			ans+=a[i].max1;
			cnt[a[i].to]++;
		}
		for(int i=1;i<=3;i++) if(cnt[i]*2>n) id=i;
		if(!id) cout<<ans<<'\n';
		else{
			priority_queue <int,vector<int>,greater<int>> emp;
			swap(emp,q);
			for(int i=1;i<=n;i++){
				if(a[i].to==id){
					q.push(a[i].max1-a[i].max2);
				}
			}
			int k=cnt[id]-(n/2);
			for(int i=1;i<=k;i++){
				ans-=q.top();
				q.pop();
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
2
10 9 8
4 0 0
*/
