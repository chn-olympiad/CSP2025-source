#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans;
char x;
bool a[505],b[505];
void dfs(int pos,int lose){
	if(n-lose<m){
		return;
	}
	if(pos>n){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]!=1){
			b[i]=1;
			if(c[i]>lose){
				if(a[pos]==1){
					dfs(pos+1,lose);
				}
				else{
					dfs(pos+1,lose+1);
				}
			}
			else{
				dfs(pos+1,lose+1);
			}
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x=='1'){
			a[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
