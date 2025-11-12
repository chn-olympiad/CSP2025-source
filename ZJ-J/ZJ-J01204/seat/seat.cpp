#include<bits/stdc++.h>
using namespace std;
int a[105],n,m;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			f=i;
			break;
		}
	}
	if((f+n-1)/n%2==1){
		cout<<(f+n-1)/n<<" ";
		if(f%n==0) cout<<n;
		else cout<<f%n;
	}
	else{
		cout<<(f+n-1)/n<<" ";
		if(f%n==0) cout<<1;
		else cout<<n-f%n+1;
	}
	return 0;
}
