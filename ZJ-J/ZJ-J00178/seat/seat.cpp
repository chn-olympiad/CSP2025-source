#include <bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm,p;
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++){
		int x;
		cin>>x;
		if(i==1)
			p=x;
		a[x]++;
	}
	int cnt=0;
	for(int i=N;i>=p;i--){
		if(a[i])
			cnt++;
	}
	int x=1,y=1;
	if(cnt%n==0){
		y=cnt/n;
	}
	else{
		y=cnt/n+1;
	}
	if(y%2==1){
		x=cnt-(y-1)*n;
	}
	else{
		x=abs(cnt-(y-1)*n-n)+1;
	}
	cout<<y<<' '<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
