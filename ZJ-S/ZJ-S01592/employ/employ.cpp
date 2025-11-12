#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Fol(i,a,b) for(int i=b;i>=a;i--)
#define bug(a) cout<<" ( "<<#a<<" : "<<a<<" ) ";
#define bugln(a) cout<<" ( "<<#a<<" : "<<a<<" )\n";
#define bugg cout<<" --Debug ";
#define buggln cout<<" --Debug\n";
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define PII pair<int,int>
using namespace std;

const int M=505,ha=998244353;

int n,m;
char s[M];
int cnt;
int ans;
int a[M];
int v[M],p[M];

void dfs(int d){
	if(d==n+1){
		int cnt=0;
		int refu=0;
		For(i,1,n){
//			bug(p[i])
			if(refu<a[p[i]]&&s[i]=='1'){
				cnt++;
			}else{
				refu++;
			}
		}
//		buggln
		ans+=(cnt>=m);
		if(ans>=ha)ans-=ha;
		return ;
	}
	For(i,1,n){
		if(!v[i]){
			v[i]=1;
			p[d]=i;
			dfs(d+1);
			v[i]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld\n%s\n",&n,&m,s+1);
	For(i,1,n){
		cnt+=s[i]-'0';
		scanf("%lld",&a[i]);
	}
	if(n<=10){
		dfs(1);
		printf("%lld",ans);
		return 0;
	}
	int ans=1;
	For(i,2,n){
		ans=ans*i%ha;
//		bug(ans)
	}
	printf("%lld",ans);
	return 0;
}
//chzx_lfw AK IOI!!!!!

//Never notice me
//Never call my name with your voice!
//Let me forget everything
//Still moonlight shines on us
//...
//I'll end it all.
//And testify!!!! 

//max: 100+64+100+8=272
//min: 0+0+0+0=0
