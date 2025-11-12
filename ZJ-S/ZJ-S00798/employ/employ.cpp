#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,a[100010],ans,nx[100010],c[100010],b[100010],sb,num;
char ch;
void dfs(int x){
	if(x>n){
		if(num>=m) ans++;
		ans%=mod;
	}
	else{
		for(int i=1;i<=n;i++){
			if(b[i]==0){
				if(a[x]==0) sb++;
				else if(sb>=nx[i]) sb++; 
				else num++;
				b[i]=1;
				dfs(x+1);
				b[i]=0;
				if(a[x]==0) sb--;
				else if(sb>=nx[i]) sb--; 
				else num--;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		a[i]=ch-'0';
	}
	for(int i=1;i<=n;i++) cin>>nx[i];
	dfs(1);
	cout<<ans;
	return 0;
}
