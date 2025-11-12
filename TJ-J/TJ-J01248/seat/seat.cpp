#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int q=a[1],w;
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==q){
			w=n*m-i+1;
		}
	}
	if(w%n==0){
		if((w/n)%2==1){
			cout<<w/n<<" "<<m;
		}
		else{
			cout<<w/n<<" "<<1;
		}
	}
	else{
		if((w/n)%2==0){
			cout<<(w/n)+1<<" "<<w%n;
		}
		else{
			cout<<(w/n)+1<<" "<<m+1-w%n;
		}
	}
	
	
	return 0;
}
