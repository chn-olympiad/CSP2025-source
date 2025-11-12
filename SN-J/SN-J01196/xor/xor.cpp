/*
CSP-J 
姓名：魏诺澜
准考证号：SN-J01196
学校：西北工业大学附属中学 
*/ 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,k,ans,maxx;
int a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		bool t=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=1)t=1;
		}
		if(!t){
			cout<<n/2;
			return 0;
		}
	}
	int x=0;
	for(int l=1;l<=n;l++){
		x^=a[l-1];
		for(int r=l;r<=n;r++){
			x^=a[l];
			if(x==k){
				ans++;
				maxx=max(maxx,ans);
				x=0;
				l=r+1;
				r++;
				break;
			}
		}
	}
	cout<<maxx;
	return 0;
}
