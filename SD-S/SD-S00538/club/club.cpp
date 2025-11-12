#include<bits/stdc++.h>
using namespace std;
long long n,t,ans;
struct p{
	long long a,b,c,maxx,mid;
}a[111111];
bool cmp1(p a,p b){
	return a.a>b.a;
}
bool cmp2(p a,p b){
	long long ma,mb;
	if(a.maxx = 0) ma =a.a;
	else if(a.maxx = 1)ma = a.b;
	else ma =a.a;
	
	if(b.maxx = 0)mb =b.a;
	else if(b.maxx = 1)mb = b.b;
	else mb =b.a;
	if(ma==mb)return a.a+a.b>b.a+b.b;
	return ma>mb;
}
void dfs(int no,int cnt1,int cnt2,int cnt3,long long sum){
	if(cnt1>n/2){
		return;
	}
	if(cnt2>n/2){
		return ;
	}
	if(cnt3>n/2){
		return ;
	}
	if(no>n){
		ans = max(ans,sum);
		return;
	}
	dfs(no+1,cnt1+1,cnt2,cnt3,sum+a[no].a);
	dfs(no+1,cnt1,cnt2+1,cnt3,sum+a[no].b);
	dfs(no+1,cnt1,cnt2,cnt3+1,sum+a[no].c);
	
}
void dfs2(int no,int cnt1,int cnt2,int cnt3,long long sum){
	if(cnt1>n/2){
		return;
	}
	if(cnt2>n/2){
		return ;
	}
	if(no>n){
		ans = max(ans,sum);
		return;
	}
	dfs2(no+1,cnt1+1,cnt2,cnt3,sum+a[no].a);
	dfs2(no+1,cnt1,cnt2+1,cnt3,sum+a[no].b);
	
}
int main(){
	ios::sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans = 0;
		cin>>n;
		if(n>30){
			for(int i=1;i<=n;i++){
				cin>>a[i].a>>a[i].b>>a[i].c;
			}
			if(a[1].b == 0){//a
				sort(a+1,a+n+1,cmp1);
				for(int i=1;i<=n/2;i++)ans+=a[i].a;
				cout<<ans<<endl;
			}
			else if(a[1].c==0){//b
				
				for(int i=1;i<=n;i++){
					cin>>a[i].a>>a[i].b>>a[i].c;
				}
				dfs2(0,0,0,0,0);
				cout<<ans<<endl;	
			}
			else{
				for(int i=1;i<=n;i++)ans+=a[i].a+a[i].b+a[i].c;
				ans/=3;
				cout<<ans<<endl;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				cin>>a[i].a>>a[i].b>>a[i].c;
			}
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
		}
	}
	return 0;
} 
