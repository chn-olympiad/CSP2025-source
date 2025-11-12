//吴启豪 - SN-J00188 - 西安滨河学校 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1000010],f=1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++ ){
		if(a[i]!=1){
			f=0;
		}
	}
	if(f){
		cout<<0;
	}
	cout<<1; 
	
	return 0;
}
