#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],ans = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<n*m;i++){
		cin>>a[i];
		if(a[i]>a[0]) ans++;
	}
	if(ans/n%2 == 0){
		cout<<(ans+n-1)/n<<" "<<(ans-1)%n+1;
	}
	else{
		cout<<(ans+n-1)/n<<" "<<n-(ans-1)%n;
	}
}
