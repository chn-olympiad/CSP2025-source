#include<bits/stdc++.h>
using namespace std;
long long n,m,s[5001],ans,p=998244353;
string a;
bool v[501];
void dfs(int k,int l){
	if(k>=m&&l>=n){
		ans++;ans=ans%p;
		return ;
	}for(int i=1;i<=n;i++){
		if(!v[i]){
			if(!(s[i]<=l-k)&&a[l]=='1'){
				v[i]=1;
				dfs(k+1,l+1);
				v[i]=0;
			}else{
				v[i]=1;
				dfs(k,l+1);
				v[i]=0;
			}
		}
			
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	dfs(0,0);
	cout<<ans;
	
	
	
	return 0;
}/*
3 2
101
1 1 2

4 3
1101
1 3 2 4
cout<<18

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

0 1 2 2 3 3 4 4 5 6
  3 7 6 7 6 5 4 3 2
  
*/
