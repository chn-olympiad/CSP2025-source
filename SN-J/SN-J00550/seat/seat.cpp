#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int xiaor=a[0];
	sort(a,a+n*m,cmp);
	int sz;
	for(int i=0;i<n*m;i++){
		if(a[i]==xiaor){
			sz=i+1;
		}
	}
	int lie=0,hang;
	for(int i=1;i<=m;i++){
		if(sz==n*i){
		lie=i;	
		}
	}
	if(lie==0){
		lie=sz/n+1;
	}
	if(lie%2==0){
		if(sz%n==0){
			hang=1;
		}else{
		hang=(n+1)-(sz%n);
		}
	}else{
		if(sz%n==0){
			hang=n;
		}else{
			hang=sz%n;
		}
	}
	cout<<lie<<' '<<hang;
	fclose(stdin);
	fclose(stdout);
return 0;
}
