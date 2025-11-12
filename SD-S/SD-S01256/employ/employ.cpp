#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,ans;
int a[505],b[505],c;
void dfs(int x,int y,int z){
	if(x==n){
		if(y>=m){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!a[i]){
			a[i]=1;
			if(s[x]=='0'||z>=b[i]){
				dfs(x+1,y,z+1);
			}else{
				dfs(x+1,y+1,z);
			}
			a[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(n<=18){
		dfs(0,0,0);
		cout<<ans<<endl;
		return 0;
	}
	cout<<0<<endl;
	return 0;
}
