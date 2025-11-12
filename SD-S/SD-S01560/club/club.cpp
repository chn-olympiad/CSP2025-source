#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int x1,wei;
}a[N],b[N];
int T,c[N],n,cnt1,cnt2,cnt3,ans1;
bool cmp(node x,node y){
	return x.x1>y.x1;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while(T--){
		int ans=0;
		cin>>n;
		if(n==2){
			int cnt1,cnt2,cnt3,cnt4,cnt5,cnt6;
			cin>>cnt1>>cnt2>>cnt3>>cnt4>>cnt5>>cnt6;
			int mx1=-1,mx2=-1,mx3=-1,mxk=0,mxk2=0,mx4=-1;
			if(max(cnt1,max(cnt2,cnt3))==cnt1){
				mxk=1;
				mx1=cnt1;
				mx4=max(cnt2,cnt3);
			}else if(max(cnt1,max(cnt2,cnt3))==cnt2){
				mxk=2;
				mx1=cnt2;
				mx4=max(cnt1,cnt3);
			}else if(max(cnt1,max(cnt2,cnt3))==cnt3){
				mxk=3;
				mx1=cnt3;
				mx4=max(cnt1,cnt2);
			}
			if(max(cnt4,max(cnt5,cnt6))==cnt4){
				mxk2=1;
				mx2=cnt4;
				mx3=max(cnt5,cnt6);
			}else if(max(cnt4,max(cnt5,cnt6))==cnt5){
				mxk2=2;
				mx2=cnt5;
				mx3=max(cnt4,cnt6);
			}else if(max(cnt4,max(cnt5,cnt6))==cnt6){
				mxk2=3;
				mx2=cnt6;
				mx3=max(cnt5,cnt4);
			}
			if(mxk==mxk2)cout<<mx1+mx3<<'\n';
			else cout<<mx1+mx2<<'\n';
			continue;
		}
		bool f=0,f1=0;
		for(int i=1;i<=n;++i){
			cin>>a[i].x1>>b[i].x1>>c[i];
			a[i].wei=i;
			b[i].wei=i;
			if(b[i].x1!=0)f=1;
			if(c[i]!=0)f1=1;
		}
		if(f==f1==1){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;++i)ans+=a[i].x1;
			cout<<ans<<'\n';
		}else if(f==1 && f1==0){
			int sum1=0,sum2=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;++i)sum1+=a[i].x1;
			for(int i=n/2+1;i<=n;++i)sum1+=b[a[i].wei].x1;
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;++i)sum2+=b[i].x1;
			for(int i=n/2+1;i<=n;++i)sum2+=a[b[i].wei].x1;
			cout<<max(sum1,sum2)<<'\n';
		}
	}
	return 0;
}
