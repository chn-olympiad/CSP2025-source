#include<bits/stdc++.h>
#define ll long long
using namespace std;
void fre(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
ll ans,n,a[10010],ma,t[10010],mod=998244353,morema;
int main(){
	fre();
	cin>>n;
	t[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ma=a[n];
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=ma;j++)ans=(ans+t[j])%mod;
		ans=(ans+morema)%mod;
		//cout<<morema<<endl;
		morema=morema*2%mod;
		for(int j=ma;j>=0;j--){
			if(j+a[i]>ma)morema=(t[j]+morema)%mod;
			else t[j+a[i]]=(t[j+a[i]]+t[j])%mod;
		}
		//cout<<i<<endl;
		//for(int j=0;j<=ma;j++)cout<<t[j];
		//cout<<" "<<morema;
		//cout<<endl;
	}
	cout<<ans;
	return 0;
}
