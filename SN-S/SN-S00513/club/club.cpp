#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int num[t];
	for(int q=0;q<t;q++){
	    int n;
    	cin>>n;
	    int a[n][t];
    	for(int i=1;i<=n;i++){
	    	for(int j=1;j<=t;j++){
		    	cin>>a[i][j];
		    }
	    }
	    for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++){
				if(a[j][0]>a[i][0])
				{
			    	int b=a[i][0];
    				a[i][0]=a[j][0];
	    			a[j][0]=b;	
				}
				if(a[j][0]=a[i][0])
				{
					for(int l=2;l<n;l++){
						for(int k=l+1;k<n;k++){
							if(a[l][1]>a[k][1]){
								int c=a[l][1];
								a[l][1]=a[k][1];
								a[k][1]=c;
							}
						}
					}
				}
			}
		}
		int sum[n/2]={0};
	   	for(int j=0;j<n/2;j++){
	    	sum[j]=sum[j]+a[j][q];
	    	for(int l=j;l<n/2+j;l++){
	    		sum[j]=sum[j]+a[l][q];
	   			for(int k=l;k<n/2+l;k++){
	    			sum[j]=sum[j]+a[k][q];
				}
			}
		}
		num[q]=sum[q];
	}
	for(int i=0;i<t;i++){
		cout<<num[i]<<endl;
	}
	return 0;
}
