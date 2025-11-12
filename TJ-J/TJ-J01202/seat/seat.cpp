#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long a[1005];
	long long n,m,ans=0;
	long long b;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+1+n);
	for(int i=1;i<=n*m;++i){
		if(a[i]!=b) ans+=1;
		if(a[i]==b) ans+=1;
	}
	cout<<"1"<<" "<<ans;
	return 0;
}
