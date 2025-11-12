#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define faster ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int N=510,mod=998244353;
int n,m,f;
string s;
int c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			f=1;
			break;
		}
	}
	if(!f){
		cout<<n*(n-1);
		return 0;	
	}
	return 0;
}
