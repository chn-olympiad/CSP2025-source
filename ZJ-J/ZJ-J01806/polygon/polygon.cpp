#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a[5010],sum,mx,f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;	
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3) cout<<0;
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]!=a[1]){
				f=1;
				break;
			}
		}
		if(f==0){
			cout<<(n*n+2-3*n)/2;
		}
		else{
			for(int i=3;i<=n;i++){
				int x=i,s=1;
				for(int l=1;l<=(1+i)*i/2;l++){
					while(x--){
						for(int j=s;j<=n-i;j++){
							sum+=a[j];
							if(x==0) mx=a[j];
						}
					}
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
