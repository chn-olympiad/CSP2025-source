#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
struct node{
	int a,b,c,ch,id;
}p[N];
int mxa,mxb,mxc;
long long ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		mxa=mxb=mxc=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			int mx=max(p[i].c,max(p[i].a,p[i].b));
			ans+=mx;
			if(p[i].a==mx){
				mxa++;
				p[i].id=1;
			}else if(p[i].b==mx){
				mxb++;
				p[i].id=2;
			}else{
				mxc++;
				p[i].id=3;
			}
		}
		priority_queue<int> q;
		if(mxa>n/2){
			for(int i=1;i<=n;i++){
				if(p[i].id==1)q.push(max(p[i].b-p[i].a,p[i].c-p[i].a));
			}
			for(int i=1;i<=mxa-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}else if(mxb>n/2){
			for(int i=1;i<=n;i++){
				if(p[i].id==2)q.push(max(p[i].a-p[i].b,p[i].c-p[i].b));
			}
			for(int i=1;i<=mxb-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}else if(mxc>n/2){
			for(int i=1;i<=n;i++){
				if(p[i].id==3)q.push(max(p[i].b-p[i].c,p[i].a-p[i].c));
			}
			for(int i=1;i<=mxc-n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}
		cout<<ans<<"\n";
	} 
	return 0;
}
