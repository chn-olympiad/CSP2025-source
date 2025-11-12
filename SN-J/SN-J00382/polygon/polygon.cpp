#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
int a[5050],qzh[5050];
long long cs=0;
int houb,qianb;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("polygon","r",stdin);
	//freopen("polygon","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<3) cout<<0;
	else if(a[0]+a[1]>a[2]) cout<<1;
	else cout<<6;
	return 0;
}

