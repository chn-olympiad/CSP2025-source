/*luogu@Nahia uid:1199153
Genshin Impact uid:289015817
I love Nahida forever!*/
//此情可待成追忆？只是当时已惘然。 
//疑似特殊性质A: 16pts
#include<bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i = a;i<=b;i++)
#define mod 998244353
using namespace std;
int c[505],k;
ll C(int n,int m){
	int x = 1,y = 1,z = 1;
	For(i,1,n) x*=i,x%=mod;
	For(i,1,m) y*=i,y%=mod;
	For(i,1,n-m) z*=i,z%=mod;
	return (x)/(y*z%mod);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	For(i,1,n){
		cin>>c[i];
		if(c[i]==0) k++;
	}
	if(n-k<m){
		cout<<0;
		return 0;
	} 
	bool f = 0;
	For(i,0,n-1){
		if(s[i] == '0'){
			f = 1;
			break;
		}
	}
	if(f==0){
		if(k==0){
			cout<<C(n,m)%mod;
		}
		else{
			cout<<(k*C(n-1,m-1)%mod+C(n-k,m)%mod)%mod;
		} 
	}
	return 0;
}
/*(n!)/(m!*(n-m)!)没有c[i]=0
k*((n-1)!)/((m-1)!*(n-m)!)+((n-k)!)/(m!*(n-k-m)!)有k个c[i]=0(k>=1) */
/*我学着不去担心的太远 不计划太多反而能勇敢冒险 丰富地过每一天 快乐地看每一天 ↑ ↑↑↓ ↓
第一次遇见阴天 遮住你侧脸 有什么故事好想了解 我感觉我懂你的特别*/
/*她是很特别的。她是五大学科竞赛中参加人数最少的一个，也是最不被重视，认为与whk相差最远的一个。
是，说的在理。可我偏偏爱上了她。
热爱，可排万难，可破万险。
我曾说要陪你到永远，可是我却率先食言
刚刚相见，转眼就要相别了*/ 
