/*
T1 club.cpp
ZJ-S00219 shicj
100pts
15:16
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,A,B,C,ans;
int a[100005][4];
int ch[100005];
struct S{
	int id,x;
}delta[100005];
int max_without(int i,int x){
	if(x==1){
		return max(a[i][2],a[i][3]);
	}
	if(x==2){
		return max(a[i][1],a[i][3]);
	}
	return max(a[i][1],a[i][2]);
}
bool cmp(S x,S y){
	return x.x<y.x;
}
void solve(){
	A=B=C=ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][1]>=max(a[i][2],a[i][3])){
			ch[i]=1;
			A++;
			ans+=a[i][1];
		}
		else if(a[i][2]>=max(a[i][1],a[i][3])){
			ch[i]=2;
			B++;
			ans+=a[i][2];
		}
		else{
			ch[i]=3;
			C++;
			ans+=a[i][3];
		}
	}
	int X=0,ID=0;
	if(A>n/2){
		X=A;
		ID=1;
	}
	else if(B>n/2){
		X=B;
		ID=2;
	}
	else{
		X=C;
		ID=3;
	}
//    cout<<X<<" "<<ID<<" "<<ans<<endl;
	for(int i=1;i<=n;i++){
        delta[i].id=i;
        delta[i].x=0x3f3f3f3f;
		if(ch[i]==ID){
			delta[i].x=a[i][ch[i]]-max_without(i,ch[i]);
		}
//        cerr<<i<<" "<<ch[i]<<" "<<a[i][ch[i]]<<" "<<delta[i].x<<endl;
	}
	sort(delta+1,delta+n+1,cmp);
	for(int i=1;i<=X-n/2;i++){
		ans-=delta[i].x;
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}