#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int n,a[105],n1,n2,n3;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	if(n==3){
		cin>>n1>>n2>>n3;
		int maxn=max(max(n1,n2),n3);
		if(n1+n2+n3>maxn*2) cout<<1;
		else cout<<0;
	}else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
