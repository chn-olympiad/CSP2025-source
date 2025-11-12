#include<bits/stdc++.h>
using namespace std;

int n,m,r;
bool cmp(int a,int b){
	return a>b;
}
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int z=n*m;
	cin>>r;
	a[1]=r;
	for(int i=2;i<=z;i++){
		cin>>a[i];
	}
	sort(a+1,a+z+1,cmp);
	int x=0;
	for(int i=1;i<=z;i++){
		if(a[i]==r){
			x=i;
			break;
		}
	}
	int lie,hang;
	if(x%n!=0){
		lie=floor(x/n)+1;
	}
	else{
		lie=x/n;
	}
	if(lie%2==0){
		hang=n-x%n+1;
	}
	else{
		if(x%n==0) hang=n;
		else hang=x%n;
	}
	cout<<lie<<" "<<hang;
	return 0;
}