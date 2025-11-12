#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=1e5+5;
int t;
int n;
int a[N],b[N],c[N];
int ca,cb,cc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ca=cb=cc=0;
		cin>>n;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ca++;
				ans+=a[i];
			}else if(a[i]<=b[i]&&b[i]>=c[i]){
				cb++;
				ans+=b[i];
			}else{
				cc++;
				ans+=c[i];
			}
		}
		if(ca*2<=n&&cb*2<=n&&cc*2<=n){
			cout<<ans<<"\n";
			continue;
		}
		priority_queue<long long>q;
		if(ca*2>n){
			for(int i=1;i<=n;i++){
				if(a[i]>=b[i]&&a[i]>=c[i]){
					q.push(max(b[i],c[i])-a[i]);
				}
			}
			while(ca*2>n){
				ca--;
				ans=ans+q.top();
				q.pop();
			}
			while(!q.empty()){
				q.pop();
			}
			cout<<ans<<"\n";
		}else if(cb*2>n){
			for(int i=1;i<=n;i++){
				if(b[i]>=c[i]&&b[i]>=a[i]){
					q.push(max(a[i],c[i])-b[i]);
				}
			}
			while(cb*2>n){
				cb--;
				//cout<<q.top().second<<" "<<q.top().first<<"\n";
				ans=ans+q.top();
				q.pop();
			}
			while(!q.empty()){
				q.pop();
			}
			cout<<ans<<"\n";
		}else if(cc*2>n){
			for(int i=1;i<=n;i++){
				if(c[i]>=b[i]&&c[i]>=a[i]){
					q.push(max(a[i],b[i])-c[i]);
				}
			}
			while(cc*2>n){
				cc--;
				ans=ans+q.top();
				q.pop();
			}
			while(!q.empty()){
				q.pop();
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
