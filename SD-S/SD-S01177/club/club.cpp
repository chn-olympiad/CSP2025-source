#include<bits/stdc++.h>
#define fst ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define int long long 
#define endl '\n'
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N = 1e5+10 , inf = 0x3f3f3f3f3f3f3f3f ;
struct node{
	int x,y,z;
}a[N];
int cnt[4];
int cmax(int x,int y,int z){
	int k=max({x,y,z});
	if(x==k) x=-1;
	else if(y==k) y=-1;
	else z=-1;
	return max({x,y,z});
}
bool cmp(node w,node e){
	return max({w.x,w.y,w.z})-cmax(w.x,w.y,w.z)>max({e.x,e.y,e.z})-cmax(e.x,e.y,e.z);
}
void solve(){
	int n,ans=0;
	cin>>n;
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int k=max({a[i].x,a[i].y,a[i].z});
		if(k==a[i].x){
			if(cnt[1]<n/2) ans+=a[i].x,cnt[1]++;
			else{
				if(a[i].y==cmax(a[i].x,a[i].y,a[i].z)) ans+=a[i].y,cnt[2]++;
				else ans+=a[i].z,cnt[3]++;
			}
		}
		else if(k==a[i].y){
			if(cnt[2]<n/2) ans+=a[i].y,cnt[2]++;
			else{
				if(a[i].x==cmax(a[i].x,a[i].y,a[i].z)) ans+=a[i].x,cnt[1]++;
				else ans+=a[i].z,cnt[3]++;
			}
		}
		else{
			if(cnt[3]<n/2) ans+=a[i].z,cnt[3]++;
			else{
				if(a[i].x==cmax(a[i].x,a[i].y,a[i].z)) ans+=a[i].x,cnt[1]++;
				else ans+=a[i].y,cnt[2]++;
			}
		}
	}
	cout<<ans<<endl;
	
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	fst 
	int T;
	cin>>T;
	while(T--) solve();	
	
	return 0;
}
//  Ren5Jie4Di4Ling5%
