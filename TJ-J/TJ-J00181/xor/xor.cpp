#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[500001],s[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,ct=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				ct++;
				i=j;
				break;
			}
		}
	}
	cout<<ct;
	return 0;
}
//神秘代码求过。。。 
