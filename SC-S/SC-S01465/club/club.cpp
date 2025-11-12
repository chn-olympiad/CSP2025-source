#include<queue>
#include<iostream>
#define int long long
using namespace std;
const int N=2e5+5;
int t,n,ans,tot,cnt[4],A[N],B[N],C[N],id[N];
priority_queue<int> pro;
void solve(){
	cin>>n;cnt[1]=cnt[2]=cnt[3]=tot=ans=0;
	for(int i=1;i<=n;i++) A[i]=B[i]=C[i]=id[i]=0;
	while(!pro.empty()) pro.pop();
	for(int i=1;i<=n;i++) cin>>A[i]>>B[i]>>C[i];
	for(int i=1;i<=n;i++){
		int maxn=max(max(A[i],B[i]),C[i]);
		if(maxn==A[i]) cnt[1]++,id[i]=1,ans+=A[i];
		else if(maxn==B[i]) cnt[2]++,id[i]=2,ans+=B[i];
		else if(maxn==C[i]) cnt[3]++,id[i]=3,ans+=C[i];
	}
	if(cnt[1]>n/2){
		tot=cnt[1]-n/2;
		for(int i=1;i<=n;i++){
			if(id[i]==1) pro.push(-min(A[i]-B[i],A[i]-C[i]));
		}
	}
	if(cnt[2]>n/2){
		tot=cnt[2]-n/2;
		for(int i=1;i<=n;i++){
			if(id[i]==2) pro.push(-min(B[i]-A[i],B[i]-C[i]));
		}
	}
	if(cnt[3]>n/2){
		tot=cnt[3]-n/2;
		for(int i=1;i<=n;i++){
			if(id[i]==3) pro.push(-min(C[i]-A[i],C[i]-B[i]));
		}
	}
//	cout<<"?"<<tot<<endl; 
	while(tot){
		int x=pro.top();pro.pop();
		ans+=x;tot--;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;while(t--) solve();
	return 0;
}