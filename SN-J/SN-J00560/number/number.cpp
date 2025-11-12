#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s;
	cin>>s;
	int n=0,t=s;
	while(t>=1){
		t=t/10;
		n=n+1;
	}
	t=s;
	int c[n],b[n];
	for(int i=n;i>=1;i--){
		c[i]=t%10;
		t=t/10;
		b[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i]<=c[j]){
				b[i]=c[j];
			}
			else if(b[i]==c[j]){
				b[i]=b[i];
			}
		}
		for(int y=1;y<=n;y++){
			if(b[i]==c[y]){
				c[y]=0;
				break;
			}
		}	
	}
	for(int i=1;i<=n;i++){
		cout<<b[i];
	}
	return 0;
}
