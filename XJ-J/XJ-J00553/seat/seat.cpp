#include<bits/stdc++.h>
using namespace std;
int n,m,b,c;
string a;
int main(){
	cin>>n>>m;
	cin>>a;
	a[0]==b;
	for(int i=1;i<=n*m;i++){
		for(int j=i;j<=n*m-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}                     
	for(int i=1;i<=n*m;i++){
		if(a[i]==b){
			if(i/n%2==0){
				cout<<i/n+3<<" "<<i%n-1;
				freopen("seat.in","r",stdin);
                freopen("seat.out","w",stdout);
				return 0;
			}else{
				cout<<i/n<<" "<<i%n+2;
				freopen("seat.in","r",stdin);
	            freopen("seat.out","w",stdout);
				return 0;
			}
		}
	}
	return 0;
}
