#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s=1,ss=1,x=0,w=2,ans=0,Max=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		if(n==1){
			if(k==1) cout<<1;
			else cout<<0;
		} 
		else{
			if(k==1) cout<<2;
			else if(k==0) cout<<1;
			else cout<<0;
		}
		return 0;
	}
	while(ss<=n){
		x=0,w=2,ans=0;
		s=ss;
		while(s<=n){
			x^=a[s];
			if(x==k){
				x=0;
				ans++;
				s++;
				w=s+1;
			}
			else{
				if(s==n){
					s=w;
					w++;
				}
				else s++;
			}
		}		
		ss++;
		Max=max(Max,ans);
	}
	cout<<Max;
	return 0;
}
