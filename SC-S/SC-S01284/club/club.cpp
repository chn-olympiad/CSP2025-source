#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct query{
	int a,b,c;
}a[1000010];

int main(){
    #ifndef Reimu
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);
    #endif
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
    	int n;cin>>n;
    	int lim=(n>>1);
    	for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
    	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qa,qb,qc;
    	ll ans=0;
    	for(int i=1;i<=n;i++){
    		if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
    			int ca=a[i].a-max(a[i].b,a[i].c);
    			if((signed)qa.size()<lim){
    				qa.push(make_pair(a[i].a-max(a[i].b,a[i].c),i));
    				ans+=a[i].a;
				}
				else {
					if(ca>qa.top().first){
						int x=qa.top().second;
						if(a[x].b>=a[x].c){
							qb.push(make_pair(a[x].b-a[x].a,x));
							ans-=qa.top().first;
						}
						else {
							qc.push(make_pair(a[x].c-a[x].a,x));
							ans-=qa.top().first;
						}
						qa.pop();
						qa.push(make_pair(ca,i));
						ans+=a[i].a;
					}
					else {
						if(a[i].b>=a[i].c){
							qb.push(make_pair(-ca,i));
							ans+=a[i].b;
						}
						else {
							qc.push(make_pair(-ca,i));
							ans+=a[i].c;
						}
					}
				}
			}
			else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
    			int ca=a[i].b-max(a[i].a,a[i].c);
    			if((signed)qb.size()<lim){
    				qb.push(make_pair(a[i].b-max(a[i].a,a[i].c),i));
    				ans+=a[i].b;
				}
				else {
					if(ca>qb.top().first){
						int x=qb.top().second;
						if(a[x].a>=a[x].c){
							qa.push(make_pair(a[x].a-a[x].b,x));
							ans-=qb.top().first;
						}
						else {
							qc.push(make_pair(a[x].c-a[x].b,x));
							ans-=qb.top().first;
						}
						qb.pop();
						qb.push(make_pair(ca,i));
						ans+=a[i].b;
					}
					else {
						if(a[i].a>=a[i].c){
							qa.push(make_pair(-ca,i));
							ans+=a[i].a;
						}
						else {
							qc.push(make_pair(-ca,i));
							ans+=a[i].c;
						}
					}
				}
			}
			else if(a[i].c>=a[i].a&&a[i].c>=a[i].b){
    			int ca=a[i].c-max(a[i].a,a[i].b);
    			if((signed)qc.size()<lim){
    				qc.push(make_pair(a[i].c-max(a[i].a,a[i].b),i));
    				ans+=a[i].c;
				}
				else {
					if(ca>qc.top().first){
						int x=qc.top().second;
						if(a[x].a>=a[x].b){
							qa.push(make_pair(a[x].a-a[x].c,x));
							ans-=qc.top().first;
						}
						else {
							qb.push(make_pair(a[x].b-a[x].c,x));
							ans-=qc.top().first;
						}
						qc.pop();
						qc.push(make_pair(ca,i));
						ans+=a[i].c;
					}
					else {
						if(a[i].a>=a[i].b){
							qa.push(make_pair(-ca,i));
							ans+=a[i].a;
						}
						else {
							qb.push(make_pair(-ca,i));
							ans+=a[i].b;
						}
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/