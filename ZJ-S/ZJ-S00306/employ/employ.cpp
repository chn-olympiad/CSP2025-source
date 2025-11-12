#include<iostream>
#include<algorithm>
#define MOD 998244353
#define int long long
using namespace std;
int n,m;
int c[505];
string str;
int s[505];
bool judge[505];
int ans;
int time;
void dfs(int num,int brk){
	time++;
	if(time>10000000)return;
	if(brk>n-m)return;
	if(num>n){
		if(n-brk>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!judge[i]){
			judge[i]=true;
			dfs(num+1,brk+((brk>=c[i])||(!s[num])?1:0));
			judge[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	fill(judge+1,judge+n+1,false);
	cin>>str;
	for(int i=0;i<str.size();i++)s[i+1]=str[i]-48;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//expect 10 pts
