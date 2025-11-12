#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
string s;
int c[505];
int ans;
int f(int a){
	int cnt=1;
	for(int i=1;i<=a;i++){
		cnt*=i;
	}
	return cnt;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		sort(c,c+n+1);
		if(c[n]<=(n-m)){
			ans=0;break;
		}
		else {
			ans=abs(f(n)-f(m));
		}
		
	}
	cout<<ans%MOD;
	return 0;
}
