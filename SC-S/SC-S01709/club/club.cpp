#include<bits/stdc++.h>
using namespace std;
int t,n,r1,r2,r3;
int a[100010],b[100010],c[100010];
long long f,ma;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			r1=r1+a[i];
		}
		cout<<r1<<endl;
	}
	return 0;
} 