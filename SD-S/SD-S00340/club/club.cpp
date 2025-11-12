#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int v[5];
}a[N];
struct Pai{
	int v;
	int bian;
	friend bool operator <(Pai c,Pai d){
		return c.v>d.v;
	}
};
priority_queue<Pai> Q;
int n;
int ca,cb,cc;
long long ans;
int Bl[N];
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>T;
	while(T--){
		cin>>n;
		ca=cb=cc=0;
		while(Q.size()){
			Q.pop();
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i].v[j];
			}
		}
		//只考虑A，B
		for(int i=1;i<=n;i++){
			if(a[i].v[1]>a[i].v[2]){
				ans+=a[i].v[1];
				Bl[i]=1;
				ca++;
			}
			else{
				ans+=a[i].v[2];
				cb++;
				Bl[i]=2;
			}
		}	
		for(int i=1;i<=n;i++){
			//这里存 
			Q.push({(a[i].v[Bl[i]]-a[i].v[3]),i}); 
		}
		for(int i=1;i<=n/2;i++){
			if(Q.top().v>=0)break;
			ans=ans-Q.top().v;
			if(Bl[Q.top().bian]==1)ca--;
			else{
				cb--;
			}
			Bl[Q.top().bian]=3;
			Q.pop();
			cc++;
		}
		//平衡
		while(Q.size()){
			Q.pop();
		}
		if(ca>n/2){
			int the=ca-n/2;
			for(int i=1;i<=n;i++){
				if(Bl[i]==1)Q.push({a[i].v[1]-a[i].v[2],i}); 
			}
			for(int i=1;i<=the;i++){
				ans=ans-Q.top().v;
				Bl[Q.top().bian]=2;
				Q.pop();
				ca--;
				cb++;
			}
		}
		if(cb>n/2){
			int the=cb-n/2;
			for(int i=1;i<=n;i++){
				if(Bl[i]==2)Q.push({a[i].v[2]-a[i].v[1],i}); 
			}
			for(int i=1;i<=the;i++){
				ans=ans-Q.top().v;
				Bl[Q.top().bian]=1;
				Q.pop();
				cb--;
				ca++;
			}
		}
//		cout<<ans<<" "<<ca<<" "<<cb<<" "<<cc<<endl; 
//		for(int i=1;i<=n;i++){
//			cout<<Bl[i]<<" ";
//		}
//		cout<<endl;
		//加入c 
	
		cout<<ans<<endl;
	}	
	return 0;
} 

