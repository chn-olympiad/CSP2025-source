#include<bits/stdc++.h>;
using namespace std;
long long n,a,b,c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>a>>b>>c;
		int sum=a+b+c;
		int maxn=max(a,max(b,c));
		if(sum>2*maxn) cout<<1;
		else cout<<0;
	}
	return 0;
} 
