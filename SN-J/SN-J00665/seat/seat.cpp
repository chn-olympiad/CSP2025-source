//SN-J00665  樊楷宁  西安市雁塔区第一学校 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	freopon("seat.in","r",stdin);
	freopon("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++){
	cin>>a[i];
	}
    int b=a[1];
   for(int i=1;i<n*m;i++){
   for(int j=i+1;j<=n*m;j++){
   	if(a[i]<a[j]){
   		swap(a[i],a[j]);
	   }
   }
   }
    for(int i=1;i<=n*m;i++){
	if(a[i]==b){
		int c=i;
    	}
	}
	if((c%n)==0){
	if((c/n)2==0){
		cout<<c/n<<" "<<n;
		
	}	else{cout<<c/n<<" "<<n;
	
	}else{if((c/n)2==0){
		cout<<c/n<<" "<<n-1;
	}
	}
	}
return 0;
}
