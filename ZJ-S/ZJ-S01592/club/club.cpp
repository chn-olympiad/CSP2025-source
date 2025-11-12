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

const int M=1e5+10;

int n;
struct node{
	int a,b,c;
}a[M];
int id[4][M],idx[4];
int b[M];
int T;

void solve(){
	scanf("%lld",&n);
	int ans=0;
	idx[1]=idx[2]=idx[3]=0;
	For(i,1,n){
		scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
		if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
			id[1][++idx[1]]=i;
			ans+=a[i].a;
		}else if(a[i].b>=a[i].a&&a[i].b>=a[i].c){
			id[2][++idx[2]]=i;
			ans+=a[i].b;
		}else if(a[i].c>=a[i].a&&a[i].c>=a[i].b){
			id[3][++idx[3]]=i;
			ans+=a[i].c;
		}
	}
//	bug(ans)bug(idx[1])bug(idx[2])bug(idx[3])
	if(idx[1]>n/2){
//		sort(id[1]+1,id[1]+idx[1]+1);
		For(i,1,idx[1]){
			b[i]=min(a[id[1][i]].a-a[id[1][i]].b,a[id[1][i]].a-a[id[1][i]].c);
//			bug(b[idxb].v);
		}
		sort(b+1,b+idx[1]+1);
		For(i,1,idx[1]-n/2){
			ans-=b[i];
		}
	}
	if(idx[2]>n/2){
//		sort(id[1]+1,id[1]+idx[1]+1);
		For(i,1,idx[2]){
			b[i]=min(a[id[2][i]].b-a[id[2][i]].a,a[id[2][i]].b-a[id[2][i]].c);
//			bug(b[idxb].v);
		}
		sort(b+1,b+idx[2]+1);
		For(i,1,idx[2]-n/2){
			ans-=b[i];
		}
	}
	if(idx[3]>n/2){
//		sort(id[1]+1,id[1]+idx[1]+1);
		For(i,1,idx[3]){
			b[i]=min(a[id[3][i]].c-a[id[3][i]].a,a[id[3][i]].c-a[id[3][i]].b);
//			bug(b[idxb].v);
		}
		sort(b+1,b+idx[3]+1);
		For(i,1,idx[3]-n/2){
			ans-=b[i];
		}
	}
	printf("%lld\n",ans);
//	buggln
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		solve();
	}
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
