#include<iostream>
using namespace std;
int n,a[500005],k,flag1=0,flag2=0,mxa=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag1=1;
		if(a[i]>1) flag2=1;
	}
	if(k==0&&flag1==0){
		cout<<n/2<<endl;
		return 0;
	}
	else if(k<=1&&flag2==0){
	    int cnt=0;
	    if(k==1){
	    	for(int i=1;i<=n;i++){
	    		if(a[i]==1) cnt++;
			}
			cout<<cnt<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
	        if(a[i]==0) cnt++;	
	        if(a[i]==1&&a[i-1]==1){
	            cnt++;
				a[i]=a[i-1]=0;	
			}
		}  
		cout<<cnt<<endl;
		return 0;  	
	}	 
	int cnt1=0;
	for(int j=1;j<=n;j++){
		if(a[j+1]==k&&j!=n){
		    cnt1++;
		    j+=1;
		    continue;
		}		    
		if((a[j]^a[j+1])==k){
			cnt1++;
			continue;		    	
		}
		a[j+1]=(a[j]^a[j+1]);		
	}
	cout<<cnt1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
