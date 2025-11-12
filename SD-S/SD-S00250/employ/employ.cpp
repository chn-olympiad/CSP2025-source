#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
const int N=510;
int a[N];
int b[N];
int id[N];
int n,m;
constexpr int mod=998244353;
void bf(){
	int tot=0;
	int ans=0;
	int output=0;
	do{
		tot=0;
		ans=0;
		for (int i=1; i<=n; i++){
			if (tot>=a[id[i]]){
				++tot;
				continue;
			}
			if (s[i]=='0'){
				++tot;
				continue;
			}
			ans++;
		}
		if (ans>=m) output++;
		if (output>=mod) output-=mod;
	}while (next_permutation(id+1,id+n+1));
	cout<<output;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s='#'+s;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		id[i]=i;
	}
	bf();
	return 0;
}

