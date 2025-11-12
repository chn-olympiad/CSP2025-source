#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q,t,ans,s[4];
bool v[2000100][4];
struct sp{
	ll x,y,z,o;
}a[200010];
bool cmp(sp x,sp y){
	return x.o<y.o;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		s[1]=s[2]=s[3]=0;
		for(int i=1;i<=n;i++){
			a[i].o=0;
			v[i][1]=v[i][2]=v[i][3]=0;
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
				ans+=a[i].x;
				s[1]++;
				v[i][1]=1;
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
				ans+=a[i].y;
				s[2]++;
				v[i][2]=1;
			}
			else{
				ans+=a[i].z;
				s[3]++;
				v[i][3]=1;
			}
		}
		ll p=max(s[1],max(s[2],s[3]));
		if(p<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		ll q;
		if(s[1]>n/2) q=1;
		else if(s[2]>n/2) q=2;
		else q=3;
		for(int i=1;i<=n;i++){
			if(q==1){
				if(v[i][1]){
					a[i].o=a[i].x-max(a[i].y,a[i].z);
				}
				else{
					a[i].o=10000000000;
				}
			}
			else if(q==2){
				if(v[i][2]){
					a[i].o=a[i].y-max(a[i].x,a[i].z);
				}
				else{
					a[i].o=10000000000;
				}
			}
			else{
				if(v[i][3]){
					a[i].o=a[i].z-max(a[i].x,a[i].y);
				}
				else{
					a[i].o=10000000000;
				}
			}
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			ans-=a[i].o;
			p--;
			if(p<=n/2) break;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}

