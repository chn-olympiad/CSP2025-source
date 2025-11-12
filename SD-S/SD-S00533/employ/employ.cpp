#include<bits/stdc++.h>
#define IXcape cout<<endl;return 0
#define Venti cout<<"\nVenti!\n"
#define int long long
using namespace std;
const int V=;

inline
void qmi(int a,int b){
	int ans=1,base=a;
	while(b>0){
		if(b&1) ans*=base;
		base*=base;
		b>>1;
	}return ans;
}

inline
void getp(int x){
	for(int i=2;i<=x;i++){
		if(!st[i]) p[++cnt]=i;
		for(int j=0;p[j]<x/i;j++){
			st[p[j]*i]=1;
			if(x%j==0) break;
		} 
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	cout<<n; 
	IXcape;
}
/*
静候那送归我的高天之歌。 
*/

