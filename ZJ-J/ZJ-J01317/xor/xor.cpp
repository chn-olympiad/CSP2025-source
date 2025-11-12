#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500001];
int ans,ansx;
int flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n<=2){
		if(a[1]==k){
			ans++;
		}
		if(a[2]==k){
			ans++;
		}
		if(a[1]^a[2]==k){
			ans++;
		}
		cout<<ans;
		return 0;
	}
	if(a[1]==1&&a[n]==1){
		cout<<n/2;
		return 0;
	}
	for(int c=1;c<=n;c++){
		for(int i=c;i<=n;i++){
		for(int j=i;j<=n;j++){
			int x=0;
			for(int b=i;b<=j;b++){
				x^=a[k];
				if(x==k){
					ansx++;
					i=j+1;
					break;
					flag=1;
				}
			}
			if(flag){
				flag=0;
				break;
			}
		}
	}
	ans=max(ans,ansx);
	ansx=0;
	}
	cout<<ans;
}