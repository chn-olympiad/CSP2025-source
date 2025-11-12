#include <bits/stdc++.h>
using namespace std;
long long t,n;
struct node{
	long long f,s,t;
}a[100010];
bool cmp(node lhs,node rhs){
	return lhs.f+lhs.s+lhs.t>rhs.f+rhs.s+rhs.t;
}
void solve(){
	memset(a,0,sizeof(a));
	long long ans=0,fcnt=0,scnt=0,tcnt=0;
	long long n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i].f>>a[i].s>>a[i].t;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		if (a[i].f>a[i].s && a[i].f>a[i].t && fcnt+1<=n/2) {
			ans+=a[i].f;
			fcnt++;continue;
		}
		else if (a[i].f>a[i].s && a[i].f>a[i].t && fcnt+1>n/2){
			if (a[i].s>a[i].t && scnt+1<=n/2) {
				ans+=a[i].s;
				scnt++;continue;
			}
			else if (a[i].s>a[i].t && scnt+1>n/2){
				ans+=a[i].t;
				tcnt++;continue;
			}
			else if (a[i].t>a[i].s && tcnt+1<=n/2) {
				ans+=a[i].t;
				tcnt++;continue;
			}
			else if (a[i].f>a[i].t && tcnt+1>n/2){
				ans+=a[i].s;
				scnt++;continue;
			}
	    }
	    
	    ////////////
	    if (a[i].s>a[i].f && a[i].s>a[i].t && scnt+1<=n/2) {
			ans+=a[i].s;
			scnt++;continue;
		}
		else if (a[i].s>a[i].f && a[i].s>a[i].t && scnt+1>n/2){
			if (a[i].f>a[i].t && fcnt+1<=n/2) {
				ans+=a[i].f;
				fcnt++;continue;
			}
			else if (a[i].f>a[i].t && fcnt+1>n/2){
				ans+=a[i].t;
				tcnt++;continue;
			}
			else if (a[i].t>a[i].f && tcnt+1<=n/2) {
				ans+=a[i].t;
				tcnt++;continue;
			}
			else if (a[i].t>a[i].f && tcnt+1>n/2){
				ans+=a[i].f;
				fcnt++;continue;
			}
	    }
	    //////
	    if (a[i].t>a[i].s && a[i].t>a[i].f && tcnt+1<=n/2) {
			ans+=a[i].t;
			tcnt++;continue;
		}
		else if (a[i].t>a[i].s && a[i].t>a[i].f && tcnt+1>n/2){
			if (a[i].s>a[i].f && scnt+1<=n/2) {
				ans+=a[i].s;
				scnt++;continue;
			}
			else if (a[i].s>a[i].f && scnt+1>n/2){
				ans+=a[i].f;
				fcnt++;continue;
			}
			else if (a[i].f>a[i].s && fcnt+1<=n/2) {
				ans+=a[i].f;
				fcnt++;continue;
			}
			else if (a[i].f>a[i].s && fcnt+1>n/2){
				ans+=a[i].s;
				scnt++;continue;
			}
	    }
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while (t--){
		solve();
	}
	return 0;
}
