#include<bits/stdc++.h>
using namespace std;
struct idw{
	int id,data;
};
struct node{
	idw x[4];
	int maxi;
}a[100005];
int t,n,ans,cnt[4];
bool cmp1(node p,node q){
	return p.maxi>q.maxi;
}
bool cmp2(idw p,idw q){
	return p.data>q.data;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cnt[1]=0;
		cnt[2]=0;
		cnt[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x[1].data>>a[i].x[2].data>>a[i].x[3].data;
			a[i].x[1].id=1;
			a[i].x[2].id=2;
			a[i].x[3].id=3;
			sort(a[i].x+1,a[i].x+4,cmp2);
			a[i].maxi=a[i].x[1].data-a[i].x[2].data;
		}
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].x[1].id]<n/2){
				cnt[a[i].x[1].id]++;
				ans+=a[i].x[1].data;
			}
			else if(cnt[a[i].x[2].id]<n/2){
				cnt[a[i].x[2].id]++;
				ans+=a[i].x[2].data;
			}
			else if(cnt[a[i].x[3].id]<n/2){
				cnt[a[i].x[3].id]++;
				ans+=a[i].x[3].data;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}