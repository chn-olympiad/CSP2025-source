#include<bits/stdc++.h>
using namespace std;
int n,m,ans,q;
long long a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=0;i<n;i++){
		cin>>q;
		if(q!=0){
			ans=ans*q;
		}
	}
	cout<<ans/998244353<<endl;
}
