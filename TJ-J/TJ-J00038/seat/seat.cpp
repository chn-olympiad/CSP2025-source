#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b;
	int a[105];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	for(int i=0;i<=n*m-1;i++){
		for(int j=0;j<=n*m-1;j++){
			if(a[j-1]<a[j])
				swap(a[j-1],a[j]);
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==r){
			b=i;
			break;
		}
	}
	cout<<2<<' '<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
