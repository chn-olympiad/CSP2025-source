#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,sum=0,cnt=0;
ll a[500000+10];
bool vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i]; 
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			bool b=true;
			for(ll k=i;k<=j;k++){
				if(vis[k]==true){
					b=false;
				}
			}
			if(b){
				for(ll k=i;k<=j;k++){
					sum=sum xor a[k];
				}
				if(sum==m){
					cnt++;
					for(ll k=i;k<=j;k++){
						vis[k]=true;
					}
				}
				sum=0;
			}	
		}
	}
	cout<<cnt;
	return 0;
}
