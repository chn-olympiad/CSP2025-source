#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
long long int a;
bool b[510];
int c[510],d[510],m,n;
string s;
inline void dfs(int x,int y){
	if(x>n){
		if(y>=m){
			a++;
			a%=p;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			if(s[x-1]==48||c[i]<=x-1-y) dfs(x+1,y);
			else dfs(x+1,y+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0);
	cout<<a;
	return 0;
}