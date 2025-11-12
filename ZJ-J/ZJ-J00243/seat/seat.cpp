#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],q,f,k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	q=n*m;
	for(int l=1;l<=q;l++){
		cin>>a[l];
	}
	k=a[1];
	sort(a+1,a+1+q);
	f=0;
	for(int l=1;l<=q;l++){
		if(k==a[l]){
			f=q-l+1;
			break;
		}
	}
	int i=1,j=1,q=1;
	f--;
	for(int l=1;l<=f;l++){
		if(j+q<=n and j+q>=1){
			j+=q;
		}
		else{
			if(q==1){
				i++;
				q=-1;
				j=n;
			}
			else{
				i++;
				q=1;
				j=1;
			}
		}
	}
	cout<<i<<" "<<j;
	return 0;
}
