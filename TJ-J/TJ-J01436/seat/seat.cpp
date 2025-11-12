#include<bits/stdc++.h>
using namespace std;
int a[250];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,l=0;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int o=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==o){
			l=i;
			break;
		}
	}
	if(l%n==0){
		if((l/n)%2!=0){
			cout << l/n << " " << n;
			return 0;
		}
		else{
			cout << l/n << " " << "1";
			return 0;
		}
    }
	else{
		if((l/n)%2!=0){
			cout << l/n+1 << " " << n-(l%n)+1;
			return 0;
		}
		else{
			cout << l/n+1 << " " << l%m;
			return 0;
		}
	}
	return 0;
} 
