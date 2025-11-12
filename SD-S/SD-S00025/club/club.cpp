#include <bits/stdc++.h>
using namespace std;
long long t,a[100001],b[100001],c[100001],d[6];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n,sum=0,m,a1=0,b1=0,c1=0;
		cin>>n;
		m=n/2;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>=b[j]&&a[j]>=c[j])a1+=1,sum+=a[j];
			else if(b[j]>=a[j]&&b[j]>=c[j])b1+=1,sum+=b[j];
			else c1+=1,sum+=c[j];
		}
		if(a1<=m&&b1<=m&&c1<=m){
			d[i]=sum;
		}
		else{
			long long u1[100001],u2[100001],v[100001];
			for(int j=1;j<=n;j++){
				if(a[j]>=b[j]&&a[j]>=c[j]){
					if(b[j]>c[j]){
						u1[j]=a[j]-b[j];
						u2[j]=a[j]-c[j];
					}
					else{
						u1[j]=a[j]-c[j];
						u2[j]=a[j]-b[j];
					}
					v[j]=1;
				}
				else if(b[j]>=a[j]&&b[j]>=c[j]){
					if(a[j]>c[j]){
						u1[j]=b[j]-a[j];
						u2[j]=b[j]-c[j];
					}
					else{
						u1[j]=b[j]-c[j];
						u2[j]=b[j]-a[j];
					}
					v[j]=2;
				}
				else{
					if(a[j]>b[j]){
						u1[j]=c[j]-a[j];
						u2[j]=c[j]-b[j];
					}
					else{
						u1[j]=c[j]-b[j];		
						u2[j]=c[j]-a[j];
					}
					v[j]=3;
				}
			}
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(u1[j]>u1[k]){
						swap(u1[j],u1[k]);
						swap(a[j],a[k]);
						swap(b[j],b[k]);
						swap(c[j],c[k]);
					}
				}
			} 
			for(int j=1;j<=n;j++){ 
				if(a1>m&&v[j]==1){
					sum-=u1[j];
					u1[j]=u2[j];
					if(b[j]>c[j])a1-=1,b1+=1;
					else a1-=1,c1+=1;
				}
				if(b1>m&&v[j]==2){
					sum-=u1[j];
					u1[j]=u2[j];
					if(a[j]>c[j])b1-=1,a1+=1;
					else b1-=1,c1+=1;
				}
				if(c1>m&&v[j]==3){
					sum-=u1[j];
					u1[j]=u2[j];
					if(a[j]>b[j])c1-=1,a1+=1;
					else c1-=1,b1+=1;
				}
			}
		}
		d[i]=sum;
		sum=0;
	}
	for(int i=1;i<=t;i++)cout<<d[i]<<endl;
	return 0;
}//Ren5Jie4Di4Ling5%
