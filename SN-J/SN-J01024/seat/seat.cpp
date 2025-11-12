#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n+1);
	for(int i=1;i<=n*m;i++){
		if(b==a[i]){
			if(i%n==0){
				if((i/n)%2==0){
					cout<<i/n<<" "<<1;
				}else{
					cout<<i/n<<" "<<n;
				}	
			}else{
				if((i/n+1)%2==0){
					cout<<i/n+1<<" "<<n-(i-(i/n)*n)+1;
				}else{
					cout<<i/n+1<<" "<<i-(i/n)*n;
				}
			}
		}
	}
	return 0;
}
