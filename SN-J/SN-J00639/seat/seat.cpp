#include<bits/stdc++.h>
using namespace std;
int m,n,c,r,a[110],b[110],f[110],R[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int ps=n*m;
	for(int i=1;i<=ps;i++){
		cin>>a[i];
		f[a[1]]=1;
	}
	sort(a+1,a+ps+1);
	int j=ps;
	for(int i=1;i<=ps;i++){
		b[i]=a[j];
		j--;
	}
	int s=1;
	for(int i=n;i>0;i--){
		R[s]=i;
		s++;
	}
	for(int i=1;i<=ps;i++){
		if(f[b[i]]==1){

			if(i%n==0&&i%n<n){
				c=1;
			}else c=i/n+1;
			if(i%n==0){
				r=R[i%n+1];
			}else if(c%2==0){
				r=R[i%n];
			}else r=i%n;

		}
	}
	cout<<c<<" "<<r;
	return 0;
}
