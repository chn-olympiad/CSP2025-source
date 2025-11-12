#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T;
int n,a[10];
vector<pair<int ,int > > c[10];
int sum,cnt[10],st[N];
void work(int i,int x){
	if(a[x]>a[(x)%3+1]&&a[x]>a[(x+1)%3+1]){
		sum+=a[x];++cnt[x];
		st[i]=x;
		c[x].push_back({a[x]-a[(x)%3+1] , i});
		c[x].push_back({a[x]-a[(x+1)%3+1] , i});
	}
}
void go_on(int x){
	sort(c[x].begin(),c[x].end());
	for(auto k:c[x]){
		if(st[k.second]!=x)continue;
		sum-=k.first;
		st[k.second]=-1;
		--cnt[x];
		if( cnt[x]<=n/2 )return ;
	}
}
void solve(){
	cin>>n;
	c[1].clear();c[2].clear();c[3].clear();
	for(int i=1;i<=n;i++)st[i]=0;
	sum=cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		cin>>a[1]>>a[2]>>a[3];
		if((a[1]==a[2]&&a[1]>a[3])||(a[2]==a[3]&&a[2]>a[1])||(a[1]==a[3]&&a[1]>a[2])){
			sum+=max( a[1],max( a[2],a[3] ) );
		}else work(i,1),work(i,2),work(i,3);
	}
	if(cnt[1]>n/2)go_on(1);
	else if( cnt[2]>n/2 )go_on(2);
	else if( cnt[3]>n/2 )go_on(3);
	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)solve();
	return 0;
}
/*
±¨¡—∞…, real!
∑€ÀÈ∞…, synapse!
Vanishment this world!
*/
