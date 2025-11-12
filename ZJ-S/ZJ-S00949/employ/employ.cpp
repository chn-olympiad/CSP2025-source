#include<bits/stdc++.h>
using namespace std;
string s;
int a[550];
int n,m;
bool st[550];
int ans;
int b[550];
void dfs(int idx){
	if(idx==n+1) {
		int num=0;
		int ans1=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&a[b[i]]>num){
				ans1++;
				
				if(ans1>=m){
					
					ans++;
					break;
				}
			}else{
				num++;
			}
		}
		return ;
	}
	
	for(int i=1;i<=n;i++){
		if(!st[i]){
			st[i]=true;
			b[idx]=i;
			dfs(idx+1);
			st[i]=false;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
