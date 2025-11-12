#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct qwer{
	ll a;
	ll b;
	ll c;
	bool q=1;
}w[100006];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		int a,b,c;
		ll maxa=0,maxb=0,maxc=0;
		a=n/2,b=n/2,c=n/2;
		ll ans=0;
		for(int i=1;i<=n;i++){
		    cin>>w[i].a>>w[i].b>>w[i].c;
		    /*if(w[i].a==0||w[i].b==0||w[i].c==0)){
		    	if(w[i].a!=0&&w[i].b==0&&w[i].c==0&&a>0){
		    		ans+=w[i].a;
		    		a--;
				}
				else if(w[i].a==0&&w[i].b!=0&&w[i].c==0&&a>0){
		    		ans+=w[i].b;
		    		b--;
				}
				else if(w[i].a==0&&w[i].b==0&&w[i].c!=0&&a>0){
		    		ans+=w[i].c;
		    		c--;
				}
				w[i].q=false;
			}*/
		}
		for(int i=n;i>=1;i--){
			if(w[i].a>w[i].b&&w[i].a>w[i].c&&a>0){
				ans+=w[i].a;
				a--;
			}
			else if(w[i].b>w[i].a&&w[i].b>w[i].c&&b>0){
				ans+=w[i].b;
				b--;
			}
			else if(w[i].c>w[i].b&&w[i].c>w[i].a&&c>0){
				ans+=w[i].c;
				c--;
			}
			/*if(w[i].q==true){
				if(w[i].a>w[i].b&&w[i].a>w[i].c&&a>0){
					a--;
					ans+=w[i].a;
				}
				else if(w[i].b>w[i].a&&w[i].b>w[i].c&&b>0){
					b--;
					ans+=w[i].b;
				}
				else if(w[i].c>w[i].a&&w[i].c>w[i].b&&c>0){
					c--;
					ans+=w[i].c;
				}
				w[i].q=false;
			}*/
		}
		cout<<ans<<endl;
	}
	return 0;
}