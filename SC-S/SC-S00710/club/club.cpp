#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100010];
bool cmp(node a,node b){
	if(a.a==b.a&&a.b==b.b) return a.c>b.c;
	if(a.a==b.a) return a.b>b.b;
	return a.a>b.a;
}
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int c2=0,c3=0,c1=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].a==0) c1++;
			if(a[i].b==0) c2++;
			if(a[i].c==0) c3++;
		}
		sort(a+1,a+1+n,cmp);
		if(c2==n&&c3==n){
			int t=n/2,ans=0;
			for(int i=1;i<=t;i++){
				ans+=a[i].a;
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(c1==n&&c3==n){
			int t=n/2,ans=0;
			for(int i=1;i<=t;i++){
				ans+=a[i].b;
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(c2==n&&c1==n){
			int t=n/2,ans=0;
			for(int i=1;i<=t;i++){
				ans+=a[i].c;
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(c3==n){
			priority_queue<pair<int,int> > p1,p2,p3;
			int t=n/2,ans=0;
			for(int i=1;i<=t;i++){
				ans+=a[i].a;
				p2.push({a[i].a-a[i].b,i});
			}
			for(int i=t+1;i<=n;i++){
				p1.push({a[i].b,i});
				p3.push({a[i].a,i});
			}
			for(int i=t+1;i<=n;i++){
				while(1){
					bool st=0;
					if(p1.size()!=0&&p3.size()!=0&&p1.top().second==p3.top().second) p1.pop(),st=1;
					if(p1.size()!=0&&p2.size()!=0&&p1.top().second==p2.top().second) p1.pop(),st=1;
					if(p2.size()!=0&&p3.size()!=0&&p2.top().second==p3.top().second) p3.pop(),st=1;
					if(st==0) break;
				}
				if(p1.top().first>p3.top().first+p2.top().first){
					ans+=p1.top().first;
					p1.pop();
				}
				else{
					ans+=p2.top().first;
					ans+=p3.top().first;
					p2.pop();
					p2.push({a[p3.top().second].b-a[p3.top().second].a,p3.top().second});
					p3.pop();
				}
			}
			cout<<ans<<"\n";
		}
		else 
			if(n<=13){
			int t1=qpow(4,n),t=n/2,maxv=0;
			for(int i=0;i<t1;i++){
				int ca=0,cb=0,cc=0,ans=0;
				int t2=i,tot=0;
				while(t2){
					tot++;
					if(t2%3==2) cc++,ans+=a[tot].c;
					if(t2%3==1) cb++,ans+=a[tot].b;
					if(t2%3==0) ca++,ans+=a[tot].a;
					if(cc>t||cb>t||ca>t){
						break;
					}
					t2/=4;
				}
				if(cc>t||cb>t||ca>t){
//					cout<<cc<<" "<<cb<<" "<<ca<<"\n";
					continue;
				}
//				cout<<ans<<" "<<i<<"\n";
				maxv=max(maxv,ans);
			}
			cout<<maxv<<"\n";
		}
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1

*/