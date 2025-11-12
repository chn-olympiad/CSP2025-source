//SN-J00251 孙悦翔 西安市曲江第一学校
#include<bits/stdc++.h>
using namespace std;

int a[13][13],s[105],n,m,l,ms,mh,ml,nh,nl;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nh=nl=1;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	ms=s[1];
	sort(s,s+n*m+1);
	a[1][1]=s[n*m];
	if(m%2){
		a[n][m]=s[1];
	}
	else{
		a[1][m]=s[1];
	}
	while(l<n*m){
        if(nh<n&&nl%2){
        	a[nh][nl]=s[n*m-l];
        	if(a[nh][nl]==ms){
		    	cout<<nl<<" "<<nh;
		    	return 0;
		    }     
        	nh++;
		}	
		else if(nh==n&&nl%2){
			a[nh][nl]=s[n*m-l];
			if(a[nh][nl]==ms){
  	            cout<<nl<<" "<<nh;
            	return 0;
            }   
			nl++;
		}
		else if(nh>1&&nl%2==0){
			a[nh][nl]=s[n*m-l];
			if(a[nh][nl]==ms){
  	            cout<<nl<<" "<<nh;
   	            return 0;
            }
			nh--;
		}
		else{
			a[nh][nl]=s[n*m-l];
			if(a[nh][nl]==ms){
  	            cout<<nl<<" "<<nh;
               	return 0;
            }
			nl++;
		}
		l++;
	}
	return 0; 
} 
