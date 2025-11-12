#include<bits/stdc++.h> 
using namespace std;

const int N=1e5+10;
int T,n,cnt1,cnt2,cnt3,ans;
int a[N];
int b[N];
int c[N];
struct node{
	int x,to,num;
	bool friend operator<(node x,node y){
		return x.num>y.num;
	}
}d1[N],d2[N],d3[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnt1=cnt2=cnt3=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			ans+=max(max(a[i],b[i]),c[i]);
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				d1[++cnt1]={a[i],0,min(a[i]-b[i],a[i]-c[i])};
//				if(a[i]-b[i]>a[i]-c[i])d1[cnt1].to=3;
//				else d1[cnt1].to=2;
			}
			else if(b[i]>=c[i]){
				d2[++cnt2]={b[i],0,min(b[i]-a[i],b[i]-c[i])};
//				if(b[i]-a[i]>b[i]-c[i])d1[cnt1].to=3;
//				else d1[cnt1].to=1;
			}
			else{
				d3[++cnt3]={c[i],0,min(c[i]-b[i],c[i]-a[i])};
//				if(c[i]-a[i]>c[i]-b[i])d1[cnt1].to=2;
//				else d1[cnt1].to=1;
			}
		}
		sort(d1+1,d1+cnt1+1);
		sort(d2+1,d2+cnt2+1);
		sort(d3+1,d3+cnt3+1);
		if(cnt1>n/2){
			for(int i=n/2+1;i<=cnt1;i++)
				ans-=d1[i].num;
		}else if(cnt2>n/2){
//			for(int i=1;i<=cnt2;i++)
//				cout<<d2[i].num<<' ';
//			cout<<endl;
			for(int i=n/2+1;i<=cnt2;i++)
				ans-=d2[i].num;
		}else{
			for(int i=n/2+1;i<=cnt3;i++)
				ans-=d3[i].num;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
