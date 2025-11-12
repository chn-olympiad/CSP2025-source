#include<bits/stdc++.h>
using namespace std;
int n,m,g,num=0,g1;
int b[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n][m];
	for(int i=1;i<=100;i++){
		b[i]=0;
	}
	cin>>g1;
	b[g1]++;
	for(int i=2;i<=n*m;i++){
		cin>>g;
		b[g]++;
	}
	for(int i=100;i>=g1;i--){
		num+=b[i];
	}
	cout<<(num+m-1)/m<<' ';
	if((num+m-1)/m%2==0){
		if(num%m==0)
		cout<<1;
		else
		cout<<n-num%m;
	}
	else{
		if(num%m==0)
		cout<<num;
		else
		cout<<num%m;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
