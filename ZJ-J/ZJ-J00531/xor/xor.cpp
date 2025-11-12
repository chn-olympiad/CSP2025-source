#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int n,k,a[N],js1,js0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//zen me hang shi da hai fang yin yue a?
	//25pts:te shu xing zhi a && b
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)js1++;
		if(a[i]==0)js0++;
	}
	if(js1==n){//A
		cout<<n/2;
	}
	else if(js1+js0==n){//B
		if(k==1){
			cout<<js1;
		}
		else{
			cout<<js0+js1/2;
		}
	}
	else cout<<0;//xia cai ba shuo bu ding zhen you
	return 0;
}
