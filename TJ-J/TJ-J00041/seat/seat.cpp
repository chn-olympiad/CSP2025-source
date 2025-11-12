#include<algorithm> 
#include<cstdio>
#include<iostream>  
#include<cstring> 
#include<algorithm>  
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int mark=1;
	int fuzhu;
	int lie,hang;
	cin>>n>>m;
	int a[n*m+1];
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n*m;i++){
		if(a[1]<a[i]){
			mark++;
		}
	}
	if(mark<=n){
		cout<<1<<" "<<mark;
	}
	if(mark>n){
		fuzhu = mark%n;
		lie=mark/n+1;
		if(lie%2!=0){
			if(fuzhu==0){
				hang=n;
			}
			else{
				hang=fuzhu;
			}
		}
		if(lie%2==0){
			if(fuzhu==0){
				hang=1;
			}
			else{
				hang=n-fuzhu+1;
			}
		}
	cout<<lie<<" "<<hang;	
	}
	return 0;	
}
