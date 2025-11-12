#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int a,b;
    long long c[1000];
    long long d[1000];
    long long e[1000];
    long long f[1000];
    for(int i=0;i<31;i++){
    	f[i]=0;
	}

    cin>>a;
    for(int i=0;i<a;i++){
    	b=0;
    	cin>>b;
    	for(int j=0;j<b;j++){
    		cin>>c[j];
    		cin>>d[j];
    		cin>>e[j];
	        if(c[j]>=d[j]){
	        	if(c[j]>=e[j]){
	        		f[i]=f[i]+c[j];
				}else{
					f[i]=f[i]+e[j];
				}
			}else{
				if(d[j]>=e[j]){
					f[i]=f[i]+d[j];
				}else{
					f[i]=f[i]+e[j];
				}
			}
		}
    	
	}
	for(int i=0;i<a;i++){
		cout<<f[i]<<endl;
	}
	
    
	return 0;
}

