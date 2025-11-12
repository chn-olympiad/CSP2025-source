#include<bits/stdc++.h>
using namespace std;
long long a[505],l,ans;
long long b[500005],c[500005],d[500005];
int pian(int n,int m){
	for(int i=1;i<=n;i++){
		if(b[i]==n&&c[i]==m)ans+=d[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans+=n+1;
			b[i]=n;
			c[i]=m;
		}
		for(int i=1;i<=n;i++){
			d[i]+=ans;
		}
	}if(m>=2){
		for(int i=1;i<=n;i++){
			ans+=n;
		}
		for(int i=1;i<=n;i++){
			ans+=n+1;
			b[i]=n;
			c[i]=m;
		}
		for(int i=1;i<=n;i++){
			d[i]=ans;
		}
		
	pian(n,m-1);
//	return ans;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	string s,x="";
	int n,m;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		x+="1";
		cin>>a[i];
	}
	if(s==x){
		pian(n,m);
	}
	cout<<ans;
	return 0;
}
