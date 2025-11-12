#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+5;
int n,t,a[mx],b[mx],c[mx],s=0,a1[mx],b1[mx];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			a1[i]=a[i],b1[i]=b[i];
		}
		int x=0;
		if(b[n]==c[n]==0){
			sort(a+1,a+n+1);
			for(int i=n;i>=n/2;i--)
				x+=a[i];
			cout<<x<<endl;
		}
		else if(c[n]==0){
			int s=0,k=0;
			for(int i=1;i<=n;i++)
				s+=a[i],k+=b[i];
				if(s>k){
					sort(a+1,a+n+1);
					for(int i=n;i>=n/2;i--){
						x+=a[i];
						for(int j=1;j<=n;j++)
							if(a[i]==a1[j]){
								b[j]=0;
							}
						}
					sort(b+1,b+n+1);
					for(int i=n;i>=n/2;i--)
						x+=b[i];
					cout<<x<<endl;
				}
				else{
					sort(b+1,b+n+1);
					for(int i=n;i>=n/2;i--){
						x+=b[i];
						for(int j=1;j<=n;j++)
							if(b[i]==b1[j]){
								a[j]=0;
							}
						}
					sort(a+1,a+n+1);
					for(int i=n;i>=n/2;i--)
						x+=a[i];
					cout<<x<<endl;
				}
		}
		else{
			x=max(a[1]+b[2],max(a[1]+c[2],max(b[1]+a[2],max(b[1]+c[2],max(c[1]+a[2],max(c[1]+b[2],1))))));
			cout<<x<<endl;
		}
	}
	return 0;
} 