#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,nn=1,mm=1;
	cin >>n>>m;
	int a[n*m+5],xiaoming;
	cin >> xiaoming;
	a[1]=xiaoming;
	if(n==1&&m==1){
		cout << "1 1";
	}
	for(int i=2;i<=n*m;i++){
		cin >>a[i];
	}
	sort(a+1,a+n*m+1);
	for(int i=m*n;i>=2;i--){
		if(a[i]==xiaoming){
			cout << mm << ' ' << nn;
		}
		int f=0;
		if(nn==n&&mm%2==0){
			nn--;
			f++;
		}
		if(nn==1&&mm%2==1&&f==0){
			nn++;
			f++;
		}
		if(nn==n&&mm%2==1&&f==0){
			mm++;
			f++;
		}
		if(nn==1&&mm%2==0&&f==0){
			mm++;
			f++;
		}
		else if(mm%2==1&&f==0)
			nn++;
		else if(mm%2==0&&f==0)
			nn--;
		
			
	}
	return 0;
} 
