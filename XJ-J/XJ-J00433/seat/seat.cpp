#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,c;
	cin>>n>>m;
	b=n*m;
	int a[b];
	for(int i=0;i<b;i++){
			cin>>a[i];
		}
	sort(a,a+b);
	for(int i=0;i<=b;i++){
		if(a[0]==a[i]){
			c=i;
 			break;}
		}
 		for(int i=0;i<b;i++){
 			if(c<m*i&&c<=n){
 				cout<<c+1<<" "<<i+1;
 				break;
 			}}
	return 0;}
