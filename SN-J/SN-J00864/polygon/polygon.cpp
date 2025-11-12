#include <bits/stdc++.h>
using namespace std;
int n,ans,a[5005],maxx,b[5005];
void qy(int a){
	a%=998;
	a%=244;
	a%=353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long gong=b[i+1]-b[i-1];
		for(int j=3;j<=n;j++){
			if(i+j>n) break;
			if(gong>a[i+j-1]) ans++;
			gong+=a[j+i-1];
		}
		qy(ans);
	}
	cout<<ans;
	return 0;
}

