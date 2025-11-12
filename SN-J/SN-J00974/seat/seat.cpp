#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[222];
cmp(int a,int b){
	if(a>b){
		return 1;
	}
	return 0;
}
int hang;
int lie;
int main()
{	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}int k=a[0];
	int j;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==k){
			j=i;
		}
	}if((j/n+1)%2==1){
		if((j+1)%n==0){
		hang=n;
	}
	else{
		hang=(j+1)%n;
	}
	if(j<=n){
		lie=1;
	}
	else{
		lie=(j+1-hang)/n+1;
	}
	}
	else{
	if(j%n!=0){
		hang=n-((j-1)%n+1);
	}
	else{
		hang=n;
	}
	if(hang==1){
		lie=(j+1-(j+1)%n)/n;
	}
	else{
		lie=(j+1-(j+1)%n)/n+1;
	}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
