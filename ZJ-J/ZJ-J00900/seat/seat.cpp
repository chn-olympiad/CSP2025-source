#include<bits/stdc++.h>
using namespace std;
int n,m;
int g;
int cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>g;
	for(int i=1;i<n*m;i++){
		int x;
		cin>>x;
		if(x>g){
			cnt++;
		}
	}
	cout<<(cnt/n+1)<<" ";
	if(cnt/n+1&1){
		cout<<(cnt%n)+1;
	}
	else{
		cout<<n-(cnt%n);	
	}
	return 0;
}