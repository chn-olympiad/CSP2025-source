#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,cnt=0,a,b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>x;
	for(int i=1;i<=n*m-1;i++){
		cin>>y;
		if(y>x){
			cnt++;
		}
	}
	cnt++;
	if(cnt%n==0){
		a=cnt/n;
	}else{
		a=cnt/n+1;
	}
	if(a%2==1){
		if(cnt%n==0){
			b=m;
		}else{
			b=cnt%n;
		}
	}else{
		if(cnt%n==0){
			b=1;
		}else{
			b=m-cnt%n+1;
		}
	}
	cout<<a<<' '<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
