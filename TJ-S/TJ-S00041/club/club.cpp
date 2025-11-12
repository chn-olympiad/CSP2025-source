#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		int ans=0;
		cin>>n;
		int a[100005],b[100005],c[100005];
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		for(int l=1;l<=n;l++){
			sort(a+1,a+n+1);
			sort(b+1,b+n+1);
			sort(c+1,c+n+1);
			int nsa=0,nsb=0,nsc=0;
			for(int j=n/2;j>0;j--){
				nsa+=a[i];
				nsb+=b[i];
				nsc+=c[i];
			}
			if(nsa>nsb && nsa>nsc){
				ans+=nsa;
				for(int j=n/2;j>0;j--){
					a[i]=0;
					b[i]=0;
					c[i]=0;
				}
			}else if(nsb>nsa && nsb>nsc){
				ans+=nsb;
				for(int j=n/2;j>0;j--){
					a[i]=0;
					b[i]=0;
					c[i]=0;
				}
			}else{
				ans+=nsc;
				for(int j=n/2;j>0;j--){
					a[i]=0;
					b[i]=0;
					c[i]=0;
				}
			}
		}
		cout<<ans<<endl;
			
	}
}
