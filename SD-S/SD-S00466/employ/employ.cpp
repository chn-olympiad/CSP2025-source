#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const int M=998244353;
int n,m,c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
    cin>>n>>m;
    string s;
    cin>>s;
    int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]){
			cnt++;
		}
	}
	ll ans=1;
	for(int i=1;i<=cnt;i++){
		ans=(ans*i)%M;
	}
	cout<<ans;
	return 0;
}
