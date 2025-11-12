#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a,b,c;
bool cmp(int q,int p){
	return q>p;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n>>a>>b>>c;
	if(a+b+c>2*max(a,max(b,c)))
		cout<<1;
	else 
		cout<<0;
	return 0; 
}
