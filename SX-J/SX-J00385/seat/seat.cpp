#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],hang=1,lian=1,k=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++){
		if(a[1]<a[i]){
			hang+=1;lian+=0;
			if(hang>m){
				hang=n+1-k;

				k++;
				lian++;
			}
		}else if(a[1]>a[i]){
			hang+=0;lian+=0;
		}
	}cout<<lian<<" "<<hang;
	return 0;
}