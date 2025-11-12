#include<bits/stdc++.h>
using namespace std;
int a[100001],n,ans=0,zxc,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>zxc>>b>>c;
		int bij=zxc;
		if(bij<b){
			bij=b;
		}
		if(bij<c){
			bij=c;
		}
		int h=zxc+b+c;
		if(h<=bij*2){
			cout<<0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int p=j+1;p<=n;p++){
					if(a[i]+a[j]>a[p]&&p<=n){
						ans++;
					}
					for(int q=p+1;q<=n;q++){
						if(a[i]+a[j]+a[p]>a[q]&&q<=n){
							ans++;
						}
						for(int t=q+1;t<=n;t++){
							if(a[i]+a[j]+a[p]+a[q]>a[t]&&t<=n){
								ans++;
							}
							for(int r=t+1;r<=n;i++){
								if(a[i]+a[j]+a[p]+a[q]+a[t]>a[r]&&r<=n){
									ans++;
								}
								for(int g=r+1;g<=n;g++){
									if(a[i]+a[j]+a[p]+a[q]+a[t]+a[r]>a[g]&&g<=n){
										ans++;
									}
									for(int f=g+1;f<=n;f++){
										if(a[i]+a[j]+a[p]+a[q]+a[t]+a[r]+a[g]>a[f]&&f<=n){
											ans++;
										}
										for(int e=f+1;e<=n;e++){
											for(int v=e+1;v<=n;v++){
												if(a[i]+a[j]+a[p]+a[q]+a[t]+a[r]+a[g]+a[f]+a[e]>a[v]&&v<=n){
													ans++;
												}
											}
										}
									}
								}
							}
						} 
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
} 
