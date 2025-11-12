#include<bits/stdc++.h>
using namespace std;
int n,m,ss[1000],ans=0,c[1000],vis[1000],tag[1000],err=0,flag;
string s;
void solve(int now){
	if(now==n){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		tag[now+1]=i,vis[i]=1;
		if(err>=c[i]||ss[i])err++;
		/*
		cout<<"now:"<<now+1<<" "<<i<<" "<<err<<endl;
		for(int i=1;i<=now+1;i++)cout<<tag[i]<<" ";
		cout<<endl;
		*/
		if(err<=flag)solve(now+1);
		vis[i]=0;
		if(err>=c[i]||ss[i])err--;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)ss[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	flag=n-m;
	solve(0);
	printf("%d",ans);
	return 0;
}
