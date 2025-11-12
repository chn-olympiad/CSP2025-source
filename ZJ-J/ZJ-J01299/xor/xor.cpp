#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,b=0,c=0,j=0,i,cnt=0;
	cin>>n>>k;
	long long a[n+2];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			c=j-i;
			if(c==0){
				if(a[i]==k)cnt++;
				
			}else{
				if(c==2&&(a[i]==0||a[i+1]==0)){
					
				}else {
				
					b=a[i];
					for(int z=1;z<=c;z++){
						b=b^a[i+z];
					
					}
				
					if(b==k)cnt++;
					
				}
				
			}
			
		}
	}
	cout<<cnt+1;
	return 0;
}
