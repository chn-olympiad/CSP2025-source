#include<bits/stdc++.h>
using namespace std;
int t,n,chong,ans,maxn=-1,maxn1=-1,ans1;
struct node{
	int a,b,c;
}op[200005];
bool cmp(node a,node b){
	if(a.a==b.a)return a.b<b.b;
	return a.a>b.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		chong=n/2;
		for(int i=1;i<=n;i++){
			cin>>op[i].a>>op[i].b>>op[i].c;
		}
		if(n==2){
			if(max(op[2].a,op[1].a)>max(op[2].b,op[1].b)){
				ans+=max(op[2].a,op[1].a);
				ans+=max(max(op[2].b,op[1].b),max(op[2].c,op[1].c));
			}else{
				ans+=max(op[2].b,op[1].b);
				ans+=max(max(op[2].a,op[1].a),max(op[2].c,op[1].c));
			}
			cout<<ans<<endl;
			continue;
		}
		if(op[1].b==0&&op[1].c==0){
			sort(op+1,op+1+n,cmp);
			for(int i=1;i<=chong;i++){
				ans+=op[i].a;
			}
			cout<<ans<<endl;
			continue;
		}
		if(op[1].c==0){
			sort(op+1,op+1+n,cmp);
			for(int i=1;i<=chong;i++)ans+=op[i].a;
			for(int i=chong+1;i<=n;i++)ans+=op[i].b;
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			ans+=max(op[i].a,max(op[i].b,op[i].c));
		}
		cout<<ans<<endl;
	}
	return 0;
}
