#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdin);
	int n,m,camp,c=1,r=1;
	cin>>n>>m;
	int a1[n*m],a2[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a1[i];
	}
	camp=a1[0];
	sort(a1,a1+n*m);
	int p=0;
	for(int i=n*m-1;i>=0;i--){
		a2[p]=a1[i];
		p++;
	}
	for(int i=0;i<n*m;i++){
		if(a2[i]==camp){
			cout<<c<<" "<<r;
			break;
		}else{
			if(r==n){
				c+=1;
			}else{
				if(c%2==1){
					r+=1;
				}
				if(c%2==0){
					r-=1;
				}
			}
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}
