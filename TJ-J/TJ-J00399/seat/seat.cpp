#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ren=n*m;
	int a[ren];
	for(int i=0;i<ren;i++){
		cin>>a[i];
	}
	int s=a[0];
	int temp=0;
	for(int i=0;i<ren;i++){
		if(a[i]<a[i+1]){
			temp=a[i];
			a[i]=a[i+1];
			a[i+1]=temp;
		}
	}
	int wei=0;
	for(int i=0;i<ren;i++){
		if(a[i]==s){
			wei=i+1;
		}
	}
	int lie=1;
	if(wei%m==0){
		lie=wei/m;
	}
	else{
		lie=wei/m+1;
	}
	int hang=1;
	if(lie%2!=0){
		hang=1+lie%wei;
	}
	else{
		if(lie%wei==0){
		hang=m-lie/wei;
		}
		else{
		hang=m-lie/wei-1;
		}
	}
	cout<<lie<<" "<<hang;
	return 0;
}
