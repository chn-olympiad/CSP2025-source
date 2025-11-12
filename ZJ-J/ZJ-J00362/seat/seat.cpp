#include<bits/stdc++.h>
using namespace std;
int n,m,fen;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>fen;
	int a,num=1;
	for(int i=1;i<n*m;i++){
		cin>>a;
		if(a>fen)num++;
	}
	int x=(num+n-1)/n,y=num%n;
	if(x%2==0){
		cout<<x<<" ";
		if(y==0){
			cout<<1;
		}else cout<<n-y+1;
	}else{
		cout<<x<<" ";
		if(num%n==0){
			cout<<n;
		}else cout<<y;
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
