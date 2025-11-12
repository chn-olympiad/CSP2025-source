#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	int i=1,j=1,v=1;
	sort(a+1,a+n*m+1);
	for(int k=n*m;k>=1;k--){
		if(a[k]==r){
			cout<<j<<" "<<i;
		}
		else{
			if(v==1 and i<n){
				i++;
			}
			else if(v==1 and i==n){
				j++;
				v=0;
			}
			else if(v==0 and i>1){				
				i--;
			}
			else{
				j++;
				v=1; 
			}
		}
	}
	return 0;
}
