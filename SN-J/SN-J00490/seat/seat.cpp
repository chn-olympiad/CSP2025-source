#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat","r",stdin);
	freopen("seat","w",stdout);
	int n,m;
	cin>>n>>m;
	int z;
	z=n*m;
	int a[z];
	int b,p;
	for(int i=z;i>=1;i--){
		cin>>a[i];
		if(i==z){
			b=a[i];
		}
	}
	sort(a+1,a+z+1);
	for(int i=1;i<=z;i++){
		if(a[i]==b){
			p=i;
			break;
		}
	}
	
		if(p/n==0 || p==n){
		    cout<<"1"<<" "<<p;
		}else{
			cout<<p%n<<" ";
			if((p/n+1)%2!=0){
				cout<<p/n+1;
			}else{
				
			}
		}
		
	        
		fclose(stdin);
		fclose(stdout);
	return 0;    
} 
   
