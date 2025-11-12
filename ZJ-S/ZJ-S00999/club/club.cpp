#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	int id,val;
	bool operator<(const node&w)const{
		return val<w.val;
	}
};
int a[N],b[N],c[N];
bool st[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--){
		int n,ans=0;cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i],st[i]=0;
		priority_queue<node>A,B,C;
		int cnta=0,cntb=0,cntc=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i])A.push(node{i,b[i]-a[i]}),A.push(node{i,c[i]-a[i]}),ans+=a[i],cnta++;
			else if(b[i]>=a[i]&&b[i]>=c[i])B.push(node{i,a[i]-b[i]}),B.push(node{i,c[i]-b[i]}),ans+=b[i],cntb++;
			else if(c[i]>=a[i]&&c[i]>=b[i])C.push(node{i,a[i]-c[i]}),C.push(node{i,b[i]-c[i]}),ans+=c[i],cntc++;
		}
		while(cnta>n/2){
			while(A.size()&&st[A.top().id])A.pop();
			st[A.top().id]=1,ans+=A.top().val,cnta--;
		}
		while(cntb>n/2){
			while(B.size()&&st[B.top().id])B.pop();
			st[B.top().id]=1,ans+=B.top().val,cntb--;
		}
		while(cntc>n/2){
			while(C.size()&&st[C.top().id])C.pop();
			st[C.top().id]=1,ans+=C.top().val,cntc--;
		}
		cout<<ans<<"\n";
	}
	return 0;
}