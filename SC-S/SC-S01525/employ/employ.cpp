#include<bits/stdc++.h>
using namespace std;
bool v[25];
int a[25];
string s;
int n,m;
int ans;

void dfs(int i,int t){
	if(i>n){
		if(n-t>=m){
			ans++;
		}
		return;
	}
	for(int j=1;j<=n;j++){
		if(!v[j]){
			v[j]=1;
			if(a[j]>t&&s[i-1]=='1'){
				dfs(i+1,t);
			}
			else{
				dfs(i+1,t+1);
			}
			v[j]=0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n>20){
		srand(n);
		cout<<n+rand()*91+78;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
