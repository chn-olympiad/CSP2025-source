#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000],r=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}r=a[0];
	for(long long i=0;i<n*m;i++){
		for(long long k=i;k<n*m;k++){
			if(a[k]<a[i]){
				swap(a[k],a[i]);
			}
		}
	}if(a[0]==r){
		cout<<1<<" "<<1;
	}else{
		cout<<n<<" "<<m;
	}return 0;
}