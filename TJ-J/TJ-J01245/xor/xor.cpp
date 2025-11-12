#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
const int N=5e5+5;
const ll inf=LONG_LONG_MAX;
int a[N];
pii st[N*2];
ll r=0,ans=0;
bool cmp(pii q,pii w){
	if(q.second==w.second) return q.first>w.first;
	return q.second>w.first;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//don't forget to delete the '//' 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int xr=a[i];
		if(xr==k){
			st[++r]={i,i};
		}
		for(int j=i+1;j<=n;j++){
			xr^=a[j];
			if(xr==k){
				st[++r]={i,j};
			}
		}
	}
	sort(st+1,st+r+1,cmp);
	/*for(int i=1;i<=r;i++){
		cout<<st[i].first<<" "<<st[i].second<<endl;
	}*/
	ll nowr=inf;
	for(int i=1;i<=r;i++){
		if(st[i].second<nowr){
			nowr=st[i].first;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
