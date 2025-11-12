#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
#define ll long long 
ll a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,ans=0,t=0,b=1;
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]>1){
			t=1;
		}
	}
	if(t==0){
		if(k==0){
			for(int i=1; i<=n; i++){
				if(a[i]==0){
					ans++;
				}
				else if(a[i]==a[i+1]&&i<n){
					ans++;
					a[i]=a[i+1]=-1;
				}
			}
		}
		else{
			for(int i=1; i<=n; i++){
				if(a[i]==1){
					ans++;
				}
				else if(a[i]!=a[i+1]&&i<n){
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		while(b<n){
			if(a[b]==k){
				b++;
				ans++;
			}
			else{
				int s=a[b];
				for(int i=b+1; i<=n; i++){
					s=s^a[i];
					if(s==k){
						ans++;
						b=i+1;
						break;
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
}