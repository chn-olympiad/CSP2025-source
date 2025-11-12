#include<bits/stdc++.h>
using namespace std;
const int N=100010;
long long n;
struct node{
	long long x,y,z;
}s[N];
long long a[N],b[N],c[N];
long long cnt1,cnt2,cnt3;
long long ans;
long long cha[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(cha,0,sizeof cha);
		ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&s[i].x,&s[i].y,&s[i].z);
		}	
		for(int i=1;i<=n;i++){
			if(s[i].x>=s[i].y){
				if(s[i].x>=s[i].z){
					a[++cnt1]=i;ans+=s[i].x;
				}else{
					c[++cnt3]=i;ans+=s[i].z;
				}
			}
			else{
				if(s[i].y>=s[i].z){
					b[++cnt2]=i;ans+=s[i].y;
				}else{
					c[++cnt3]=i;ans+=s[i].z;
				}
			}
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		if(cnt1>n/2){
			for(int i=1;i<=cnt1;i++){
				int pos=a[i];
				int ss=max(s[pos].y,s[pos].z);
				cha[i]=s[pos].x-ss;
			}
			sort(cha+1,cha+cnt1+1);
			for(int i=1;i<=cnt1-n/2;i++){
				ans-=cha[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		if(cnt2>n/2){
			for(int i=1;i<=cnt2;i++){
				int pos=b[i];
				int ss=max(s[pos].x,s[pos].z);
				cha[i]=s[pos].y-ss;
			}
			sort(cha+1,cha+cnt2+1);
			for(int i=1;i<=cnt2-n/2;i++){
				ans-=cha[i];
			}
			cout<<ans<<'\n';
			continue;
		}
		if(cnt3>n/2){
			for(int i=1;i<=cnt3;i++){
				int pos=c[i];
				int ss=max(s[pos].y,s[pos].x);
				cha[i]=s[pos].z-ss;
			}
			sort(cha+1,cha+cnt3+1);
			for(int i=1;i<=cnt3-n/2;i++){
				ans-=cha[i];
			}
			cout<<ans<<'\n';
			continue;
		}
	}
	return 0;
}
