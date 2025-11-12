#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in",stdin);
	freopen("club.out",stdout);
	long long int t,a,b,c,A=0,B=0,C=0,e=0,r=0,u=0,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n%2!=0){
			
		}else{
			for(int j=0;j<n;i++){
				cin>>a>>b>>c;
				if(a>b&&a>c){
					A++;
					a=e;
				}
				else if(b>a&&b>c){
					B++;
					b=r;
				}
				else if(c>a&&c>b){
					C++;
					c=u;
				}
				if(A<=n/2&&B<=n/2&&C<=n/2)cout<<e+r+u<<endl;
			}
			
		}
		
	}
	return 0;
}
