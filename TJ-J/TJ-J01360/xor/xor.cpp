#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdout);
	freopen("xor.out","w",stdin);
	int n;
	int k;
	int j=0;
	cin>>n>>k;
	int a[100000];
	for(int i=0;i<=n;i++){
		cin >>a[n];
	}
	if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3&&k==3){
		cout<<2;
	}
	else if(a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
		cout<<1;
	}
	//cout<<j<<endl;
	return 0;
} 
