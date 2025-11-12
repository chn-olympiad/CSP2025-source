//李兴辰 SN-S00324 安康高新技术产业开发区九年制学校
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct T{
	int a1,a2,a3;
	short getm(){
		if(a1>a2){
			if(a3>a1)return 3;
			return 1;
		}if(a2>a3)return 2;
		else return 3;
	}short gets(){
		if(a1>a2){
			if(a3>a1)return 1;
			if(a2>a3)return 2;
			else return 3;
		}if(a3>a2)return 2;//a2>a1
		if(a1>a3)return 1;
		else return 3;
	}
	short getmn(){
		if(a1>a2){
			if(a3>a1)return a3;
			return a1;
		}if(a2>a3)return a2;
		else return a3;
	}short getsn(){
		if(a1>a2){
			if(a3>a1)return a1;
			if(a2>a3)return a2;
			else return a3;
		}if(a3>a2)return a2;//a2>a1
		if(a1>a3)return a1;
		else return a3;
	}
}a[N];
int n,s[4],ti[4][N];
void solve(){
	cin>>n;
	memset(s,0,sizeof(s));
	memset(ti,0,sizeof(ti));
	ll ans[N];
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		short i1=a[i].getm(),i2=a[i].gets(),d1=a[i].getmn(),d2=a[i].getsn();
		if(s[i1]<(n>>1)){
			ti[i1][++s[i1]]=i;
			ans[i]=d1;
		}
		else{
			int minn=d1-d2,id=-1,ind;//id->a,ind->ti
			for(int j=1;j<=s[i1];j++){
				int f=a[ti[i1][j]].getmn()-a[ti[i1][j]].getsn();
				if(f<minn){
					minn=f,id=ti[i1][j],ind=j;
				}
			}
			if(id==-1){
				ti[i2][++s[i2]]=i;
				ans[i]=d2;
			}else{
				ti[i1][ind]=i;
				ans[i]=d1;
				ti[a[id].gets()][++s[a[id].gets()]]=id;
				ans[id]=a[id].getsn();
			}
		}
	}
	ll ansn=0;
	for(int i=1;i<=n;i++){
		ansn+=ans[i]; 
	}cout<<ansn<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
