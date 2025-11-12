#include<bits/stdc++.h>
using namespace std;
int e[150];
long long a,b,m[100][100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a*b;i++){
		cin>>e[i];
	}
	sort(e+1,e+a*b-1);
	
	int t=a*b;
	for(int i=1;i<a*b;i++){
		if(e[0]<e[i]){
			t--;	
		}	
	}	
	t=a*b-t;
	
	int r=0;
	for(int i=0;i<b;i++){
		if(i%2==0){
			for(int j=0;j<a;j++){
				if(r==t){
					cout<<i+1<<" "<<j+1;
				}
				r++;
			}		
			}else{
				for(int j=a-1;j>=0;j--){
					if(r==t){				
						cout<<i+1<<" "<<j+1;
					}
					r++;	
					}
		}
	}	
	return 0;
}  
