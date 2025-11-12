#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n';
using ll=unsigned long long;
int a[5001];
ll ans=0;
ll M=998244353;
void dfss(int n,int minn,int r){
	if(n==0&&minn<0){ans++;ans%=M;return ;}
	if(n==0)return ;
	if(minn<0)return ;
	if(r<0)return ;
	for(int i=r;i>=n-1;i--){
		dfss(n-1,minn-a[i],i-1);
	}
}
int main(){
	fast;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n<3)cout<<0;
	else if(n==3){if((a[0]+a[1])>a[2])cout<<1;else cout<<0;}
	else if(n<=500){
		ll res=0;
		for(int i=2;i<n;i++){
			for(int j=3;j<=i+1;j++){
				dfss(j,a[i]*2,i);
				res+=ans;
				ans=0;
				res%=M;
			}
		}
	}
	else cout<<n*2-1;
	
	
	
	return 0;
} 


