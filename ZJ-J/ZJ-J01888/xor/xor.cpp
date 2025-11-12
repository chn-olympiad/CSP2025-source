#include<bits/stdc++.h>
using namespace std;
int n,k,zzy,cnt,a[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	a[0]=1;
	for(int i=1;i<=n;i++){
		cin>>zzy;
		cnt^=zzy;
		if(a[cnt^k]==1){
			ans++;
			memset(a,0,sizeof(a));
			a[0]=1;
			cnt=0;
		}
		else{
			a[cnt]=1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//zhun kao zheng hao:1888 
//not AFO
//CSP2025 RP++!!!
//ji dao wan sui!!!
//luogu uid:582006 markkkk_NBFLS please subscribe
//I want to be on shang qi pa dai ma da shang
//I lOVE NBFLS
