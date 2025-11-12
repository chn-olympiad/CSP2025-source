#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5; 
int t,n,cnt[3];
pair<int,int> tmp[N];
struct node{
	int val,type;
	inline bool operator < (const node &rhs) const {
		return val>rhs.val;
	}
}a[N][3];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<3;j++){
			cin>>a[i][j].val;
			a[i][j].type=j;
		}
	int lim=n/2;
	for(int i=1;i<=n;i++)
		sort(a[i],a[i]+3);

	int ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i][0].val;
		cnt[a[i][0].type]++;
	}
	bool ok=1;
	int tar;
	for(int i=0;i<3;i++)
		if(cnt[i]>lim) tar=i,ok=0;
	if(ok) {
		cout<<ans<<'\n';
		return;
	}
	//第tar号社团超过了n/2个，需要更换为其他的社团 
	int tot=0;
	for(int i=1;i<=n;i++)
		if(a[i][0].type==tar)
			tmp[++tot]={a[i][0].val-a[i][1].val,a[i][1].type};
	sort(tmp+1,tmp+1+tot);
	int dag=cnt[tar]-lim; //超过了dag个 
	for(int i=1;i<=dag;i++){
		cnt[tar]--;
		ans-=tmp[i].first;
		cnt[tmp[i].second]++;
	}
	ok=1;
	for(int i=0;i<3;i++)
		if(cnt[i]>lim) tar=i,ok=0;
	if(ok){
		cout<<ans<<'\n';
		return;
	}
	tot=0;
	dag=cnt[tar]-lim;
	for(int i=1;i<=n;i++)
		if(a[i][1].type==tar)
			tmp[++tot]={a[i][1].val-a[i][2].val,a[i][2].type};
	sort(tmp+1,tmp+1+tot);
	for(int i=1;i<=dag;i++)
	{
		cnt[tar]--;
		ans-=tmp[i].first;
		cnt[tmp[i].second]++;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--) solve();
	return 0;
}
