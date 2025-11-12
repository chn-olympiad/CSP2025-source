#include<bits/stdc++.h>
using namespace std;
const int Z=998244353;
int n,ans,maxa,tota,cnt;
int a[5005];
bool pf1=true,pf2=true,flag;
int chs[5005];
int comb(int n,int m){
	m=max(m,n-m);
	int ret=1;
	for(int i=n;i>m;i--){
		ret*=i;
	}
	m=n-m;
	for(int i=2;i<=m;i++){
		ret/=i;
	}
	return ret;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>3) pf1=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) pf2=false;
	}
	if(pf1){
		sort(a+1,a+4);
		if(a[1]+a[2]>a[3]) ans=1;
		else ans=0;
	}else if(pf2){
		const int b=1;
		ans+=(b<<n)-(1+n+(n-1)*n/2);
		if(ans<0) ans+=Z;
		ans%=Z;
	}else{
		flag=true;
		while(flag){
			chs[1]++;
			tota=0,maxa=0;
			for(int i=1;i<=n;i++){
				chs[i+1]+=chs[i]/2;
				chs[i]%=2;
				if(chs[i]){
					tota+=a[i],cnt++;
					maxa=max(maxa,a[i]);
				}
			}
			if(2*maxa<tota&&cnt>=3) ans++;
			flag=false;
			for(int i=1;i<=n;i++){
				if(chs[i]==0){
					flag=true;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}