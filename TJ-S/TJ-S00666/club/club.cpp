#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int ans,ni,ni1,cia,cib,cic;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int j=1;j<=t;j++){
		cin>>n;
		ans=0;
		ni=0;
		ni1=0;
		cia=0;
		cib=0;
		cic=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int j=1;j<=n;j++){
			ni+=b[j];
			ni1+=c[j];	
		}
		if(ni==0&&ni1==0){
			sort(a+1,a+n+1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans;
		}
		for(int i=1;i<=n;i++){
			if(cia<=n/2&&cib<=n/2&&cic<=n/2){
				if(a[i]==max(a[i],b[i])){
					if(a[i]==max(a[i],c[i])){
						ans+=a[i];
						cia++;
					}else{
						ans+=c[i];
						cic++;
					}
				}
				else if(b[i]==max(c[i],b[i])){
					if(b[i]==max(b[i],a[i])){
						ans+=b[i];
						cib++;
					}else{
						ans+=a[i];
						cia++;
					}
				}
				else {
					if(c[i]==max(b[i],c[i])){
						ans+=c[i];
						cic++;
					}else{
						ans+=b[i];
						cib++;
					}
				} 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

