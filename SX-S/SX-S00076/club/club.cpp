#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
}a[100010];
bool cmp(Node p,Node q){
	if(p.a==q.a){
		if(p.b==q.b) return p.c>q.c;
		return p.b>q.b;
	}
	return p.a>q.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,ca=0,cb=0,cc=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].a>>a[i].b>>a[i].c;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(max({a[i].a,a[i].b,a[i].c})==a[i].a){
				if(ca<n/2) ans+=a[i].a,ca++;
				else if(a[i].b>a[i].c){
					if(cb<n/2) ans+=a[i].b,cb++;
					else ans+=a[i].c,cc++;
				}
				else ans+=a[i].c,cc++;
			}
			else if(max({a[i].a,a[i].b,a[i].c})==a[i].b){
				if(cb<n/2) ans+=a[i].b,cb++;
				else if(a[i].a>a[i].c){
					if(ca<n/2) ans+=a[i].a,ca++;
					else ans+=a[i].c,cc++;
				}
				else ans+=a[i].c,cc++;
			}
			else{
				if(cc<n/2) ans+=a[i].c,cc++;
				else if(a[i].b>a[i].a){
					if(cb<n/2) ans+=a[i].b,cb++;
					else ans+=a[i].a,ca++;
				}
				else ans+=a[i].a,ca++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}