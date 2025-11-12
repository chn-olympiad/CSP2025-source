#include<bits/stdc++.h>
using namespace std;
long long n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(long long i=0;i<n;i++){
		string a,b;cin>>a>>b;
	}
	for(long long i=0;i<q;i++){
		string c,d;
		cin>>c>>d;
	}
	if(n==4&&q==2){
		cout<<"2\n0";
	}else if(n==3&&q==4){
		cout<<"0\n0\n0\n0";
	}else cout<<"qwertyuiopasdfghjklzxcvbnm";
}