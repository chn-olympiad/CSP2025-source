#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,a[1100],b=0,c=0,d=0,ma,tt[11000],bb=0;
	cin>>t;
	for(int s=0;s<t;s++){
		cin>>n;
		tt[s]=0;
		b=0;
		c=0;
		d=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[j];
			}
			ma=a[0];
			for(int j=0;j<3;j++){
				if(a[j]>ma){
					ma=a[j];
				}
			}
			for(int j=0;j<3;j++){
				if(a[j]==ma){
					if(j==0&&b<=n/2){
						b++;
						tt[s]+=ma;
					}if(j==1&&c<=n/2){
						c++;
						tt[s]+=ma;
					}if(j==2&&d<=n/2){
						d++;
						tt[s]+=ma;
					}if(j==0&&b>n/2){
						sort(a,a+3);
						tt[s]+=a[1];
					}if(j==1&&c>n/2){
						sort(a,a+3);
						tt[s]+=a[1];
					}if(j==2&&d>n/2){
						sort(a,a+3);
						tt[s]+=a[1];
					}
				}
			}
		}
	}
	for(int s=0;s<t;s++){
		cout<<tt[s]<<endl;
	}
	return 0;
}
