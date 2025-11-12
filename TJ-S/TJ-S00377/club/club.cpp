#include <bits/stdc++.h>
using namespace std;
struct ranen{
	int a,b,c;
}r[100005]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t,n,an=0,bn=0,cn=0,nn=0;
    cin>>t;
    
    for(int k=1;k<=t;k++){
    	int h=0;
    	cin>>n;
    	nn+=n;
    	for(int i=1;i<=n;i++){
    		cin>>r[i].a;
    		cin>>r[i].b;
    		cin>>r[i].c;
    		
		}
		for(int i=1;i<=n;i++){
			if(2*an+2>nn){
				r[i].a=0;
			}if(2*bn+2>nn){
				r[i].b=0;
			}if(2*cn+2>nn){
				r[i].c=0;
			}
			if(r[i].a>=r[i].b&&r[i].a>=r[i].c){
				h+=r[i].a;
				an++;
			}else if(r[i].b>=r[i].a&&r[i].b>=r[i].c){
				h+=r[i].b;
				bn++;
			}else if(2*cn+2<=nn){
				h+=r[i].c;
				cn++;
			}
		}cout<<h<<'\n';
	}
	return 0;
    
     
}
