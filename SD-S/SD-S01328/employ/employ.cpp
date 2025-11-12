#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[1000];
string s;
long long js=1;
int main(){
	freopen("employ","r",stdin);
	freopen("employ","w",stdout);
cin>>n>>m>>s;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	js=js%998244353;
	js*=i;
	js=js%998244353;
}
cout<<js;
	return 0;
} 
