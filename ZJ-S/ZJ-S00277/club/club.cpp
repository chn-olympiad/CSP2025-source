#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[100050][4],s[4],ss,maxx,c[100050],v[100050];
vector<ll> b[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll _;
	cin>>_;
	while(_--){
		cin>>n;
		ss=s[1]=s[2]=s[3]=0;
		b[1].clear();
		b[2].clear();
		b[3].clear();
		ll i;
		for(i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))) s[1]++,b[1].push_back(i);
			else if(a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))) s[2]++,b[2].push_back(i);
			else  s[3]++,b[3].push_back(i);
			ss+=max(a[i][1],max(a[i][2],a[i][3]));
			c[i]=max(a[i][1],max(a[i][2],a[i][3]))*2+min(a[i][1],min(a[i][2],a[i][3]))-a[i][1]-a[i][2]-a[i][3];
		}
		if(max(s[1],max(s[2],s[3]))<=n/2){
			cout<<ss<<"\n";
			continue;
		}
		if(s[1]==max(s[1],max(s[2],s[3]))) maxx=1;
		else if(s[2]==max(s[1],max(s[2],s[3]))) maxx=2;
		else maxx=3;
		for(i=0;i<b[maxx].size();i++) v[i]=c[b[maxx][i]];
		sort(v,v+b[maxx].size());
		for(i=0;i<s[maxx]-n/2;i++) ss-=v[i];
		cout<<ss<<"\n";
	}
	return 0;
}