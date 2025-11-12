//李紫曌 SN-S00373 西安滨河学校
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n[10111],a[10111],b[10111],c[10111],ans,zs,n;
int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0; i<t; i++) {
		cin>>n[i];
		ans=n[i]/2;
		for(int j=0; j<n[i]; j++) {
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>=b[j]&&a[j]>=c[j]) {
				n=a[j];
				sort(a,a+n[i]);
				if(n==a[0]||n==a[1]){
					zs+=n;
				}
			}else if()
		}
	}
	return 0;
}
