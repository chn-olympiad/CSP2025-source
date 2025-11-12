#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n,a[N],i,ans;
bool b[N];int ansc;
bool text=1;
int c(int num){
	ansc=1;
	for(int i=n+1-num;i<=n;i++)ansc=(ansc*i)%mod;
	while(num)if(num)ansc/=num--;
	return ansc;
}
void bfs(int m,int tot){
	for(int bfsi=0;bfsi<n;bfsi++){
		if(b[bfsi] || a[bfsi]>=m)continue;
		if(tot>m){
			ans=(ans+1)%mod;
			for(int j=0;j<n;j++){
			}
		}
		
		b[bfsi]=1;
		bfs(m,tot+a[bfsi]);
		b[bfsi]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>1)text=0;
	}
	if(text){
		ans=0;
		for(i=3;i<=n;i++){
			ans=(ans+c(i))%mod;
		}
		cout<<ans;
	}
	else{
		for(i=n;i>=0;i--){
			bfs(i,0);
		}
		cout<<ans;
	}//I can't solve it.
	return 0;
}
//m = 3 
//baoli
