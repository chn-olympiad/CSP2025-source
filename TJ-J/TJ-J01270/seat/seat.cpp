#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,c=1,r=1,e,sum,k;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
    	cin>>a[i];
	}
	e=a[0];
	for(int j=0;j<n*m;j++){
		sum=a[0];		
		for(int i=1;i<n*m;i++){
			if(sum>=a[i]){
				sum=sum;
			}
			else{
				sum=a[i];
				k=i;
			}
		}
	    a[k]=0;
		if(sum==e){
		    cout<<r<<" "<<c<<endl;
			break;
		}
		else{
			if(c==n&&r%2!=0){
				r+=1;
			}
			else if(r%2==0&&c>=2){
				c=c-1;
			}
			else if(r%2!=0){
				c+=1;
			}
			else{
				r+=1;
			}	
		}
	}
	return 0;
}
