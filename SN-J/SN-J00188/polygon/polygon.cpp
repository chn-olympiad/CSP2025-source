//吴启豪 - SN-J00188 - 西安滨河学校
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100000010],num;
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=3; i++) {
		for(int j=i; j<=3; j++) {
			for(int k=j; k<=3; k++) {
				if((a[i]+a[j]+a[k])>2*max(a[i],max(a[j],a[k]))){
					num++;
				}
			}
		}
	}
	cout<<num;
	return 0;
}
