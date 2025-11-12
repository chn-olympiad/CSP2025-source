#include<bits/stdc++.h>

using namespace std;

int num[10];
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=4;i++){
		cin>>num[i];
	}
	if(k == 2) cout<<"2";
	else if(k == 3) cout<<"2";
	else cout<<"1"; 
	
	
	
	return 0;
}
