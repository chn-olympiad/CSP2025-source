#include<bits/stdc++.h>
using namespace std;
long long a[105],n,m;
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
	long long r1=a[1],r2;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r1) r2=i;
	}
	long long q=r2/n+1;
	if(r2%n==0) {
		cout<<r2/n<<" "<<r2-(q-2)*n;
	}
	else if(q%2==1){
		cout<<q<<" "<<r2-(q-1)*n;
	}
	else{
		cout<<q<<" "<<n-(r2-(q-1)*n)+1;
	}
	return 0;
}
