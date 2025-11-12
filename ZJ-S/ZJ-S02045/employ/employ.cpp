#include<bits/stdc++.h>
using namespace std;
void fastIO(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
void fileIO(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int n,m,c[510];
const int mod=998244353;
pair<int,int> pi[510];
int ans;
string s;
bool valid(){
	int cnt=0,left=0;
	for (int i=1;i<=n;i++){
		if (left>=pi[i].second || s[i-1]=='0'){
			left++;
			continue;
		}
		cnt++;
	}
	return cnt>=m;
}
int main(){
	fileIO();
	fastIO();
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++) cin>>c[i];
	for (int i=1;i<=n;i++){
		pi[i]=make_pair(i,c[i]);
	}
	do{
		if (valid()) ans++;
	}while (next_permutation(pi+1,pi+n+1));
	cout<<ans<<endl;
	return 0;
}