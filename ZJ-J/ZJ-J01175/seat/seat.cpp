#include<bits/stdc++.h>
using namespace std;
int n,m,a[100],r;
bool pd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	r=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+(n*m),pd);
	int i=0;
	for(int j=1;j<=m;j++){
		for(int k=1;k<=n;k++){
			if(a[i]==r){
				cout<<j<<" "<<k;
			}
			i++;
		}
		j++;
		if(j>m)break;
		for(int k=m;k>0;k--){
			if(a[i]==r){
				cout<<j<<" "<<k;
			}
			i++;
		}
	}
	return 0;
}
