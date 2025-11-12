#include<iostream>
#include<algorithm>
using namespace std;

char ch[510];
bool flag[510];
int n,m,ans,c[510],p[510];

/*
 10 5
 1101111011
 6 0 4 2 1 2 5 4 3 3
*/

int check(){
	int giveup=0,num=0;
	for(int i=1;i<=n;i++){
		if(ch[i]=='0') giveup++;
		else if(giveup<c[p[i]]) num++;
		else giveup++;
	}
	return num>=m?1:0;
}

void dfs(int x){
	if(x>n){
		ans+=check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]) continue;
		flag[i]=1;
		p[x]=i,dfs(x+1);
		flag[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>ch+1;
	int cnt=0;
	for(int i=1;i<=n;i++) if(ch[i]=='1') cnt++;
	if(cnt<m){cout<<0;return 0;}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
