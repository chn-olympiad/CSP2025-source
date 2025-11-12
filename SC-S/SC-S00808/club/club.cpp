#include<bits/stdc++.h>
using namespace std;
int t,n,da,f[10];
struct s{
	int a[10],x;
}ans[10010];
bool cmp(int i,int j){
	return (ans[i].a[1]+ans[i].a[2]+ans[i].a[3])>(ans[j].a[1]+ans[j].a[2]+ans[j].a[3]); 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++){
		cin>>n;
		da=0;
		for(int i=1;i<=n;i++){
			cin>>ans[i].a[1]>>ans[i].a[2]>>ans[i].a[3];
			if(ans[i].a[1]>ans[i].a[2]&&ans[i].a[1]>ans[i].a[3]){
				ans[i].x=1;
			}else if(ans[i].a[2]>ans[i].a[1]&&ans[i].a[2]>ans[i].a[3]){
				ans[i].x=2;
			}else{
				ans[i].x=3;
			}
		}
		sort(ans+1,ans+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(f[ans[i].x]<n/2){
				da+=ans[i].a[ans[i].x];
				f[ans[i].x]++;
			}else{
				da+=max(ans[i].a[(ans[i].x+1)%3],ans[i].a[(ans[i].x+2)%3]);
				if(ans[i].a[(ans[i].x+1)%3]>=ans[i].a[(ans[i].x+2)%3]){
					f[(ans[i].x+1)%3]++;
				}else{
					f[(ans[i].x+2)%3]++;
				}
			}
		}
		cout<<da;
	}
	return 0;
} 