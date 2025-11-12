#include<bits/stdc++.h> 
#define rep(i,n,m) for(int i=n;i<=m;i++)
#define pre(i,n,m) for(int i=n;i>=m;i--)
using namespace std;
const int N=998244353;
int n,m,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	rep(i,1,m){
		ans=ans*i%N;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
