#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int MAXN=1e5+5;
ll t,n,m[4];
struct Node{
	int x,y,z;
}a[MAXN];
bool cmp1(Node l,Node r){
	return l.x+max(r.y,r.z)>=r.x+max(l.y,l.z);
}
bool cmp2(Node l,Node r){
	return l.y+max(r.x,r.z)>=r.y+max(l.x,l.z);
}
bool cmp3(Node l,Node r){
	return l.z+max(r.x,r.y)>=r.z+max(l.x,l.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ll ans=0;
		for(int i=1;i<=n;i++){
			int cnt=0,pos=0;
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x==max(a[i].x,max(a[i].y,a[i].z))) pos=1,cnt++;
			if(a[i].y==max(a[i].x,max(a[i].y,a[i].z))) pos=2,cnt++;
			if(a[i].z==max(a[i].x,max(a[i].y,a[i].z))) pos=3,cnt++;
			ans+=max(a[i].x,max(a[i].y,a[i].z));
			if(cnt==1) m[pos]++;
		}
		if(max(m[1],max(m[2],m[3]))>n/2){
			ans=0;
			if(m[1]>n/2){
				sort(a+1,a+n+1,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].x;
				}
				for(int i=n/2+1;i<=n;i++){
					ans+=max(a[i].y,a[i].z);
				}
			}
			else if(m[2]>n/2){
				sort(a+1,a+n+1,cmp2);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].y;
				}
				for(int i=n/2+1;i<=n;i++){
					ans+=max(a[i].x,a[i].z);
				}
			}
			else{
				sort(a+1,a+n+1,cmp3);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].z;
				}
				for(int i=n/2+1;i<=n;i++){
					ans+=max(a[i].x,a[i].y);
				}
			}
			cout<<ans<<"\n";
		}
		else{
			cout<<ans<<"\n";
		}
	}
	return 0;
}
