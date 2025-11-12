#include<bits/stdc++.h> 
#define rep(i,n,m) for(int i=n;i<=m;i++)
#define pre(i,n,m) for(int i=n;i>=m;i--)
using namespace std;

const int N=1e5+5;
int t,n,ans,cnt1,cnt2,cnt3,mans;
struct node{
	int a,b,c;
	bool flag1,flag2,flag3;
	bool in1,in2,in3;
}a[N];
bool flag0=true,flag2=true;
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		ans=0,mans=0,flag0=flag2=true;
		cin>>n;
		rep(i,1,n){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0) flag0=false;
			if(a[i].c!=0) flag2=false;
			mans+=max(max(a[i].a,a[i].b),a[i].c);
		}
		if(flag0){
			rep(i,1,n) rep(j,1,n-1) if(a[j].a<a[j+1].a) swap(a[j],a[j+1]);
			rep(i,1,n/2) ans+=a[i].a;
			cout<<ans;
		}else if(flag2){
			rep(i,1,n) rep(j,1,n-1) if(a[j].a<a[j+1].a) swap(a[j],a[j+1]);
			rep(i,1,n){
				if(a[i].a>a[i].b) ans+=a[i].a;
				else ans+=a[i].b;
			}
			cout<<ans;
		}else cout<<mans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
