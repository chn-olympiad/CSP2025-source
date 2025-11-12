//程楚焱 延安新区培文 SN-J00861 
#include<bits/stdc++.h>
using namespace std;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c[255],t,h,u=1,k,m,rg=1;
	long long ty[255][255];
	cin>>a>>b;
	for(int i=1;i<=a*b;i++){
		cin>>c[i];
	}
	h=c[1];
	for (int j=1;j<=a*b;j++){
    	for(int i=1;i<=a*b;i++){
			if(c[i]<=c[i+1]){
				t=c[i+1];
				c[i+1]=c[i];
				c[i]=t;
			}
		}
	}
	for(int j=1;j<=a;j++){
		if(rg%2!=0 || a==1){
			for(int i=1;i<=b;i++){
				ty[j][i]=c[u];
				m=c[u];
				u++;
				//cout<<m<<" "<<h<<endl;
				if(m==h){
					cout<<j<<" "<<i;
					break;
				}				
			}
	    }
	    else{
	    	for(int o=b;o>=1;o--){
				ty[j][o]=c[u];
				k=c[u];
				u++;
				//cout<<k<<" "<<h<<endl;
				if(k==h){
					cout<<j<<" "<<o;
					break;
				}		
			}
		}
		rg++;
    }
	fclose(stdin);
	fclose(stdout);
} 
