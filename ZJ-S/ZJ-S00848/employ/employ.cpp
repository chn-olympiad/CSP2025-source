#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,ans;
int a[505],c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int s1=0;
	for(int i=1;i<=n;i++){
		char d;
		cin>>d;
		a[i]=d-48;
		if(a[i]==1) s1++;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(s1<m){
		cout<<0<<'\n';
		return 0;
	}
	do{
		int s=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s>=c[i]){
				s+=1;
				continue;
			}
			if(a[i]==0) s+=1;
			else sum+=1;
		}
		if(sum>=m) ans=(ans+1)%MOD;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans<<'\n';
	return 0;
}
