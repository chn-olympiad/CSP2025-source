#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
constexpr int N=1e5+10;using namespace std;void solve();
int n,A[N][4],arr[N],cnt[4],tot,tmp[N],ans;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
void solve(){
	cin>>n;
	forUp(i,1,n)cin>>A[i][1]>>A[i][2]>>A[i][3];
	ans=cnt[1]=cnt[2]=cnt[3]=0;
	forUp(i,1,n){
		int id=0;
		forUp(j,1,3)if(A[i][j]>=A[i][id])id=j;
		ans+=A[i][id];
		++cnt[id],arr[i]=id;
	}
	int id=0;
	forUp(i,1,3)if(cnt[i]>=cnt[id])id=i;
	if(cnt[id]>n/2){
		tot=0;
		forUp(i,1,n)if(arr[i]==id){
			int cur=0;
			forUp(j,1,3){
				if(j==arr[i])continue;
				if(A[i][j]>=A[i][cur])cur=j;
			}
			tmp[++tot]=A[i][arr[i]]-A[i][cur];
		}
		sort(tmp+1,tmp+tot+1);
		forUp(i,1,cnt[id]-n/2)ans-=tmp[i];
	}
	cout<<ans<<'\n';
}