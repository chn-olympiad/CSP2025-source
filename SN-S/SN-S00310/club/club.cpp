#include<bits/stdc++.h>
using namespace std;   
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
	cin>>t;
	int n;
    int p,o,i;
    int f;
    int z=0;
    int a[3],b[3],c[3];				
    while(t){
    	cin>>n;
    	p=z;
    	o=z;
    	i=z;
    	for(int j=1;j<=n;j++){
    		cin>>a[j]>>b[j]>>c[j];
    		if(a[j]>b[j] && a[j]!=10 && b[j]!=10){
    			if(a[j]>c[j] && a[j]!=10 && c[j]!=10){
    				f=a[j];
    				p=p+f;
				}else{
					f=c[j];
					i=i+f;
				}
			}else{
				if(b[j]>c[j] && c[j]!=10 && b[j]!=10){
					f=b[j];
					o=o+f;
				}else{
					f=c[j];
					i=i+f;
				}
			}	
		}
		cout<<p+o+i<<endl;
	}

    fclose(stdin);
    fclose(stdout);
	return 0;
} 
