#include<iostream>
using namespace std;
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,flag0=0,flag1=0,flag23=0,sum=0;
	int a[500010]={};
	cin>>n>>k;
	for(int i=0;i<n;i=i+1){
		cin>>a[i];
		if(a[i]==0){
			flag0=1;
		}
		else if(a[i]==1){
			flag1=1;
		}
		else{
			flag23=1;
		}
	}
	a[n]=-1;
	if(k<=1 && flag23==0){
		if(k==0){
			for(int i=0;i<n;i=i+1){
				if(a[i]==0){
					sum=sum+1;
				}
				else if(a[i]==1 && a[i+1]==1){
					sum=sum+1;
					i=i+1;
				}
			}
			cout<<sum;
	    }
	    else{
	    	for(int i=0;i<n;i=i+1){
				if(a[i]==1){
					sum=sum+1;
				}
				else if(a[i]==0 && a[i+1]==0){
					sum=sum+1;
					i=i+1;
				}
			}
			cout<<sum;
		}
	}
	else if(k==0 && flag0==0 && flag1==1 && flag23==0){
		cout<<n/2;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
