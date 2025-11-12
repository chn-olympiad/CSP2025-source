#include<bits/stdc++.h>
using namespace std;

int t,n,a[100100],b[100100],c[100100],m;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1;i<=n;i++){
				m+=max(a[i],max(b[i],c[i]));
		}
	}
	cout<<m;
	return 0;
}
