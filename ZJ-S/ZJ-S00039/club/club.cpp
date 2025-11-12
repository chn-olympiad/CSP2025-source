#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}s[100005];
int t,ans=0;
bool cmp(node a,node b){
	return a.a>b.a;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=s[i].a;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
