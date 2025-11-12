#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int a[N];
bool A=1,B=1,C=1;
int main(){
	freopen("xor.in","r",stdin); freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) A=0;
		if(a[i]>1) B=0;
		if(a[i]>255) C=0;
	}
	if(A) cout<<"0\n";
	else if(B){
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt1++;
			if(a[i]==0) cnt0++;
		}
		cout<<cnt0+k<<"\n";
	}else{
		cout<<"I can't do it!\n";
	}
	return 0;
}