//程楚焱 延安新区培文 SN-J00861 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int c[999],t,h=0,g=1;
	string a;
	cin>>a;
    for(int i=0;i<=a.size()-1;i++){
    	//cout<<i;
    	if(a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5' || a[i]=='6' || a[i]=='7' || a[i]=='8' || a[i]=='9' || a[i]=='0'){
    		//cout<<a[i]<<" ";
    		if(g<=a.size()-1){
    			c[h]==a[i];
    			g++;
    			h++;
    			cout<<a[i]<<" ";
			}
		}
	}
	/*for (int j=0;j<=a.size()-1;j++){
    	for(int i=0;i<=a.size()-1;i++){
			if(c[i]<=c[i+1]){
				t=c[i+1];
				c[i+1]=c[i];
				c[i]=t;
			}
		}
	}*/
	for(int i=0;i<=a.size()-1;i++){
		cout<<c[i]<<" ";
	}
} 
