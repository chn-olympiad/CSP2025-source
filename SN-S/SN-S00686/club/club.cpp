#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	int outt=0;
	char gett=getchar();
	while(gett<'0' || gett>'9')gett=getchar();
	while(gett>='0' && gett<='9')outt*=10,outt+=gett-'0',gett=getchar();
	return outt;
}
struct node{
	int a,b,c,d;
}mp[200001];
int noww[200001];
struct nod{
	int s,w;
};
bool operator<(nod a,nod b){
	return mp[a.w].d>mp[b.w].d;
}
priority_queue<nod> aa,bb,cc;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		while(aa.size())aa.pop();
		while(bb.size())bb.pop();
		while(cc.size())cc.pop();
		int n=read(); 
		for(int i=1;i<=n;i++){
			int s;
			cin>>mp[i].a>>mp[i].b>>mp[i].c;
			if(mp[i].a>=max(mp[i].b,mp[i].c)){
				noww[i]=1;
				if(mp[i].b>mp[i].c)s=2,mp[i].d=mp[i].a-mp[i].b;
				else s=3,mp[i].d=mp[i].a-mp[i].c;
				aa.push({s,i});
			}
			else if(mp[i].b>=max(mp[i].a,mp[i].c)){
				noww[i]=2;
				if(mp[i].a>mp[i].c)s=1,mp[i].d=mp[i].b-mp[i].a;
				else s=3,mp[i].d=mp[i].b-mp[i].c;
				bb.push({s,i});
			}
			else{
				noww[i]=3;
				if(mp[i].a>mp[i].b)s=1,mp[i].d=mp[i].c-mp[i].a;
				else s=2,mp[i].d=mp[i].c-mp[i].b;
				cc.push({s,i});
			}
		}
	//	for(int i=1;i<=n;i++)cout<<noww[i]<<' ';
	//	cout<<endl;
//		cout<<aa.size()<<' '<<bb.size()<<' '<<cc.size()<<endl;
		while(aa.size()>n/2){
//			cout<<"f";
			noww[aa.top().w]=aa.top().s;
			aa.pop();
		}
		while(bb.size()>n/2){
//			cout<<"f";
			noww[bb.top().w]=bb.top().s;
			bb.pop();
		}
		while(cc.size()>n/2){
//			cout<<"f";
			noww[cc.top().w]=cc.top().s;
			cc.pop();
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(noww[i]==1){
				ans+=(ll)mp[i].a;
			}
			else if(noww[i]==2){
				ans+=(ll)mp[i].b;
			}
			else{
				ans+=(ll)mp[i].c;
			}
		}cout<<ans<<endl;	
	}
	
	return 0;
} 
