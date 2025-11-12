#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N = 1e5+10;
int n,ans;
struct pr{int vi,p,id;};
vector<pr> v;
bool f[N];
bool cmp3(pr A,pr B){A.vi > B.vi;}
void solve();
int main(){
//	freopen("club4.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t; cin>>t;
	while(t--){
		v.clear();
		cin>>n; ans=0;
		int k[4]; k[1]=0,k[2]=0,k[3]=0;
		for(int i=1,a,b,c;i<=n;i++){
			cin>>a>>b>>c; f[i]=0;
			v.push_back({a,i,1});
			v.push_back({b,i,2});
			v.push_back({c,i,3});
		}
		sort(v.begin(),v.end(),cmp3);
		for(int i=1;i<=3*n;i++){
			if(f[v[i].p] || k[v[i].id] == n/2) continue;
			else{
				f[v[i].p] = 1;
				k[v[i].id]++;
				ans+=v[i].vi;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/