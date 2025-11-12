#include<bits/stdc++.h>
using namespace std;
int a[1000000],n,ans=0,k=0,c=0,b=1; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;;i++){
		int s=0;
		for(int j=1;j<=n;j++){
			s+=a[j];
			k=max(k,a[j]);
			
		}
		if(s>2*k){
			ans++;
		}
	}
	 
	cout<<ans;

	
}
