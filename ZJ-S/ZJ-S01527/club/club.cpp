#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	long long a[101],d[4],q=0;
	//cin>>t>>n;
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=4;i++){
		scanf("%lld",&d[i]);
	}
	for(int i=1;i<=t;i++){
		if((a[1]>a[2]>a[3] or a[1]>a[3]>a[2]) and d[1]<n/2){
			//if(d[1]<n/2){
				d[1]+=1;
				//q+=a[i];
				
		//	}
		}
	q+=a[i];
	}
	printf("%lld\n",q);
	
	for(int i=1;i<=t;i++){
		 if((a[2]>a[3]>a[1] or a[2]>a[1]>a[3]) and d[2]<n/2){
			//if(d[2]<n/2){
				d[2]+=1;
				//q+=a[i];
				
		//	}
	q+=a[i];
	}
	printf("%lld\n",q);
	

	
	for(int i=1;i<=t;i++){
		if((a[3]>a[2]>a[1] or a[3]>a[1]>a[2]) and d[3]<n/2){
		//	if(d[3]<n/2){
				d[3]+=1;
			//	q+=a[i];
				
				//}
			}
	q+=a[i];	
	}
	printf("%lld\n",q);
	fcloss(stdin);
	fcloss(stdout);
	return 0;
}
}
