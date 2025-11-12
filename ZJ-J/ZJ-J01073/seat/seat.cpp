#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,a[200],t;
bool cmp(int x,int y){
	return (x>y);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n*m;i++)cin>>a[i];
	k=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(i=1;i<=n*m;i++){
		if(a[i]==k){
		j=i;
		break;	
		} 
	}
	for(i=1;i<=m;i++){
		if(i%2){
			for(int l=1;l<=n;l++){
				t++;
				if(t==j){
					cout<<i<<" "<<l;
					break;
				}
		  }
		}
		else {
			for(int l=n;l>=1;l--){
				t++;
				if(t==j){
					cout<<i<<" "<<l;
					break;
				}
			}
		}
	}
	return 0;
}
