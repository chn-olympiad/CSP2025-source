#include<bits/stdc++.h>
using namespace std;
int n,m,p;
int a[110];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			p=i;
			break;
		}
	}
	cout<<(p-1)/n+1<<" ";
	if(((p-1)/n+1)%2==1){
		cout<<(p-1)%n+1;
	}
	else{
		cout<<n-(p-1)%n;
	}
	return 0;
}
