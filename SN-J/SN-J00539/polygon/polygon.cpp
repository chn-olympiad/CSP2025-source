#include <bits/stdc++.h>

using namespace std;
int n;
long long ans;
int f[5001];
int pt[5001];
int bshu;
void pol(int mx_,int mx_bao,int ml,int* pf){
	
	int he=0;
	for(int i=1;i<=ml;i++){
		he+=pf[i];
	}
	if(he>mx_*2){
		ans++;
	}
	ml++;
	if(mx_bao==n){
		return;
	}
	for(int i=mx_bao+1;i<=n;i++){
		pf[ml]=f[i];
		pol(f[i],i,ml,pf);
		pf[ml]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> f[i];
	}
	sort(f+1,f+1+n);
	int mxx=f[1];
	int mx_shu=f[n];
	
	for(int i=1;i<=n;i++){
		if(f[i]==mx_shu){
			bshu++;
		}
	}
	for(int i=1;i<=n;i++){
		mxx=f[i];
		pt[1]=mxx;
		pol(mxx,i,1,pt);
	}
	long long ppp=ans%998244353;
	cout<<ppp;
	return 0;
}
