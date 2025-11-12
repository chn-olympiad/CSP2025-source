#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],c[100005],vis[100005],b[100005],ans,p;
string s;
void dfs(int x) {
    if(x>n){
    	int fq=0,sum=0;
    	for(int i=1;i<=n;i++){
    		int t=b[i];
    		if(fq>=c[t]){
    			fq++;continue;
			}
			if(a[i])sum++;
			else fq++;
		}
		if(sum>=m)ans++;
		return ;
	}
	for(int i=1; i<=n; i++)
		if(!vis[i]) {
			vis[i]=1;
			b[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0; i<s.size(); i++)a[i+1]=s[i]-'0',p+=(!a[i+1]);
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
