#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IO(fn) freopen(fn".in","r",stdin);freopen(fn".out","w",stdout);
int n,lmt;
const int N=1e5+15;
struct node{
	int x,y,z;
	void read(){
		cin>>x>>y>>z;
	}
	void roll(){
		swap(x,y),swap(y,z);
	}
}a[N];
//bool vis[N];
int a1,a2,a3,ans=0;
void dfs(int cur,int sum){
	if(cur==n+1){
		ans=max(ans,sum);
		return;
	}
	if(a1<lmt){
		a1++;
		dfs(cur+1,sum+a[cur].x);
		a1--;
	}
	if(a2<lmt){
		a2++;
		dfs(cur+1,sum+a[cur].y);
		a2--;
	}
	if(a3<lmt){
		a3++;
		dfs(cur+1,sum+a[cur].z);
		a3--;
	}
}
void solve1(){
	lmt=n>>1;ans=a1=a2=a3=0;
	for(int i=1;i<=n;i++){
		a[i].read();
	}
	dfs(1,0);
	cout<<ans<<'\n';
	return;
}
bool cmp1(const node a1,const node a2){
	return a1.x>a2.x;
}
void solve2(){
	sort(a+1,a+n+1,cmp1);
	int anss=0;
	for(int i=1;i<=lmt;i++)anss+=a[i].x;
	cout<<anss<<'\n';
	return;
}
bool cmp11(const node aa,const node bb){return aa.x>bb.x;}
bool cmp22(const node aa,const node bb){return aa.y>bb.y;}
void solve3(){
	int s1,s2;
	s1=s2=0;
	sort(a+1,a+n+1,cmp11);
	for(int i=1;i<=lmt;i++){
		s1+=a[i].x+a[i+lmt].y;
	}
	sort(a+1,a+n+1,cmp22);
	for(int i=1;i<=lmt;i++){
		s2+=a[i].x+a[i+lmt].y;
	}
	cout<<max(s1,s2)<<'\n';
	return;
}
bool cmp(const node aa,const node bb){
	if(aa.x!=bb.x)return aa.x>bb.x;
	else if(aa.y!=bb.y)return aa.y>bb.y;
	else return aa.z>bb.z;
}
#define gt1 num[1]++,ans+=a[i].x
#define gt2 num[2]++,ans+=a[i].y
#define gt3 num[3]++,ans+=a[i].z
int solve11(){
	int ans=0,num[4]={0,0,0,0};
	sort(a+1,a+n+1,cmp);
	for(int tmp,i=1;i<=n;i++){
		tmp=max(a[i].x,max(a[i].y,a[i].z));
		if(tmp==a[i].x){
			if(num[1]<lmt)gt1;
			else if(a[i].y>a[i].z){
				if(num[2]<lmt)gt2;
				else gt3;
			}
			else{
				if(num[3]<lmt)gt3;
				else gt2;
			}
		}
		else if(tmp==a[i].y){
			if(num[2]<lmt)gt2;
			else if(a[i].x>a[i].z){
				if(num[1]<lmt)gt1;
				else gt3;
			}
			else{
				if(num[3]<lmt)gt3;
				else gt1;
			}
		}
		else if(tmp==a[i].z){
			if(num[3]<lmt)gt3;
			else if(a[i].x>a[i].y){
				if(num[1]<lmt)gt1;
				else gt2;
			}
			else{
				if(num[2]<lmt)gt2;
				else gt1;
			}
		}
//		cerr<<"\n"<<num[1]<<' '<<num[2]<<' '<<num[3];
	}
//	cerr<<"\n"<<num[1]<<' '<<num[2]<<' '<<num[3]<<'\n';
	return ans;
}
void solve4(){
	cin>>n;lmt=n>>1;
	for(int i=1;i<=n;i++)a[i].read();
	int A,B,C;
	A=solve11();cerr<<'\n';
	for(int i=1;i<=n;i++)a[i].roll();
	B=solve11();cerr<<'\n';
	for(int i=1;i<=n;i++)a[i].roll();
	C=solve11();cerr<<'\n';
	cerr<<A<<' '<<B<<' '<<C<<'\n';
	cout<<max(A,max(B,C))<<'\n';
}
void solve(){
	cin>>n;lmt=n>>1;
	if(n<10){
		solve1();
		return;
	}
	for(int i=1;i<=n;i++){
		a[i].read();
	}
	bool flg1=1,flg2=1;
	for(int i=1;i<=n;i++){
		flg1&=(a[i].z==0);
		flg2&=(a[i].z==0)&&(a[i].y==0);
	}
	solve2();
}

signed main(){IO("club");
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	for(cin>>T;T--;solve());
}
