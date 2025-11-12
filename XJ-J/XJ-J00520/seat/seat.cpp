#include<bits/stdc++.h> 
using namespace std;
int g[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    long long m,n;
	int q,o,h,l,s,d,k;
    k=0;
    h=1;
    l=0;
    cin>>m>>n;
	o=0;
	cin>>q;
	s=q;
	g[q]++;
	
	for(int i=0;i<=1000;i++){
		g[i]=0;
	
	}
	for(int i=1;i<m*n;++i){
		cin>>d;
		g[d]++;
	
	} 
	for(int i=1000;i>=0;i--){
		if(g[i]!=0){
			o++;
		}if(i==q){
			break;
		}
	}
	s=o+1;
	
	while(s!=0){
	   if(h==n||h==1){
	   	if(k==0){
	   		k=1;
		   }else{
		   	k=0;
		   }
		   l++;
		   s--;
	   }
	   if(s==0){
	   	cout<<l<<' '<<h;
	   	return 0;
	   }
	   s--;
	   if(k==1){
	   	h++;
	   }else{
	   	h--;
	   }	
	  
	}
cout<<l<<' '<<h;
return 0;
}
