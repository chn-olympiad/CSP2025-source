#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int uy=0;
	sort(a+1,a+1+n);
	uy+=a[1];
	uy+=a[2];
	int op=0;
	if(n<=3){
		if(uy+a[3]>a[n]*2){
			op++;
		}
	}
	for(int i=3;i<n;i++){
		uy+=a[i];
		if(uy>a[n]*2){
			op++;
		}
	}
	cout<<op;
	return 0;
}
