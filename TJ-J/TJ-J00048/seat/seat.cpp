#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int s=a[1];
		for(int i=1;i<=n*m;i++){
		sort(a+1,a+1+n*m,cmp);
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			int b=i;
			if(b%n==0){
				int t=b/n;
				cout<<t<<" ";
				if(t%2==0){
		int f=t*n-b+1;
		cout<<f;
	}else{
		int f=n-(t*n-b);
		cout<<f;
	}
			}else{
int t=b/n+1;
cout<<t<<" ";
if(t%2==0){
		int f=t*n-b+1;
		cout<<f;
	}else{
		int f=n-(t*n-b);
		cout<<f;
	}
}

}
}
	return 0;
}
