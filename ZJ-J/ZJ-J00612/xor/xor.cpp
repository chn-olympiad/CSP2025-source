#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,s,fl,ans,a[500010],f[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=n-i+1;j++){
			s=0;fl=1;
			for(k=j;k<=j+i-1;k++) s^=a[k];
			for(k=j;k<=j+i-1;k++)
				if(f[k]==1){
					fl=0;
					break;
				}
			if(fl&&s==m){
				ans++;
				for(k=j;k<=j+i-1;k++) f[k]=1;
			}
		}
	cout<<ans;
	return 0;
}

