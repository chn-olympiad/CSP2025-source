#include<bits/stdc++.h>
using namespace std;
long long n,m,t,o,k=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>o;
	//cout<<n<<m<<o<<k;
	while(cin>>t){
		if(t>o){
			k++;
		}
		
	}
	//k=(k+n-1)/n;
	if(((k+n-1)/n)%2==1){
		cout<<(k+n-1)/n<<' '<<k-(n*((k+n-1)/n-1));
	}else{
		cout<<(k+n-1)/n<<' '<<n-(k-(n*((k+n-1)/n-1)))+1;
	}
	return 0;
}

