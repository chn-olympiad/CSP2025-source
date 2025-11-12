#include<bits/stdc++.h>
using namespace std;
int n,k,s[500001],fa;
bool r[500001];
vector<int>RS,RE;
void dfs(int a,int b,int c){
	if(b>n) return;
	c=s[b] xor c;
	if(c==k){
		//cout<<a<<' '<<b<<endl;
		RS.push_back(a);
		RE.push_back(b);
	}
	dfs(a,b+1,c);
	return;
}void chk(bool u[500001],int ans,int dep,string sel){
	bool fla=1;
	//cout<<sel<<' '<<dep<<endl;
	if(RS[dep+1]==-1){
		fa=max(fa,ans+1);
		return;
	}else{
		chk(u,ans,dep+1,sel+'0');
		//cout<<RS[dep+1]<<' '<<RE[dep+1]<<endl;
		for(int i=RS[dep+1];i<=RE[dep+1];i++){
			if(u[i]) fla=0;
	}if(fla){
		for(int i=RS[dep+1];i<=RE[dep+1];i++) u[i]=1;
		chk(u,ans+1,dep+1,sel+'1');
	}}
}int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}for(int i=0;i<n;i++){
		dfs(i,i,0);
	}
	RS.push_back(-1);
	chk(r,0,-1,"");
	cout<<fa;
}
