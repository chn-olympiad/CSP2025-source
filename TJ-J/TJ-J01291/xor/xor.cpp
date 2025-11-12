#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e5+5;
int a[N];
int sum=0;
int main(){
	//remember freopen!!!
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int q=0;//all 1 or some 0 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			q=1;//some 0
		}
	}
	if(k!=0&&k!=1){
		cout<<0<<endl;
		return 0;
	}
	if(k==0){
		if(q==0){
			sum+=n-1;
			
		}
	}
	cout<<sum<<endl;
	return 0;
}
//I have nothing to say.Because I don't know what can I write now.Ok,just 7199.I wish I could get a nice return.
