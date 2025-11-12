#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,id;
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){id=i;break;}
	}
	cout<<(id+n-1)/n<<" ";
	if(((id+n-1)/n)&1){
		if(id%n==0)cout<<n<<endl;
		else cout<<id%n<<endl;
	}
	else{
		if(id%n==0)cout<<1<<endl;
		else cout<<n-id%n+1;
	}
} 
