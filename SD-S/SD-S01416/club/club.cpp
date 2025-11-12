#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100010;
struct Node{
	int a,b,c;
	int maxn;
}z[MAXN];
int ans,n;
void dfs(int i,int sum1,int sum2,int sum3,int now){
	if(i>n){
		ans=max(ans,now);
		return;
	}
	if(sum1<(n>>1)){
		dfs(i+1,sum1+1,sum2,sum3,now+z[i].a);
	}
	if(sum2<(n>>1)){
		dfs(i+1,sum1,sum2+1,sum3,now+z[i].b);
	}
	if(sum3<(n>>1)){
		dfs(i+1,sum1,sum2,sum3+1,now+z[i].c);
		return;
	}
} 
bool cmp1(Node i,Node j){
	return i.a>j.a;
}
bool cmp(Node i,Node j){
	return i.maxn>j.maxn;
}
void solve(){
	cin>>n;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>z[i].a>>z[i].b>>z[i].c;
		z[i].maxn=max(z[i].a,max(z[i].b,z[i].c));
		if(z[i].b!=0||z[i].c!=0){
			flag=0;
		}
	}
	if(flag){
		sort(z+1,z+n+1,cmp1);
		for(int i=1;i<=n>>1;i++){
			ans+=z[i].a;
		}
		cout<<ans<<'\n';
		return;
	}
	if(n<=15){
		ans=0;
		dfs(1,0,0,0,0);
		cout<<ans<<'\n';
		return;
	}
	int sum1=0,sum2=0,sum3=0;
	sort(z+1,z+n+1,cmp);
	int aans=0;
	for(int i=1;i<=n;i++){
		int aa=z[i].a,bb=z[i].b,cc=z[i].c;
		if(aa>bb&&aa>cc){
			if(sum1<(n>>1)){
				sum1++;
				ans+=aa;
			}else{
				if(bb==cc){
					if(sum2<sum3){
						sum2++;
						ans+=bb;
					}else{
						sum3++;
						ans+=cc;
					}
				}else if(bb>cc){
					if(sum2<(n>>1))sum2++,ans+=bb;
					else sum3++,ans+=cc;
				}else{
					if(sum3<(n>>1))sum3++,ans+=cc;
					else sum2++,ans+=bb;
				}
			}
		}else if(bb>aa&&bb>cc){
			if(sum2<(n>>1)){
				sum2++;
				ans+=bb;
			}else{
				if(aa==cc){
					if(sum1<sum3){
						sum1++;
						ans+=aa;
					}else{
						sum3++;
						ans+=cc;
					}
				}else if(aa>cc){
					if(sum1<(n>>1)){
						sum1++;ans+=aa;
					}else sum3++,ans+=cc;
				}else{
					if(sum3<(n>>1)){
						sum3++;
						ans+=cc;
					}else{
						sum1++;
						ans+=aa;
					}
				}
			}
		}else if(cc>aa&&cc>bb){
			if(sum3<(n>>1)){
				sum3++;
				ans+=cc;
			}else{
				if(aa==bb){
					if(sum1<sum2){
						sum1++;
						ans+=aa;
					}else{
						sum2++;
						ans+=bb;
					}
				}else if(aa>bb){
					if(sum1<(n>>1)){
						ans+=aa;sum1++;
					}else{
						ans+=bb;sum2++;
					}
				}else{
					if(sum2<(n>>1)){
						ans+=bb;sum2++;
					}else sum1++,ans+=aa;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
