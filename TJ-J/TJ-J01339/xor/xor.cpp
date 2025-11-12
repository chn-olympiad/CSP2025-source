#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cin in
#define cout out
#define endl '\n'
ll n,k;
ll a[500005]={};
ll dfs(int i,int l){
	if(i==n && l==k){
		return 1;
	}else if(i==n){
		return 0;
	}else if(l==k){
		return dfs(i+1,a[i])+1;
	}
	return max(dfs(i+1,l^a[i]),dfs(i+1,a[i]));
}
int main(){
	fstream in,out;
	in.open("xor.in",ios::in);
	out.open("xor.out",ios::out);
	cin >> n >> k;
	bool ta=true,tb=true;
	ll bs=0;
	ll k1=k;
	ll a1;
	for(int i=0;i<n;i++){
		cin >> a[i];
		a1=a[i];
		if(a[i]!=1){
			ta=false;
		}
		if(a[i]>1){
			tb=false;
		}
		if(a[i]==1)bs++;
		int s=0;
		while(a1!=0){
			if((k1>>s)%2==1){
				k1-=1<<s;
			}
			a1/=2;
			s++;
		}
	}
	if(ta){
		if(k==1){
			cout << n << endl;
		}else{
			cout << 0 << endl;
		}
	}else if(tb){
		if(k==1){
			cout << bs << endl;
		}else{
			cout << 0 << endl;
		}
	}else if(k1!=0){
		cout << 0 << endl;
	}else{
		cout << dfs(1,a[0]) << endl;
	}
	return 0;
}