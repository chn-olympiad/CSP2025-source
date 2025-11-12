#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct news{
	int c1,c2,c3;
}a[10005];
bool cmp(news x,news y){
	return x.c1>x.c2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
		}
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<=n/2;i++){
			ans+=a[i].c1;
		}
	}
	return 0;
}
