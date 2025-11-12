#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[150];
int pos;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])pos++;
	}
	pos++;
	int x=0;
	if(pos%n==0)x=pos/n;
	else x=pos/n+1;
	cout<<x<<" ";
	pos-=(x-1)*n;
	if(x&1){
		cout<<pos;
	}else{
		cout<<n-pos+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
