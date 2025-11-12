#include<bits/stdc++.h>
using namespace std;
//#define ll long long;
long long t,n;
long long cnt[5],topp,ans;
struct abc{
	long long a[5],id;
}a[200005];
bool cmp(abc x,abc y){
	return x.a[x.id]>y.a[y.id];
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long _=1;_<=t;_++){
		cnt[1]=cnt[2]=cnt[3]=ans=0;
		cin>>n;
		topp=n/2;
		for(long long i=1,x;i<=n;i++){
			cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];
			x=min(min(a[i].a[1],a[i].a[2]),a[i].a[3]);
			a[i].a[1]-=x;a[i].a[2]-=x;a[i].a[3]-=x;
			ans+=x;	
			if(a[i].a[1]==0){
				if(a[i].a[2]<=a[i].a[3]){//3
					ans+=a[i].a[2];
					a[i].a[3]-=a[i].a[2];a[i].a[2]=0;
					a[i].id=3;
				}
				else{//2
					ans+=a[i].a[3];
					a[i].a[2]-=a[i].a[3];a[i].a[3]=0;
					a[i].id=2;
				}
			}
			else if(a[i].a[2]==0){
				if(a[i].a[1]<=a[i].a[3]){//3
					ans+=a[i].a[1];
					a[i].a[3]-=a[i].a[1];a[i].a[1]=0;
					a[i].id=3;
				}
				else{//1
					ans+=a[i].a[3];
					a[i].a[1]-=a[i].a[3];a[i].a[3]=0;
					a[i].id=1;
				}
			}
			else if(a[i].a[3]==0){
				if(a[i].a[2]<=a[i].a[1]){//1
					ans+=a[i].a[2];
					a[i].a[1]-=a[i].a[2];a[i].a[2]=0;
					a[i].id=1;
				}
				else{//2
					ans+=a[i].a[1];
					a[i].a[2]-=a[i].a[1];a[i].a[1]=0;
					a[i].id=2;
				}
			}
		}
		sort(a+1,a+1+n,cmp);
		for(long long i=1;i<=n;i++){
			if(topp>cnt[a[i].id]){
				cnt[a[i].id]++;
				ans+=a[i].a[a[i].id];
			}
		}//cout<<a[i].id<<' '<<a[i].a[a[i].id]<<'\n';
		cout<<ans<<'\n';
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