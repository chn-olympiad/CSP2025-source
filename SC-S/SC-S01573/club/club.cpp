#include<bits/stdc++.h> 
using namespace std;
const int N=4e5+10;
int t,n,ans,ans2;
struct edge{
	int a,b,c;
}e[N];
int d[N],s[4];
priority_queue<int> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		while(q.size()) q.pop();
		s[1]=s[2]=s[3]=0;
		
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
		}
		for(int i=1;i<=n;i++){
			if(e[i].b>=e[i].a&&e[i].b>=e[i].c){
				d[i]=2;
			}
			if(e[i].c>=e[i].b&&e[i].c>=e[i].a){
				d[i]=3;
			}
			if(e[i].a>=e[i].b&&e[i].a>=e[i].c){
				d[i]=1;
			}
			s[d[i]]++;
		}
		if(s[2]>=s[1]&&s[2]>=s[3]){
			for(int i=1;i<=n;i++){
				swap(e[i].a,e[i].b);
			}
		}
		else if(s[3]>=s[1]&&s[3]>=s[2]){
			for(int i=1;i<=n;i++){
				swap(e[i].a,e[i].c);
			}
		}s[1]=s[2]=s[3]=0;
		for(int i=1;i<=n;i++){
			if(e[i].b>=e[i].a&&e[i].b>=e[i].c){
				d[i]=2;
			}
			if(e[i].c>=e[i].b&&e[i].c>=e[i].a){
				d[i]=3;
			}
			if(e[i].a>=e[i].b&&e[i].a>=e[i].c){
				d[i]=1;
			}
			s[d[i]]++;
		}
		for(int i=1;i<=n;i++){
			if(d[i]==1) ans+=e[i].a;
			if(d[i]==2) ans+=e[i].b;
			if(d[i]==3) ans+=e[i].c;
		}
		if(s[1]<=n/2){
			cout<<ans<<endl;
		}
		else{
			for(int i=1;i<=n;i++){
				if(d[i]==1){
					q.push(max(e[i].b-e[i].a,e[i].c-e[i].a));
				}
			}
			while(s[1]>n/2){
				ans+=q.top();q.pop();
				s[1]--;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}