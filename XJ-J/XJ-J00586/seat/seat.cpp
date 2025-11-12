#include<bits/stdc++.h>
using namespace std;
int n,m,s,im,z;
int a[105];
int tong[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=m*n;
	for(int i=1;i<=s;i++){
		cin>>a[i];
		tong[a[i]]++;
		if(i==1){
			im=a[1];
		}
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(n==1){
		int b=0;
		for(int i=100;i>=1;i--){
			if(tong[i]!=0){
				b++;
			}
			if(i==im){
				cout<<b<<" "<<1;
				return 0;
			}
		}
	}
	if(m==1){
		int d=0;
		for(int i=100;i>=1;i--){
			if(tong[i]!=0){
				d++;
			}
			if(i==im){
				cout<<1<<" "<<d;
				return 0;
			}
		}
	}
	for(int i=100;i>=1;i--){
		float e;
		if(tong[i]!=0){
			e++;
		}
		z=int(e)%n;
		if(ceil(e/n)%2==0){
			z=n-int(e)%n+1;
		}else{
			z=int(e)%n;
		}
		if(i==im){
			cout<<ceil(e/n)<<" "<<z;
			return 0;
		}
	}
	return 0;
}
