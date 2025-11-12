#include<bits/stdc++.h>
using namespace std;
#define ys 998244353
int pit[505];
bool tg[505];
int lbr[505];
int ren[505];
long long jch(int x){
	if(x==1)return 1;
	if(x==2)return 2;
	if(x==3)return 6;
	if(x==4)return 24;
	return 1ll*x*jch(x-1)%ys;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string hd;
	cin>>n>>m;
	cin>>hd;
	for(int i=1;i<=n;i++){
		cin>>pit[i];
	}
	int mr=0;
	for(int i=0;i<hd.size();i++){
		if(hd[i]-'0'==0)continue;
		tg[i]=1;mr++;
	}
	if(mr<m){
		cout<<0;return 0;
	}
	sort(pit+1,pit+1+n);
	for(int i=1;i<=n && i<=hd.size();i++){
		if(!tg[i]){
			lbr[i]=lbr[i-1]+1;continue; 
		}
		if(lbr[i]<pit[i]){
			ren[i]=n-i;
		}
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		if(ren[i]!=0){
			ans*=jch(ren[i])%ys;
			ans%=ys;
		}
	}
	cout<<ans%ys;
	return 0;
}