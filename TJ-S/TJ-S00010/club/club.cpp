#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	int sum =0;
	int num = 1000005; 
	int cnm =0;
	int ans = 0;
	int b1 = 0;
	int b2 = 0;
	int b3 = 0;
	int cc=0;
	while(t--){
		cin>>n;
		for(int i = 0;i<n;i++){
			for(int j = 0;j<3;j++){
				cin>>a[j];
				if(a[j]>sum){
					sum=a[j];
				}else if(a[j]<num){
					num=a[j];
				}
				else if(sum>=cnm>=num){	
					continue;
				}
				cnm=a[j];
			}
			for(int j = 0;j<3;j++){
				if(a[j]==sum){
					if(j==0){
						b1+=1;
					}else if(j==1){
						b2+=1;
					}else if(j==2){
						b3+=1;
					}
				}
			}if(b1>n/2){
				if(b2<n/2&&a[i]==cnm){
					b1-=1;
					b2+=1;
					continue;
				}
				else if(b3<n/2&&a[i]==cnm){
					b1-=1;
					b3+=1;
					continue;
				}
			}else if(b2>n/2){
				if(b1<n/2&&a[i]==cnm){
					b2-=1;
					b1+=1;
					continue;
				}
				else if(b3<n/2&&a[i]==cnm){
					b2-=1;
					b3+=1;
					continue;
				}
			}else if(b3>n/2){
				if(b1<n/2&&a[i]==cnm){
					b3-=1;
					b1+=1;
					continue;
				}
				else if(b2<n/2&&a[i]==cnm){
					b3-=1;
					b2+=1;
					continue;
				}
			}
			if(ans<=sum&&cc>1){
				if(b1>n/2){
					b1-=1;
					if(b2<n/2){
						b2+=1;
					}else if(b3<n/2){
						b3+=1;
					} 
				}else if(b2>n/2){
					b2-=1;
					if(b1<n/2){
						b1+=1;
					}else if(b3<n/2){
						b3+=1;
					} 
				}if(b3>n/2){
					b3-=1;
					if(b1<n/2){
						b1+=1;
					}else if(b2<n/2){
						b2+=1;
					} 
				}
			}		
			cc++;
			ans+=sum;	
			sum=0;				
		}
		cout<<ans;
		sum =0;
		num = 1000005; 
		cnm =0;
		ans = 0;
		b1 = 0;
		b2 = 0;
		b3 = 0;
		cc=0; 
	}
	return 0;
}
