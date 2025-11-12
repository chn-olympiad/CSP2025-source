#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n;
struct node{
	int x,y,z;
}a[100005];
bool cmp(node A,node B){
	int s1[3] = {A.x,A.y,A.z};
	int s2[3] = {B.x,B.y,B.z};
	sort(s1,s1+3),sort(s2,s2+3);
	return s1[2]-s1[1]>s2[2]-s2[1];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		ll cnt1,cnt2,cnt3,ans;
		cnt1=cnt2=cnt3=ans=0;
		for(int i = 1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		sort(a+1,a+n+1,cmp);
		for(int i = 1;i<=n;i++){
			int mx = max(a[i].x,max(a[i].y,a[i].z));
			if(mx==a[i].x){
				if(cnt1<n/2) ans+=mx,cnt1++;
				else ans+=max(a[i].y,a[i].z);
			}
			else if(mx==a[i].y){
				if(cnt2<n/2) ans+=mx,cnt2++;
				else ans+=max(a[i].x,a[i].z);
			}
			else{
				if(cnt3<n/2) ans+=mx,cnt3++;
				else ans+=max(a[i].x,a[i].y);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
