#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int x=a[0];
	for(int i=0;i<n*m-1;i++){
		for(int j=1;j<n*m;j++){
			if (a[i]>a[j]){
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	sort(a,a+n*m);
	int nn;
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			nn=i;
		}
	}
	int now=n*m-nn+1;
	int nom;
	if(now%m==0){
		nom=now/m;
	}
	else{
		nom=now/m+1;
	}
	int non;
	non=now%n;
	if(now%2==0){
		non=n-non;
	}
	
	
	cout<<nom<<" "<<non;
	return 0;


}
