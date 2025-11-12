#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<__LINE__<<" : "<<#x<<" "<<x
typedef long long ll;
typedef pair<int,int> PII;

priority_queue<PII, vector<PII>, greater<PII> > q[4];

int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin>>T;
    while(T --){
    	ll ans = 0;
    	int n; cin>>n;
    	vector<vector<int>> s(4, vector<int>(n + 1, 0));
    	for(int i=1;i<=n;i++){
    		for(int j=1;j<=3;j++){cin>>s[j][i];}
    		int id = 0;
    		for(int j=1;j<=3;j++)if(s[j][i] >= s[id][i]){id = j;}
    		int ids = 0;
    		for(int j=1;j<=3;j++)if(j != id && s[j][i] >= s[ids][i]){ids = j;}
    		q[id].push({s[id][i] - s[ids][i], i});
    		ans += s[id][i]; 
		}
		for(int i=1;i<=3;i++)while(q[i].size() > n / 2){
			ans -= q[i].top().first; q[i].pop();
		}
		cout<<ans<<"\n";
		for(int i=1;i<=3;i++)while(q[i].size()){q[i].pop();}
    }
    return 0; 
}
