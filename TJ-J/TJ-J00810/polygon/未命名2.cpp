#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("r","seat.in",stdin);
	freopen("w","seat.out",stdout);
	int n,m,a[105],b[105],ans,q=0;
	cin>>n>>m;
	int A=n*m;
	for(int i=0;i<A;i++){
		cin>>a[i];
	}
	int an=a[0];
	for(int i=0;i<A;i++){
		for(int j=0;j<A;j++)
		if(a[j]<a[j-1]){
			swap(a[j],a[j-1]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[q]==an){
				cout<<j<<' '<<i;
				return 0;
			}
			q++;
		}
		i++;
		for(int j=m;j>=0;j--){
			if(a[q]==an){
				cout<<j<<' '<<i;
				return 0;
			}
			q++;
		}
	}
	return 0;
}
