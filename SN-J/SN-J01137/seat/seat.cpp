#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,r,e,f;
	cin>>n>>m;//n––£¨m¡– 
	int chen[n*m];
	for(int i=0;i<n*m;i++){
		cin>>chen[i];
		if(i==0){
			e=chen[i];
		}else{
			for(int j=0;j<i;j++){
				if(chen[i]>chen[j]){
					r=chen[j];
					chen[j]=chen[i];
					chen[i]=r;
				}
			}
		}
	}for(int i=0;i<=n*m;i++){
		if(e==chen[i]){
			f=i+1;
		}
	}
	
	if((f/n+1)%2==0){
		if(f%n==0){
			if(f%m==0){
				cout<<f/n<<" "<<n;	
			}else{
				cout<<f/n+1<<" "<<n;		
			}
		}else{
			if(f%m==0){
				cout<<f/n<<" "<<n-(f%n);	
			}else{
				cout<<f/n+1<<" "<<n-(f%n);
			}
		}
	}else{
		if((f-1)%n==0){
			if(f%m==0){
				cout<<f/n<<" "<<n;	
			}else{
				cout<<f/n+1<<" "<<n;	
			}
		}else{
			if(f%m==0){
				cout<<f/n<<" "<<f%n;		
			}else{
				cout<<f/n+1<<" "<<f%n;	
			}
		}	
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
