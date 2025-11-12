#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int x[500005];
int s;
int last=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x[i]=(x[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>last;j--){
			if((x[i]^x[j-1])==k){
				s++;
				last=i;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}

