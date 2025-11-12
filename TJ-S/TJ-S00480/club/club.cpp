#include<bits/stdc++.h>
using namespace std;
int t,n,s,a1[100005],a2[100005],a3[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		sort(a1+1,a1+1+n,cmp);
		sort(a2+1,a2+1+n,cmp);
		sort(a3+1,a3+1+n,cmp);
		for(int i=1;i<=n/2;i++){
			s+=a1[i]+a2[i]+a3[i];
		}
		cout<<s;
	}
	return 0;
}
