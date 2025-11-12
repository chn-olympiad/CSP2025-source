#include<bits/stdc++.h>
using namespace std;
const int modd=998244353;
int n,m,s[501],c[501],v[501],sum=0;
char d;
void dfs(int d,int shi,int deep){
	if(d>=m&&deep>n){
		sum++;
		sum%=modd;
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			if(shi<c[i]&&s[deep]==1){
				dfs(d+1,shi,deep+1);
			}
			else{
				dfs(d,shi+1,deep+1);
			}
			v[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d;
		s[i]=d-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0,0,1);
	cout<<sum;
	return 0;
}
