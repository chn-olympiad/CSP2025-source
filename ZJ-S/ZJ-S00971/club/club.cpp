#include<bits/stdc++.h>
using namespace std;
int t,n,fa,fb,fc;
int ans;
priority_queue<int,vector<int>,greater<int> >qa,qb,qc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=fa=fb=fc=0;
		while(qa.size())qa.pop();
		while(qb.size())qb.pop();
		while(qc.size())qc.pop();
		cin>>n;
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(a>=b&&a>=c)ans+=a,qa.push(a-max(b,c)),fa++;
			else if(b>=a&&b>=c)ans+=b,qb.push(b-max(a,c)),fb++;
			else ans+=c,qc.push(c-max(a,b)),fc++;
		}
		if(fa*2>n){
			while(fa*2>n){
				fa--;
				ans-=qa.top();
				qa.pop();
			}
		}
		if(fb*2>n){
			while(fb*2>n){
				fb--;
				ans-=qb.top();
				qb.pop();
			}
		}
		if(fc*2>n){
			while(fc*2>n){
				fc--;
				ans-=qc.top();
				qc.pop();
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}//f 
