#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=500005;
ll n,k,a[maxn],pre[maxn],suf[maxn];

struct node{
	int x,y;
	bool operator < (const node&ts) const{
		if(y!=ts.y)
			return y<ts.y;
		return x<ts.x;
	}
};
void solve(){
	memset(pre,0,sizeof pre);
	memset(suf,0,sizeof suf);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	pre[1]=a[1];
	for(int i=2;i<=n;i++)
		pre[i]=pre[i-1]^a[i];
	suf[n]=a[n];
	for(int i=n-1;i>=1;i--)
		suf[i]=suf[i+1]^a[i];
	vector <node> s;
	for(int i=1;i<=n;i++){
		ll x=pre[i-1],y,cnt;
		for(int j=i;j<=n;j++){
			y=suf[j+1];
			cnt=x^y^k;
			if(cnt==pre[n]){
				s.push_back({i,j});	
			}
		}
	}
	sort(s.begin(),s.end());
	int now_left=-1,ans=0;
	for(auto i:s){
		if(i.x>now_left){
			ans++;
			now_left=i.y;
		}
	}
	cout<<ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int T=1;
	while(T--)
		solve();

	return 0;
}

