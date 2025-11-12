#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,ans=0;
int q[N],q1[N],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		q1[i]=q1[i-1]^q[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=i;k++){
			if(q1[i]^q1[k-1]==m) f[i]=max(f[i],f[k]+1);
		}
	} 
	cout<<f[n];
	return 0;
}
