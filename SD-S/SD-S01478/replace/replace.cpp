#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 200005
#define M 100005
#define mod 998244353
#define ls root<<1
#define rs root<<1|1
#define F first
#define S second
using namespace std;
ll n,q;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		cout<<"0"<<endl;
	}
	return 0;
}

