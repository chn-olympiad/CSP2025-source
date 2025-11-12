#include<bits/stdc++.h>


using namespace std;

int n,cnt,da=0,cmm=0;
int num[5010];
int numm[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>num[1];
	numm[1]=num[1];
	for(int i=2;i<=n;i++){
		cin>>num[i];
		numm[i]=num[i]+numm[i-1];
	}
	for(int h=1;h<=n;h++){
		for(int g=1;g<=n;g++){
			if(num[h+g-1]<=n-3)num[h+g]=-1;
			else break;
			
			for(int i=1;i<=n;i++){
				cnt=0;
				da=0;
				for(int j=i;j<=n;j++){
				    if(num[j]!=-1){
					
						cnt=numm[j]-numm[i];	
					    da=max(da,num[j]);
					    if(da*2<cnt){
					    	cmm++;
						}
			        }
				   
				}
			}		
		}
	}

   	cout<<cmm;
	return 0;
	
} 
