//SN-S00259
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a1[100020],a2[100020],a3[100020];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans = 0;
		int tmp = 0;
		for(int i = 1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			tmp+=a2[i];
			tmp+=a3[i];
		}
		if(n==2){
			ans = max(a1[1]+a2[2],max(a1[1]+a3[2],max(a2[1]+a1[2],max(a2[1]+a3[2],max(a3[1]+a1[2],max(a3[1],a2[2]))))));
			cout<<ans<<endl;
			continue;
		}
		if(!tmp){
			sort(a1+1,a1+1+n,cmp);
			for(int i = 1;i<=n/2;i++){
				ans+=a1[i];
			}
		}
		else{
			for(int i = 1;i<=n;i++){
				ans+=max(a1[i],a2[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
