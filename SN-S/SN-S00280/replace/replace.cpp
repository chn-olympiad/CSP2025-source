//徐梦凡 SN-S00280 延安市新区第一中学 
#include<bits/stdc++.h>
using namespace std;
int a[50004],b[50007],c[50008],club[1500002];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<=n;i++){
			a[i]=0,b[i]=0,c[i]=0;
		}
		int ai,bi,ci;
		for(int i=0;i<n;i++){
			bool a1=true,b1=true,c1=true;
			cin>>ai>>bi>>ci;
			for(int j=0;j<n/2;j++){
				if(ai>a[j] && a1){
					a[j+1]=a[j];
					a[j]=ai;
					a1=false;
				}
				if(bi>b[j] && b1){
					b[j+1]=b[j];
					b[j]=bi;
					b1=false;
				}
				if(ci>c[j] && c1){
					c[j+1]=c[j];
					c[j]=ci;
					c1=false;
				}
			}
		}
		for(int i=0;i<n/2;i++){
			club[i]=a[i];
			club[i+n/2]=b[i];
			club[i+n]=c[i];
		}

		long long ans=0;
		for(int i=0;i<n;i++){
			int maxi=0,maxi1;
			for(int j=0;j<=n/2*3;j++){
				if(club[j]>maxi){
					maxi=club[j];
					maxi1=j;
				}
			}
			ans+=maxi;
			club[maxi1]=0;
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
