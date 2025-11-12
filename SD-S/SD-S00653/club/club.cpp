#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int a,b,c,res,sec;
}w[100005];
bool operator < (node a,node b){
	return a.res>b.res;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	int n,a=0,b=0,c=0;
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>w[i].a>>w[i].b>>w[i].c;
    		if(w[i].a>=w[i].b&&w[i].a>=w[i].c) a++;
    		else if(w[i].b>=w[i].a&&w[i].b>=w[i].c) b++;
    		else c++;
		}
		if(b>n/2){
			for(int i=1;i<=n;i++){
				swap(w[i].a,w[i].b);
			}
		}
		if(c>n/2){
			for(int i=1;i<=n;i++){
				swap(w[i].a,w[i].c);
			}
		}
		int flag=(a>n/2)||(b>n/2)||(c>n/2);
		if(!flag){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(w[i].a,max(w[i].b,w[i].c));
			}
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				int d=abs(w[i].a-w[i].b),e=abs(w[i].a-w[i].c);
				if(d<=e) w[i].res=d,w[i].sec=w[i].b;
				else w[i].res=e,w[i].sec=w[i].c;
			}
			sort(w+1,w+n+1);
			int cnt=0,ans=0;
			for(int i=1;i<=n;i++){
				if(w[i].a>=w[i].b&&w[i].a>=w[i].c){
					if(cnt>=n/2) ans+=w[i].sec;
					else{
						ans+=w[i].a;
						cnt++;
					}
				}
				else{
					ans+=max(w[i].b,w[i].c);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
