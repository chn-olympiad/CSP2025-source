#include<bits/stdc++.h>
#define ll long long
#define fi fisrt
#define se second
#define pi pair
//recall.cpp
//#define ll bong bong

using namespace std;
const ll N=200005;
const ll inf=1e18;
ll n;
ll cnt[N];
ll p[N][5];
vector<ll>v[5];
void sol(){
	cin>>n;
	v[1].clear();
	v[2].clear();
	v[3].clear();
	cnt[1]=cnt[2]=cnt[3]=0;
	ll res=0;
	for(int i=1;i<=n;i++){
		cin>>p[i][1]>>p[i][2]>>p[i][3];
		if(p[i][3]>=p[i][2]&&p[i][3]>=p[i][1]){
			cnt[3]++;
			res+=p[i][3];
			v[3].push_back(max(p[i][1],p[i][2])-p[i][3]);
		}
		else if(p[i][2]>=p[i][3]&&p[i][2]>=p[i][1]){
			cnt[2]++;
			res+=p[i][2];
			v[2].push_back(max(p[i][1],p[i][3])-p[i][2]);
		}
		else{ 
			cnt[1]++;
			res+=p[i][1];
			v[1].push_back(max(p[i][2],p[i][3])-p[i][1]);
		}
	}
	sort(v[1].begin(),v[1].end(),[&](const ll a,const ll b){
		return a>b;
	});
	sort(v[2].begin(),v[2].end(),[&](const ll a,const ll b){
		return a>b;
	});
	sort(v[3].begin(),v[3].end(),[&](const ll a,const ll b){
		return a>b;
	});
	ll m=(n+1)>>1;
	ll t=0;
	while(cnt[1]>m){
		cnt[1]--;
		res+=v[1][t];
		t++;
	}
	while(cnt[2]>m){
		cnt[2]--;
		res+=v[2][t];
		t++;
	}
	while(cnt[3]>m){
		cnt[3]--;
		res+=v[3][t];
		t++;
	}
	cout<<res<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll ttt;
	cin>>ttt;
	for(int i=1;i<=ttt;i++)sol();
	return 0;
}