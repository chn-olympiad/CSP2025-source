#include<bits/stdc++.h>
using namespace std;
int n,m,fs[1010],xr,pm=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>xr;
	for(int i=1;i<n*m;i++){
		cin>>fs[i];
		if(fs[i]>xr){
			pm++;
		}
	}
	int h=pm/n,l;
	if(pm%n!=0){
		h++;
	}
	if(h%2==1){
		l=pm-(h-1)*n;
	}
	else{
		l=n-(pm-(h-1)*n)+1;
	}
	cout<<h<<" "<<l;
	return 0;
}  	
