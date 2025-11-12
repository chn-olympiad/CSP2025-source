#include<bits/stdc++.h>
using namespace std;
int a1[100005],a2[100005],a3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,maxn,sum=0,b1=0,b2=0,b3=0;
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			maxn=max(a1[i],a2[i]);
			
			if(a3[i]>maxn){
				
				if(b3==n/2){
					if(a1[i]>a2[i]&&b1+1<=n/2){
						sum+=a1[i];
						b1++;
					}
					if(a1[i]>a2[i]&&b1==n/2){
						sum+=a2[i];
						b2++;
					}	
					if(a1[i]<a2[i]&&b2+1<=n/2){
						sum+=a2[i];
						b2++;
					}
					if(a1[i]<a2[i]&&b2==n/2){
						if(b1+1<=n/2){
							sum+=a1[i];
							b1++;
						}	
					}
					if(a1[i]==a2[i]){
						if(b1==n/2){
							sum+=a2[i];
							b2++;
						}
						else{
							sum+=a1[i];
							b1++;
						}
					}
				}
			
				else{
					sum+=a3[i];
					b3++;
				}
		
			}	
		
		
			else{
				if(maxn==a1[i]){
					
					if(b1==n/2){
						if(a2[i]>a3[i]&&b2+1<=n/2){
							sum+=a2[i];
							b2++;
						}
						if(a2[i]>a3[i]&&b2==n/2){
							sum+=a3[i];
							b3++;
						}
						if(a2[i]<a3[i]&&b3+1<=n/2){
							sum+=a3[i];
							b3++;
						}
						if(a2[i]<a3[i]&&b3==n/2){
							if(b2+1<=n/2){
								sum+=a2[i];
								b2++;
							}	
						}
						if(a2[i]==a3[i]){
							if(b2==n/2){
								sum+=a3[i];
								b3++;
							}
							else{
								sum+=a2[i];
								b2++;
							}
						}
					}
						
					else{
						sum+=maxn;
						b1++;
					}
				}
				
					 
				else{
					
					if(b2==n/2){
						if(a1[i]>a3[i]&&b1+1<=n/2){
							sum+=a1[i];
							b1++;
						}
						if(a1[i]>a3[i]&&b1==n/2){
							sum+=a3[i];
							b3++;
						}
						if(a1[i]<a3[i]&&b3+1<=n/2){
							sum+=a3[i];
							b3++;
						}
						if(a1[i]<a3[i]&&b3==n/2){
							if(b1+1<=n/2){
								sum+=a1[i];
								b1++;
							}	
						}
						if(a1[i]==a3[i]){
							if(b1==n/2){
								sum+=a3[i];
								b3++;
							}
							else{
								sum+=a1[i];
								b1++;
							}
						}
					}
					
					else{
						sum+=maxn;
						b2++;
					}		
				}	
				
			}
		} 
			
		cout<<sum<<endl;
		sum=0,maxn=0,b1=0,b2=0,b3=0;
		
	}
	
	return 0;
}
