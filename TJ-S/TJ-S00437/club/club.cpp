#include<bits/stdc++.h>
using namespace std;
struct w{
	long long a1,a2,a3;
} a[10000005];
long long t,n,x,y,z,best[100005],sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			best[j]=a[j].a1;
			if(best[j]<a[j].a2){
				best[j]=a[j].a2;
			}
			if(best[j]<a[j].a3){
				best[j]=a[j].a3;
			}	
			
			if(best[j]==a[j].a1)
			x++;
			else if(best[j]==a[j].a2)
			y++;
			else if(best[j]==a[j].a3)
			z++;
			
		}
		
		if(x<=n/2 and y<=n/2 and z<=n/2){
	     for(int j=0;j<n;j++){
	     	sum+=best[j];
		 }
		 cout<<sum<<endl;
		 sum=0;
		}
		else if(x>n/2 or y>n/2 or z>n/2){
			
			long long s;
			if(x>n/2){
				s=x-n/2-s;
				for(int j=0;j<n-1;j++){
					for(int l=0;l<n-2;l++){
					if(a[j].a1<a[j+1].a1)
					swap(a[j].a1,a[j+1].a1);
				}
				}
				for(int j=0;j<n/2;j++){
					sum+=a[j].a1;
				}
			}
			
			if(y>n/2){
					s=y-n/2-s;
				for(int j=0;j<n-1;j++){
					for(int l=0;l<n-1;l++){
					if(a[j].a2<a[j+1].a2)
					swap(a[j].a2,a[j+1].a2);
				}
				}
				for(int j=0;j<n/2;j++){
					sum+=a[j].a2;
				}
			}
			
			
			if(z>n/2){
					s=z-n/2-s;
				for(int j=0;j<n-1;j++){
					for(int l=0;l<n-1;l++){
					if(a[j].a3<a[j+1].a3)
					swap(a[j].a3,a[j+1].a3);
				}
				}
				for(int j=0;j<n/2;j++){
					sum+=a[j].a3;
				}
			}
			
			
			cout<<sum+1<<endl;
			sum=0;
		}
		
		
		
	}
	return 0;
}
