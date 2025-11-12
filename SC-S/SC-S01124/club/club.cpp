#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int t,n,num[4],ans;
struct m{
	int a,b,c,Max;
	int aa,bb,cc; 
}p[N];
bool ss(m x,m y){
	if(max(max(x.aa,x.bb),x.cc)>max(max(y.aa,y.bb),y.cc)){
		return true;
	}
	return false;
}
void solve(){
	cin>>n;
	num[1]=num[2]=num[3]=n/2;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].b>>p[i].c;
		p[i].aa=p[i].a-p[i].b-p[i].c;
		p[i].bb=p[i].b-p[i].a-p[i].c;
		p[i].cc=p[i].c-p[i].b-p[i].a;
//		cout<<p[i].aa<<" "<<p[i].bb<<" "<<p[i].cc<<endl;
		if(p[i].aa>=p[i].bb&&p[i].aa>=p[i].cc){
			p[i].Max=1;
		}
		if(p[i].bb>=p[i].aa&&p[i].bb>=p[i].cc){
			p[i].Max=2;
		}
		if(p[i].cc>=p[i].aa&&p[i].cc>=p[i].bb){
			p[i].Max=3;
		}
	}
	sort(p+1,p+1+n,ss);
	for(int i=1;i<=n;i++){
		if(num[p[i].Max]>0){
			if(p[i].Max==1){
				ans+=p[i].a;
			}
			if(p[i].Max==2){
				ans+=p[i].b;
			}
			if(p[i].Max==3){
				ans+=p[i].c;
			}
			num[p[i].Max]--;
//			cout<<p[i].Max<<" "<<ans<<endl;
		}
		else{
			if(p[i].Max==1){
				if(p[i].bb>p[i].cc&&num[2]>0){
					num[2]--;
					ans+=p[i].b;
				}
				else if(p[i].bb<p[i].cc&&num[3]>0){
					num[3]--;
					ans+=p[i].c;
				}
				else if(num[2]==0){
					num[3]--;
					ans+=p[i].c;
				}
				else{
					num[2]--;
					ans+=p[i].b;
				}
			}
			if(p[i].Max==2){
				if(p[i].aa>p[i].cc&&num[1]>0){
					num[1]--;
					ans+=p[i].a;
				}
				else if(p[i].aa<p[i].cc&&num[3]>0){
					num[3]--;
					ans+=p[i].c;
				}
				else if(num[1]==0){
					num[3]--;
					ans+=p[i].c;
				}
				else{
					num[1]--;
					ans+=p[i].a;
				}
			}
			if(p[i].Max==3){
				if(p[i].bb>p[i].aa&&num[2]>0){
					num[2]--;
					ans+=p[i].b;
				}
				else if(p[i].bb<p[i].aa&&num[1]>0){
					num[1]--;
					ans+=p[i].a;
				}
				else if(num[2]==0){
					num[1]--;
					ans+=p[i].a;
				}
				else{
					num[2]--;
					ans+=p[i].b;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<p[i].a<<" "<<p[i].b<<" "<<p[i].c<<" "<<p[i].Max<<endl;
//	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}