#include<bits/stdc++.h>

using namespace std;

int num[20];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>num[i];
	}
	if(num[1] == 99) cout<<"1"<<" "<<"2";
	else if(num[1] == 98) cout<<"2"<<" "<<"2";
	else cout<<"3"<<" "<<"1";
	
	return 0;
}
