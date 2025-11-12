#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,cnt[4],ans,a,b,c;
struct node{
	int mx,mi,rec;
}t[N];
bool cmp1(node P,node Q){
	return P.mx-P.mi>Q.mx-Q.mi;
}
signed main(){
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				t[i].rec=1;
				t[i].mx=a;
				t[i].mi=max(b,c);
			}
			else if(b>=a&&b>=c){
				t[i].rec=2;
				t[i].mx=b;
				t[i].mi=max(a,c);
			}
			else{
				t[i].rec=3;
				t[i].mx=c;
				t[i].mi=max(a,b);
			}
		}
		sort(t+1,t+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(t[i].rec==1){
				if(cnt[1]>=n/2){
					ans+=t[i].mi;
				}
				else{
					cnt[1]++;
					ans+=t[i].mx;
				}
			}
			else if(t[i].rec==2){
				if(cnt[2]>=n/2){
					ans+=t[i].mi;
				}
				else{
					cnt[2]++;
					ans+=t[i].mx;
				}
			}
			else{
				if(cnt[3]>=n/2){
					ans+=t[i].mi;
				}
				else{
					cnt[3]++;
					ans+=t[i].mx;
				}
			}
		}
		cout<<ans<<'\n';
	}
}