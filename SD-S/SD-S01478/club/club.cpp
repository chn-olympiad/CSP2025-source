#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 100005
#define M 1000005
#define mod 998244353
#define ls root<<1
#define rs root<<1|1
#define F first
#define S second
using namespace std;
ll t,ans;
struct node{
	ll x,y,z;
}a[N];
struct fg{
	ll x,y,z;
}b[N],c[N],d[N];
bool cmp1(fg yjh,fg lsy){
	return yjh.x-max(yjh.y,yjh.z)>lsy.x-max(lsy.y,lsy.z);
}
bool cmp2(fg yjh,fg lsy){
	return yjh.y-max(yjh.x,yjh.z)>lsy.y-max(lsy.x,lsy.z);
}
bool cmp3(fg yjh,fg lsy){
	return yjh.z-max(yjh.x,yjh.y)>lsy.z-max(lsy.x,lsy.y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ll n,cnt1=0,cnt2=0,cnt3=0;cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			ll flag=0;
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>max(a[i].y,a[i].z)){
				b[++cnt1].x=a[i].x;
				b[cnt1].y=a[i].y;
				b[cnt1].z=a[i].z;
				ans+=a[i].x;
				flag=1;
			}
			else if(a[i].y>max(a[i].x,a[i].z)){
				c[++cnt2].x=a[i].x;
				c[cnt2].y=a[i].y;
				c[cnt2].z=a[i].z;
				ans+=a[i].y;
				flag=1;
			}
			else if(a[i].z>max(a[i].x,a[i].y)){
				d[++cnt3].x=a[i].x;
				d[cnt3].y=a[i].y;
				d[cnt3].z=a[i].z;
				ans+=a[i].z;
				flag=1;
			}
			if(flag==0){
				ans+=max(a[i].x,max(a[i].y,a[i].z));//最大值有相同，一定能排上 
			}
		}
		if(cnt1>n/2){
			sort(b+1,b+1+cnt1,cmp1);
			for(int i=cnt1;i>n/2;i--){
				ans-=(b[i].x-max(b[i].y,b[i].z));
			}
		} 
		if(cnt2>n/2){
			sort(c+1,c+1+cnt2,cmp2);
			for(int i=cnt2;i>n/2;i--){
				ans-=(c[i].y-max(c[i].x,c[i].z));
			}
		}
		if(cnt3>n/2){
			sort(d+1,d+1+cnt3,cmp3);
			for(int i=cnt3;i>n/2;i--){
				ans-=(d[i].z-max(d[i].x,d[i].y));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
