#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.cin","club",stdin);
	freopen("club.out","club",stdout);
		int n,sum=0,s=0,r=0,o=0;
		cin>>n;
		int a;
		int b,c,d;
		for(int i=1;i<=n;i++){
			cin>>a;
			for(int j=1;j<=a;j++){
				cin>>b>>c>>d; 
				if(c>=b>=d){
					sum+=c;
					
				}else{
			       if(b>=c>=d){
					sum+=b;
					
				}
				}
				 
		
	}
}
		cout<<sum;
		
	      return 0;
}
