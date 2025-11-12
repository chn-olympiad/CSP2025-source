#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[1000],b[1000],c[1000],ans;
string s;
long long po(int w){
	long long ans=1;
	for(int i=1;i<=w;i++)
		ans=ans*i%998244353;
	return ans;
}
bool check(){
	int h=0,o=0;
	for(int i=1;i<=n;i++){
		if(a[c[i]]<=h) continue;
		if(s[i-1]=='0') h++;
		else o++;
	}
	return (o>=m);
}
void dfs(int u){
	if(u==n+1&&check()){
		ans=(ans+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1,c[u]=i;
			dfs(u+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='1')
			cnt++;
	if(m>cnt)
		return cout<<0,0;
	if(cnt==n)
		return cout<<po(n),0;
	if(m==n)
		return cout<<0,0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs(1);
	cout<<ans;
}