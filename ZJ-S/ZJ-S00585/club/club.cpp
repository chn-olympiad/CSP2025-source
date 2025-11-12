#include<bits/stdc++.h>
using namespace std;
long long t,n,cnt[4];
struct node{
	long long a1,a2,a3;
}a[100005],b[100005];
bool cmp1(node a,node b){
	return a.a1-a.a2>b.a1-b.a2;
}
bool cmp2(node a,node b){
	return a.a1-a.a2<b.a1-b.a2;
}
bool cmp3(node a,node b){
	return a.a3-a.a1>b.a3-b.a1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;++i){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			int maxx=max(a[i].a1,max(a[i].a2,a[i].a3));
			if(a[i].a1==maxx) cnt[1]++;
			else if(a[i].a2==maxx) cnt[2]++;
			else if(a[i].a3==maxx) cnt[3]++;
		}
		long long cntt=0,ans=0;
		if(cnt[1]>n/2){
			for(int i=1;i<=n;++i){
				int maxx=max(a[i].a1,max(a[i].a2,a[i].a3));
				if(a[i].a1==maxx){
					if(a[i].a2<a[i].a3) swap(a[i].a2,a[i].a3);
					b[++cntt]=a[i];
				}
				else ans+=max(a[i].a2,a[i].a3);
			}
			sort(b+1,b+1+cntt,cmp1);
			for(int i=1;i<=n/2;++i) ans+=b[i].a1;
			for(int i=n/2+1;i<=cntt;++i){
				ans+=b[i].a2;
			}
		}
		else if(cnt[2]>=n/2){
			for(int i=1;i<=n;++i){
				int maxx=max(a[i].a1,max(a[i].a2,a[i].a3));
				if(a[i].a2==maxx){
					if(a[i].a1<a[i].a3) swap(a[i].a1,a[i].a3);
					b[++cntt]=a[i];
				}
				else ans+=max(a[i].a1,a[i].a3);
			}
			sort(b+1,b+1+cntt,cmp2);
			for(int i=1;i<=n/2;++i) ans+=b[i].a2;
			for(int i=n/2+1;i<=cntt;++i){
				ans+=max(b[i].a1,b[i].a3);
			}
		}
		else if(cnt[3]>=n/2){
			for(int i=1;i<=n;++i){
				int maxx=max(a[i].a1,max(a[i].a2,a[i].a3));
				if(a[i].a3==maxx){
					if(a[i].a1<a[i].a2) swap(a[i].a1,a[i].a2);
					b[++cntt]=a[i];
				}
				else ans+=max(a[i].a1,a[i].a2);
			}
			sort(b+1,b+1+cntt,cmp3);
			for(int i=1;i<=n/2;++i) ans+=b[i].a3;
			for(int i=n/2+1;i<=cntt;++i){
				ans+=max(b[i].a1,b[i].a2);
			}
		}
		else{
			for(int i=1;i<=n;++i){
				int maxx=max(a[i].a1,max(a[i].a2,a[i].a3));
				ans+=maxx;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
