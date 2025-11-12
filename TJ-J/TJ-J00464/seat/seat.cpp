#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	int c,r,b;
	cin>>c>>r;
	int a[c*r];
	for(int i=0;i<c*r;i++){
		cin>>a[i];
	}
	if((100-a[0]+1)%c==0){
		b=(100-a[0]+1)/c;
	}else{
		b=(100-a[0]+1)/c+1;
	}
	cout<<b<<" ";
	if(b%2==1){
		cout<<a[0]%c;
	}else{
		cout<<c-a[0]%c+1;
	}
	return 0;
}
