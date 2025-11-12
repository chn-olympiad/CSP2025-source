#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
const int N=1e5+5;
int n,cnt[4],a[N][3],cho[N];
void solve(){
	cin>>n;
	cnt[0]=cnt[1]=cnt[2]=0;
	ll ans=0;
	rep(i,1,n){
		int mx=0;
		rep(j,0,2)cin>>a[i][j],mx=max(mx,a[i][j]);
		ans+=mx;
		if(a[i][0]==mx)cnt[cho[i]=0]++;
		else if(a[i][1]==mx)cnt[cho[i]=1]++;
		else if(a[i][2]==mx)cnt[cho[i]=2]++;
	}
	int f=-1;
	rep(i,0,2)if(cnt[i]>n/2)f=i;
	if(f==-1)printf("%lld\n",ans);
	else{
		vector<int>num;
		rep(i,1,n)if(cho[i]==f){
			int cmx=0;rep(j,0,2)if(j!=f)cmx=max(cmx,a[i][j]);
			num.push_back(a[i][f]-cmx);
		}
		sort(num.begin(),num.end());
		int l=0;
		while(cnt[f]>n/2){
			ans-=num[l];l++;cnt[f]--;
		}
		printf("%lld\n",ans);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}