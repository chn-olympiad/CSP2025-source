#include<bits/stdc++.h>
using namespace std;
int n,a[510],maxx,cnt,ans;
bool flag;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		maxx=max(maxx,a[i]);
		cnt+=a[i];
	}
	if(n==3){
		if(cnt>maxx*2) cout<<1;
		else cout<<0;
	}
	else if(n>3&&n<=20){
		if(n==4){
			int x=a[0]+a[1]+a[2];
			int m=0;
			m=max(a[1],a[0]);
			m=max(m,a[2]);
			if(x>m*2) ans++;
			x=a[0]+a[1]+a[3];
			m=0;
			m=max(a[1],a[0]);
			m=max(m,a[3]);
			if(x>m*2) ans++;
			x=a[0]+a[2]+a[3];
			m=0;
			m=max(a[2],a[0]);
			m=max(m,a[3]);
			if(x>m*2) ans++;
			x=a[1]+a[2]+a[3];
			m=0;
			m=max(a[1],a[2]);
			m=max(m,a[3]);
			if(x>m*2) ans++;
			if(cnt>maxx*2) ans++;
			cout<<ans;                                                                                                                                                                
		}
	}
	return 0;
}
