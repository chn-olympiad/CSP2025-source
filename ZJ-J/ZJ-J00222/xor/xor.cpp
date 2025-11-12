#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k,a[MAXN],s[MAXN];
int jisuan(int x){ //2^x
	int ans=1;
	while(x--) ans*=2;
	return ans;
}
int Xor(int a,int b){ //a xor b
	int ans=0,mi=0;
	while(a>0||b>0){
		if(a%2!=b%2) ans+=jisuan(mi);
		a/=2,b/=2,mi++;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=Xor(s[i-1],a[i]);
	} 
	int l,r=1,lastr=1,ans=0;
	while(r<=n){
		int l=lastr+1;
		while(l<=r){
			if(Xor(s[l-1],s[r])==k){
				lastr=r,ans++;
				break;
			}
			l++;
		}
		r++;
	}
	cout<<ans;
	return 0;
}                            
