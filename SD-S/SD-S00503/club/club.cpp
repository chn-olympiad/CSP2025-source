#include<bits/stdc++.h>
using namespace std;
long long t,n,p[4];
long long ans=0;
struct ap{
	long long a,b,c;
	long long maxx,p;
}a[100005];
void find(long long x,long long r){
	int minn=0;
	for(int i=1;i<r;i++){
		if(a[i].p==x){
			if(a[i].p==1) minn=min(abs(a[i].a-a[i].b),abs(a[i].a-a[i].c));
			else if(a[i].p==2) minn=min(abs(a[i].b-a[i].a),abs(a[i].b-a[i].c));
			else minn=min(abs(a[i].c-a[i].b),abs(a[i].c-a[i].a));
		}
		ans-=minn;
		p[a[i].p]--;
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=3;i++) p[i]=0;
		if(n==1){
			cin>>a[1].a>>a[1].b>>a[1].c;
			a[1].maxx=max(max(a[1].a,a[1].b),a[1].c);
			cout<<a[1].maxx<<endl;
			continue;
		} 
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].maxx=max(max(a[i].a,a[i].b),a[i].c);
			if(a[i].maxx==a[i].a) a[i].p=1;
			else if(a[i].maxx==a[i].b) a[i].p=2;
			else a[i].p=3;
		}
		for(int i=1;i<=n;i++){
			ans+=a[i].maxx;
			p[a[i].p]++;
			if(p[a[i].p]>n/2){
				find(a[i].p,i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
