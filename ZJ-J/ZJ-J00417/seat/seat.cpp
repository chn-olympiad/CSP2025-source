#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s,cnt=1;
	cin>>s;
	for(int i=2;i<=n*m;i++){
		int z;
		cin>>z;
		if(z>s){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	if(((cnt-1)/n)%2==0){
		cout<<(cnt+n-1)/n<<" ";
		if(cnt%n==0){
			cout<<n;
		}
		else{
			cout<<cnt%n;
		}
	}
	else{
		cout<<(cnt+n-1)/n<<" ";
		if(cnt%n==0){
			cout<<1;
		}
		else{
			cout<<n-cnt%n+1;
		}
	}
	return 0;
}
