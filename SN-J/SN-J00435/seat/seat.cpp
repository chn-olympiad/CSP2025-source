//SN-J00435  Ðì×Ó³½  ³¤Çì°ËÖÐ
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int b=a[1];
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	int c;
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			c=i;
		}
	}
	if(c%n==0){
		if((c/n)%2==0){
			cout<<c/n<<" 1";
		}
		else{
			cout<<c/n<<" "<<n;
		}
	}
	else{
		if((c/n)%2==0){
			cout<<c/n+1<<" "<<c%n;
		}
		else{
			cout<<c/n+1<<" "<<n-(c%n-1);
		}
	}
	return 0;
}
