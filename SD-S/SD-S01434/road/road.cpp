#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a[1000005],b[1000005],c[1000005],cun,mina,minb,ans,min;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(i==1) ans=c[i];
		else{
			if(ans>c[i]){
				ans=c[i];
				cun=i;
			}
		} 
	}
	mina=a[cun];
	minb=b[cun];	
	for(int i=1;i<=n;i++){
		if(a[i]==mina&&b[i]==minb) continue;
		for(int j=1;j<=m;j++){
			if(a[i]==i||b[i]==i){
				if(min<c[i]) min=c[i];
			}
			ans+=min;
			min=0;
		}
	}
	cout<<ans;
	return 0;
}
