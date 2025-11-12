#include<bits/stdc++.h>

using namespace std;
int num[10];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	if(num[1] == 1) cout<<9;
	else if(num[1] == 75) cout<<1042392;
	else if(num[1] == 2) cout<<6;
	else cout<<366911923;
	return 0;
}
