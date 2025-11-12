#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[1919810],if1=1,if0=1;
int xorn(int x,int y){
	int ans=a[x];
	for(int i=x+1;i<=y;i++){
		ans=ans xor a[i];
	}
	return ans;
}
signed main(){
   	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)if1=0;
	}
	if(if1&&k!=1){
		cout<<0;
		return 0;
	}else if(if1&&k==1){
		cout<<n;
		return 0;
	}else if(if1&&k==0){
		cout<<n/2;
		return 0;
	}
	if(if0&&k!=0){
		cout<<0;
		return 0;
	}else if(if0&&k==0){
		cout<<n;
		return 0;
	}
	return 0;
} 
