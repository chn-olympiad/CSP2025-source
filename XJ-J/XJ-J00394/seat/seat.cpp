#include <bits/stdc++.h>
using namespace std;
long long int n,m,num,r,wc;
long long int a[9999];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	num=n*m;
	for(int i=1;i<=num;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+num+1);
	for(int i=num;i>=1;i--){
		if(r==a[i]){
			wc=num-i+1;
			break;
		}
	}
	int lie;
	if(wc%m==0) lie=wc/m;
	else lie=(wc/m)+1;
	int hang;
	if(lie%2==0) hang=abs(wc-lie*m)+1; 
	else if(lie==1) hang=wc;
	else hang=abs(wc-lie*m)-1;
	cout<<lie<<' '<<hang;
	return 0;
}
