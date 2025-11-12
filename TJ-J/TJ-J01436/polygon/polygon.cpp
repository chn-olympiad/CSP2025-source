#include<bits/stdc++.h>
using namespace std;
int a[5050],up[5050],dn[5050];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,cnt=3,ans=0,upp=1,dnn=1;
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	while(cnt<=n){
	    for(long long i=1;i<=cnt;i++){
	    	up[i]=n-i+1;
	    	dn[i]=cnt-i+1;
		}
		for(long long i=1;i<=cnt;i++){
		    upp*=up[i];
		    dnn*=dn[i];
		}
		ans+=(upp/dnn);
		cnt++;
	    memset(up,0,sizeof(up));
		memset(dn,0,sizeof(dn)); 
		upp=1;
		dnn=1;   	
	}
	cout << ans;
	return 0;
} 
