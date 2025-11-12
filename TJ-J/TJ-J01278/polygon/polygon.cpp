#include <bits/stdc++.h>
using namespace std;
int n,j,a=1;
int main(){
	//feropen(polygon.in;"r";stdin)
	//feropen(polygon.out;"w";stdout)
    int sum;
	cin>>n;
	int l[n];
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
    for(int i=1;i<=n*2;i++){
    	if(l[i]>l[i+1]){
    		a=l[i];
    		l[i]=l[i+1];
    		l[i+1]=a;	
		}
	}
    for(int i=1;i<=n-2;i++){
    	for(int i=1;i<=n-i+2;i++){
    		if(l[j]+l[j+1]>l[j+2]){
    			    sum+=1;
			}
    	for(int i=1;i<=n-i+2;i++){
			if(l[j]+l[j+1]+l[j+2]>l[j+3]){
    			    sum+=1;
			}
        }
        for(int i=1;i<=n-2;i++){
        	if(l[j]+l[j+1]+l[j+2]+l[j+3]>l[j+4]){
    			    sum+=1;
			}
		}
        for(int i=1;i<=n-i+2;i++){
        	if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]>l[j+5]){
    			    sum+=1;
			}
		}	
        for(int i=1;i<=n-i+2;i++){
        	if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]+l[j+5]>l[j+6]){
    			    sum+=1;
			}
		}
    	for(int i=1;i<=n-i+2;i++){
    		if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]+l[j+5]+l[j+6]>l[j+7]){
    			    sum+=1;
			}
		}
    	for(int i=1;i<=n-i+2;i++){
    		if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]+l[j+5]+l[j+6]+l[j+7]>l[j+8]){
    			    sum+=1;
			}
		}	
        for(int i=1;i<=n-i+2;i++){
        	if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]+l[j+5]+l[j+6]+l[j+7]+l[j+8]>l[j+9]){
    			    sum+=1;
			}
		}
        for(int i=1;i<=n-i+2;i++){
        	if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]+l[j+5]+l[j+6]+l[j+7]+l[j+8]+l[j+9]>l[j+10]){
    			    sum+=1;
			}
		}	
    	for(int i=1;i<=n-i+2;i++){
    		if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]+l[j+5]+l[j+6]+l[j+7]+l[j+8]+l[j+9]+l[j+10]>l[j+11]){
    			    sum+=1;
			}
		}	
    	for(int i=1;i<=n-i+2;i++){
    		if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]+l[j+5]+l[j+6]+l[j+7]+l[j+8]+l[j+9]+l[j+10]+l[j+11]>l[j+12]){
    			    sum+=1;
			}
		}	
    	for(int i=1;i<=n-i+2;i++){
    		if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]+l[j+5]+l[j+6]+l[j+7]+l[j+8]+l[j+9]+l[j+10]+l[j+11]+l[j+12]>l[j+13]){
    			    sum+=1;
			}
		}	
    	for(int i=1;i<=n-i+2;i++){
    		if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]+l[j+5]+l[j+6]+l[j+7]+l[j+8]+l[j+9]+l[j+10]+l[j+11]+l[j+12]+l[j+13]>l[j+14]){
    			    sum+=1;
			}
		}
    	for(int i=1;i<=n-i+2;i++){
    		if(l[j]+l[j+1]+l[j+2]+l[j+3]+l[j+4]+l[j+5]+l[j+6]+l[j+7]+l[j+8]+l[j+9]+l[j+10]+l[j+11]+l[j+12]+l[j+13]+l[j+14]>l[j+15]){
    			    sum+=1;
			}
		}
    }
    }
    cout<<sum;
    //feclose(stdin)
    //feclose(stdout)
}
