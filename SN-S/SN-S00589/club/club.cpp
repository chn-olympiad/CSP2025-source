#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int s=1;
	int t,n,m=0;
	cin>>t;
	int a[n+1],b[n+1],c[n+1];
	for(int j=0;j<t;j++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			while(s<n){
			if(a[i]+a[i-s]>a[i]+b[i-s]&&a[i]+a[i-s]>a[i]+c[i-s]&&a[i]+a[i-s]>b[i]+a[i-s]&&a[i]+a[i-s]>b[i]+b[i-s]&&a[i]+a[i-s]>b[i]+c[i-s]&&a[i]+a[i-s]>c[i]+c[i-s]&&a[i]+a[i-s]>c[i]+b[i-s]&&a[i]+a[i-s]>c[i]+a[i-s]&&a[i-s]!=0&&i>0){
				m=a[i]+a[i-s];
			}
			if(a[i]+b[i-s]>a[i]+a[i-s]&&a[i]+b[i-s]>a[i]+c[i-s]&&a[i]+b[i-s]>b[i]+a[i-s]&&a[i]+b[i-s]>b[i]+b[i-s]&&a[i]+b[i-s]>b[i]+c[i-s]&&a[i]+b[i-s]>c[i]+c[i-s]&&a[i]+b[i-s]>c[i]+b[i-s]&&a[i]+b[i-s]>c[i]+a[i-s]&&b[i-s]!=0&&i>0){
				m=a[i]+b[i-s];
			}
			if(a[i]+c[i-s]>a[i]+b[i-s]&&a[i]+c[i-s]>a[i]+a[i-s]&&a[i]+c[i-s]>b[i]+a[i-s]&&a[i]+c[i-s]>b[i]+b[i-s]&&a[i]+c[i-s]>b[i]+c[i-s]&&a[i]+c[i-s]>c[i]+c[i-s]&&a[i]+c[i-s]>c[i]+b[i-s]&&a[i]+c[i-s]>c[i]+a[i-s]&&c[i-s]!=0&&i>0){
				m=a[i]+c[i-s];

			}
			if(b[i]+a[i-s]>a[i]+b[i-s]&&b[i]+a[i-s]>a[i]+c[i-s]&&b[i]+a[i-s]>a[i]+a[i-s]&&b[i]+a[i-s]>b[i]+b[i-s]&&b[i]+a[i-s]>b[i]+c[i-s]&&b[i]+a[i-s]>c[i]+c[i-s]&&b[i]+a[i-s]>c[i]+b[i-s]&&b[i]+a[i-s]>c[i]+a[i-s]&&a[i-s]!=0&&i>0){
				m=b[i]+a[i-s];
		
			}
			if(b[i]+b[i-s]>a[i]+b[i-s]&&b[i]+b[i-s]>a[i]+c[i-s]&&b[i]+b[i-s]>b[i]+a[i-s]&&b[i]+b[i-s]>a[i]+a[i-s]&&b[i]+b[i-s]>b[i]+c[i-s]&&b[i]+b[i-s]>c[i]+c[i-s]&&b[i]+b[i-s]>c[i]+b[i-s]&&b[i]+b[i-s]>c[i]+a[i-s]&&b[i-s]!=0&&i>0){
				m=b[i]+b[i-s];
			}
			if(b[i]+c[i-s]>a[i]+b[i-s]&&b[i]+c[i-s]>a[i]+c[i-s]&&b[i]+c[i-s]>b[i]+a[i-s]&&b[i]+c[i-s]>b[i]+b[i-s]&&b[i]+c[i-s]>a[i]+a[i-s]&&b[i]+c[i-s]>c[i]+c[i-s]&&b[i]+c[i-s]>c[i]+b[i-s]&&b[i]+c[i-s]>c[i]+a[i-s]&&c[i-s]!=0&&i>0){
				m=b[i]+c[i-s];

			}
			if(c[i]+a[i-s]>a[i]+b[i-s]&&c[i]+a[i-s]>a[i]+c[i-s]&&c[i]+a[i-s]>b[i]+a[i-s]&&c[i]+a[i-s]>b[i]+b[i-s]&&c[i]+a[i-s]>a[i]+a[i-s]&&c[i]+a[i-s]>c[i]+c[i-s]&&c[i]+a[i-s]>c[i]+b[i-s]&&a[i]+a[i-s]>c[i]+a[i-s]&&a[i-s]!=0&&i>0){
				m=c[i]+a[i-s];

			}
			if(c[i]+b[i-s]>a[i]+b[i-s]&&c[i]+b[i-s]>a[i]+c[i-s]&&c[i]+b[i-s]>b[i]+a[i-s]&&c[i]+b[i-s]>b[i]+b[i-s]&&c[i]+b[i-s]>a[i]+a[i-s]&&c[i]+b[i-s]>c[i]+c[i-s]&&c[i]+b[i-s]>a[i]+a[i-s]&&c[i]+b[i-s]>c[i]+a[i-s]&&b[i-s]!=0&&i>0){
				m=c[i]+b[i-s];

			}
			if(c[i]+c[i-s]>a[i]+b[i-s]&&c[i]+c[i-s]>a[i]+c[i-s]&&c[i]+c[i-s]>b[i]+a[i-s]&&c[i]+c[i-s]>b[i]+b[i-s]&&c[i]+c[i-s]>a[i]+a[i-s]&&c[i]+c[i-s]>a[i]+a[i-s]&&c[i]+c[i-s]>c[i]+b[i-s]&&c[i]+c[i-s]>c[i]+a[i-s]&&c[i-s]!=0&&i>0){
				m=c[i]+c[i-s];

			}
			s++;
		}
			if(a[i]>b[i]&&a[i]>c[i]&&i<n/2){
				m+=a[i];
				a[i]=0;
			}else if(b[i]>a[i]&&b[i]>c[i]&&i<n/2){
				m+=b[i];
				b[i]=0;
			}else if(c[i]>a[i]&&c[i]>b[i]&&i<n/2){
				m+=c[i];
				c[i]=0;
				}
				else if(i>=n/2){
				if(a[i]>b[i]&&a[i]>c[i]&&a[i-1]!=0){
					m+=a[i];
				}else if(b[i]>a[i]&&b[i]>c[i]&&b[i-1]!=0){
					m+=b[i];
				}else if(c[i]>a[i]&&c[i]>b[i]&&i<n/2&&c[i-1]!=0){
					m+=c[i];
				}
			}
		
		}
		cout<<m<<endl;
		m=0;
}
	
	return 0;
} 
