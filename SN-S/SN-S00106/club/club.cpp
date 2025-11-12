#include<bits/stdc++.h>
using namespace std;
int b[5],vis[100005],n,ans;
struct man {
	int a1,a2,a3,id;
} a[100005];
bool cmp(man a,man b){
	return a.a1>b.a1;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		ans=0;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i].a1;
		}
		cout<<ans<<endl;
	}





	fclose(stdin);
	fclose(stdout);
	return 0;
}
