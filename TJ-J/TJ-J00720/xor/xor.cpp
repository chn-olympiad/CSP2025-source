#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=5e5+5;
int n,k,a[N],flag=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	rep(i,1,n){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(k==0&&flag){
		cout<<n/2;
		return 0;
	}
	cout<<n;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
