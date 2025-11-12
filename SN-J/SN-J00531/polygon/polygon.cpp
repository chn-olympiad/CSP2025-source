#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mo=998244353;
int n;
int a[5005];
int cj,tn,ans=0;
int xbx[5005];
bool tb=true;
void sl(){
	int mm=0,ma=-1,ym=0;
	for(int i=1;i<=n;++i){
		if(xbx[i]==1){
			mm++;
			ym+=a[i];
			ma=max(ma,a[i]);
		}
	} 
	if(mm>=3 and ym>2*ma)ans++;
}
void fs(int a){
	if(a==n){
		xbx[a]=0;
		sl();
		xbx[a]=1;
		sl();
		return;
	}
	xbx[a]=0;
	fs(a+1);
	xbx[a]=1;
	fs(a+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1)tb=false;
	}
	if(tb==true){
		cj=1;
		for(int i=1;i<=n;++i){
			cj=(cj*2)%mo;
		}
		if(n>=30)cj+=mo;
		tn=(n*(n-1)/2)%mo;
		cout<<(cj-tn-n-1)%mo;
	}
	else{
		fs(1);
		cout<<ans;
	}
	return 0;
}

