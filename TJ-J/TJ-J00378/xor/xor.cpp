#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,s,maxn=-1,h=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		bool f=0;
		for(int j=n;j>=i;j--){
			s=a[i];
			for(int z=i+1;z<=j;++z){
				s^=a[z];
				if(s==m){
					break;
				}
			}
			if(s==m && f==0){
				h++;
				f=1;
			}
		}
	}
	cout<<h;
	return 0;
}
