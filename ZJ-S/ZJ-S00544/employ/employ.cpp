#include<bits/stdc++.h>
using namespace std;
string x;
const int N=500;
int n,m;
int a,b,d[N+10];
int ans;
void dfs(int a,int b,int c,int t,int x){
	if(c>=m){
		ans++;
		return;
	}
	if(a>0){
		t+=1;
		x+=1;
		a--;
		dfs(a,b,c,t,x);
		x-=1;
		t-=1;
		a++;
	}if(b>0){
		if(t>d[x]) t+=1;
		else c+=1;
		b--;
		x+=1;
		dfs(a,b,c,t,x);
		if(t>d[x]) t-=1;
		else c-=1;		
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>x;
	for(int i=0;i<x.length();++i){
		if(x[i]=='0') a++;
		else b++;
	}
	for(int i=1;i<=n;++i) cin>>d[i];
	dfs(a,b,0,0,1);
	cout<<ans;
	return 0;
}/*3 2
101
1 1 2*/
