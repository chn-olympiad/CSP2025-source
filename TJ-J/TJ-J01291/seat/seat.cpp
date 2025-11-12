#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=150;
int a[N];
int b[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int r=a[1];
	int p=1;
	for(int i=100;i>=1;i--){
		for(int j=1;j<=n*m;j++){
			if(a[j]==i){
				b[p]=i;
				p++;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(b[i]==r){
			int e=i%n;
			int t=i/n;
			t+=1;
			if(e==0){
				e=n;
				t=i/n;
			}
			if(t%2==0){
				e=n-e+1;
			}
			cout<<t<<" "<<e<<endl;
		}
	}
	return 0;
}
//Just 7199.
