#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			if(i==1){
				if(a[2]==1){
					cout<<1;
					return 0;
				}
			}
			else{
				if(a[1]==1){
					cout<<1;
					return 0;
				}
			}
		}
	}
	cout<<0;
	return 0;
}
