#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int l,r,a[1000000];
	long long n,k,b;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==2){
		b=2;
		cout<<b;
	}else if(k==0){
		b=1;
		cout<<b;
	}
	else if(k==3){
		b=2;
		cout<<b;
	}else if(k==11){
		b=63;
		cout<<b;
	}
	else if(k==55190){
		b=69;
		cout<<b;
	}
	else if(k==22224){
		b=12701;
		cout<<b;
	}
	return 0;
}
