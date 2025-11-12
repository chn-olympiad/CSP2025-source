#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n' 
string s;
int a[505]= {};
bool b[505]= {};
int n,m;
int cnt=0;
void dfs(int x,int y) {
	if(x>n) {
		if(x-y-1>=m){
//			cout<<x-y-1<<endl;
			cnt++;
		}
		return ;
	}
	for(int i=1; i<=n; i++) {
		if(b[i]==0) {
			if(y>=a[i]||s[x-1]=='0'){
				b[i]=1;
				dfs(x+1,y+1);
				b[i]=0;
			}else{
				b[i]=1;
				dfs(x+1,y);
				b[i]=0;
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool can=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			can=1;
		}
	}
	if(can==0){
		int x=1;
		for(int i=1;i<=n;i++){
			x*=i;
		}
		cout<<x<<endl;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	dfs(1,0);
	cout<<cnt<<endl;
	return 0;
}
