#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N = 1e5+10;
int n,ans;
struct pr{int vi,p,id;};
bool f[N];
bool cmp3(pr A,pr B){A.vi > B.vi;}
void solve();
int main(){
//	freopen("club4.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
void solve(){
	vector<pr> v;
	cin>>n;
	cout<<n<<'\n';
	 ans=0;
	int k[4]; k[1]=0,k[2]=0,k[3]=0;
	for(int i=1,a,b,c;i<=n;i++){
		cin>>a>>b>>c; f[i]=0;
		v.push_back({a,i,1});
		v.push_back({b,i,2});
		v.push_back({c,i,3});
		cout<<a<<b<<c<<'\n';
	}
	cout<<"33333\n";
	sort(v.begin(),v.end(),cmp3);
	for(int i=1;i<=3*n;i++){
		if(f[v[i].p] || k[v[i].id] == n/2) continue;
		else{
			f[v[i].p] = 1;
			k[v[i].id]++;
			ans+=v[i].vi;
		}
		cout<<i<<'\n';
	}
	cout<<ans<<'\n';
	
}