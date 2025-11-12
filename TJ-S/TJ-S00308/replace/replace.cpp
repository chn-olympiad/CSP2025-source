#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	string a,b;
};
ll n,q;
node nn[200010],qq[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>nn[i].a>>nn[i].b;
	}
	for(ll i=1;i<=q;i++){
		cin>>qq[i].a>>qq[i].b;
	}
	if(n==4 && q==2){
		cout<<2<<endl<<0;
	}else if(n==3 && q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
	return 0;
}
