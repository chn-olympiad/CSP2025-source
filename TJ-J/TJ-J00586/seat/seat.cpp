#include<bits/stdc++.h>
using namespace std;

int n,m,s,cnt;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=2;i<=n*m;i++){
		int x;
		cin>>x;
		if(x>s)cnt++;
	}
	cnt++;
	cout<<(cnt-1)/n+1<<' ';
	if(((cnt-1)/n)%2){
		int t=(cnt-1)%n;
		cout<<n-t;
	}else{
		int t=(cnt-1)%n;
		cout<<t+1;
	}
	
	
	return 0;
}
