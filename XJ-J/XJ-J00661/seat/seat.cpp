#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,r = 0,c = 0;
	cin>>n>>m;
	int num[n*m];
	int a[n*m-1];
	int pm = n*m+1;
	if(n<=1 && m<=1){
		cout<<1<<" "<<1;
	}
	for(int i = 0;i<=n*m-1;i++){
		cin>>num[i];
	}
	for(int i = 1;i<=n*m-1;i++){
		if(num[0]>num[i]){
			pm--;
		}
	}
	for(int i = 0;i<n*m;i++){
		if(pm == i+1){
			//c列 r行
			//m列 n行 
			if(pm/n % 2 == 0){
				c = (pm-1)/n+1;
			    r = pm%m+1;
			    cout<<c<<" "<<r;
			}else{
				c = pm/n;
				r = pm/m-1;
				cout<<c<<" "<<r;
			}
		}
	}
}
