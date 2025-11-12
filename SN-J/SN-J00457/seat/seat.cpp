#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,summ=1,a,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	summ=1;
	for(int i=2;i<=n*m;i++){
		cin>>y;
		if(y>x){
			summ=summ+1;
		}
	}
	a=summ/n;
	b=summ%n;
	if(b==0){
		if(a%2==0){
			cout<<a<<' '<<1;
		}else{
			cout<<a<<' '<<n;
		}
	}else{
		a=a+1;
		if(a%2==0){
			cout<<a<<' '<<n-b+1;
		}else{
			cout<<a<<' '<<b;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
