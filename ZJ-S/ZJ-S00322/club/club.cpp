#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
struct node{
	int a1,a2,a3,maxx;
};
node a[N];
int n;
int ans=0;
void dg(int x,int cnt1,int cnt2,int cnt3,int w){
	if(x==n+1){
		ans=max(ans,w);
		return ;
	}
	if(cnt1<n/2)dg(x+1,cnt1+1,cnt2,cnt3,w+a[x].a1);
	if(cnt2<n/2)dg(x+1,cnt1,cnt2+1,cnt3,w+a[x].a2);
	if(cnt3<n/2)dg(x+1,cnt1,cnt2,cnt3+1,w+a[x].a3);
	return ;
}
void f(){
	cin>>n;
	int flaga=0,flagb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		if(a[i].a2!=0||a[i].a3!=0)flaga=1;
		if(a[i].a3!=0)flagb=1;
		a[i].maxx=max(a[i].a1,max(a[i].a2,a[i].a3));
	}
	if(n<=10){
		dg(1,0,0,0,0);
		cout<<ans<<endl;
		ans=0;
		return ;
	}
	if(!flaga){
		sort(a+1,a+1+n,[](node x,node y){
			return x.a1>y.a1;
		});
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i].a1;
		}
		cout<<ans<<endl;
		return ;
	}
	if(!flagb){
		
	}
	sort(a+1,a+1+n,[](node x,node y){
		return x.maxx>y.maxx;
	});
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(a[i].a1==a[i].maxx){
			if(cnt1!=n/2){
				ans+=a[i].a1;
				cnt1++;
			}
			else ans+=max(a[i].a2,a[i].a3);
		}
		if(a[i].a2==a[i].maxx){
			if(cnt2!=n/2){
				ans+=a[i].a2;
				cnt2++;
			}
			else ans+=max(a[i].a1,a[i].a3);
		}
		if(a[i].a3==a[i].maxx){
			if(cnt3!=n/2){
				ans+=a[i].a3;
				cnt3++;
			}
			else ans+=max(a[i].a1,a[i].a2);
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		f();ans=0;
	}
}
