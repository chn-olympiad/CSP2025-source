#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
const int maxm=1e6+10;
int a[maxn];
int tong[maxm];
int n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tong[a[i]]++;
	}
	if(k==0){
		if(tong[1]==n){
			int x=n/2;
			int ans=0;
			for(int i=1;i<=x;i++){
				ans+=i*2;
			}
			if(n%2==0){
				cout<<ans-x;
			}else{
				cout<<ans;
			}
		}
	}	
	return 0;
}
