#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long m,n,a[1000],r=1,z,c=1,b[110][110];
	cin>>n>>m;
	z=m*n;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+z+1,greater<int>());
	for(int i=1;i<=z;i++){
		if(r==a[i]){
			r=i;
			break; 
		}
	}
	z=0;
	int q=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(r==q){
					cout<<i<<" "<<j;
					q++;
					break;
				}
				q++;
			}
		}else{
			for(int j=1;j<=n;j++){
				if(r==q){
					cout<<i<<" "<<j;
					q++;
					break;
				}
				q++;
			}
		}
		if(q-1==r){
			break;
		}
	}
	return 0;
}
