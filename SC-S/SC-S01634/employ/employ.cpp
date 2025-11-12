#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<__LINE__<<" : "<<#x<<" "<<x
typedef long long ll;
typedef pair<int,int> PII;
const int N=500+5,mod=1e9+7;

int n, m;
int s[N], c[N]; 

int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    string w; cin>>w; w = ' ' + w;
    for(int i=1;i<=n;i++){s[i] = w[i] - '0';}
	for(int i=1;i<=n;i++){cin>>c[i];} 
	if(n <= 18){
		vector<int> v(n + 1); iota(v.begin(), v.end(), 0);
		ll ans = 0;
		do{
			int last = 0;
			for(int i=1;i<=n;i++){
				int id = v[i];
				if(c[id] <= last || s[i] == 0){last ++;}
			}
			ans += (n - last >= m);
		}while(next_permutation(v.begin() + 1, v.end()));
		cout<<ans<<"\n";
	}
	else{
		ll sum = 0;
		for(int i=1;i<=n;i++){sum += (c[i] > 0);}
		ll ans = 1;
		if(sum < m){cout<<"0\n"; return 0;}
		for(int i=1;i<=sum;i++){ans = ans * i % mod;}
		cout<<ans<<"\n";
	}
    return 0; 
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3 
*/
