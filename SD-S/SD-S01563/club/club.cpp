#include<bits/stdc++.h>
#define int long long
#define MAXN 100007
using namespace std;
struct Node{
	int a,b,c;
};
int t,n;
Node s[MAXN];
int ans=0;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
bool cmp(Node A,Node B){
	return A.a>B.a;
}
void dfs(int sum,int cnt1,int cnt2,int cnt3){
	int w=cnt1+cnt2+cnt3;
	if(w>n){
		ans=max(ans,sum);
		return ;
	}
	if(cnt1<n/2){
		dfs(sum+s[w].a,cnt1+1,cnt2,cnt3);
	}
	if(cnt2<n/2){
		dfs(sum+s[w].b,cnt1,cnt2+1,cnt3);
	}
	if(cnt3<n/2){
		dfs(sum+s[w].c,cnt1,cnt2,cnt3+1);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	for(int i=1;i<=t;i++){
		ans=0;
		n=read();
		for(int j=1;j<=n;j++){
			s[j].a=read(),s[j].b=read(),s[j].c=read();
		}
		if(n>30){
			sort(s+1,s+n+1,cmp);
			for(int j=1;j<=n/2;j++){
				ans+=s[j].a;
			}
		}
		else{
			dfs(0,0,0,0);
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0 
4
3 2 1
1 2 3
2 1 3
3 1 2
8521987456321741596374123789512374195398746153275927529 is prime!
18:12
i'm sure that this code will get a score that not up to 20
so it's a completely lose
and i'm a eleven grade student so this is my last chance
a unperfect ending with one last duel
good luck to each oier
bye
story ending
//freopen ץ 
//freopen
//freopen
luogu uid 341801
AFO
*/
