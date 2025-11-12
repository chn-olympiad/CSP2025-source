/*
#include<bits/stdc++.h>
using namespace std;
const int mxn=2e6+26;
int n,q,cnt[mxn],ans;
char s[2][mxn];
struct AI_ACAM{
	struct Node{
		int s[26],f;
		vector<int> id;
	}T[mxn];
	int cnt=1,u,m;
	inline void I(char *s,int id){
		u=1;
		m=strlen(s+1);
		for(int i=1,t;i<=m;i++){
			t=s[i]-'a';
			if(!T[u].s[t])
				T[u].s[t]=++cnt;
			u=T[u].s[t];
		}
		T[u].id.emplace_back(id);
		return ;
	}
	queue<int> qq;
	inline void B(){
		for(int i=0;i<26;i++)
			T[0].s[i]=1;
		qq.push(1);
		while(!qq.empty()){
			u=qq.front();qq.pop();
			for(int i=0,t;i<26;i++){
				t=T[u].s[i];
				if(!t)
					T[u].s[i]=T[T[u].f].s[i];
				else{
					T[t].f=T[T[u].f].s[i];
					qq.push(t);
				}
			}
		}
		return ;
	}
}t[2];
inline void Q(){
	int x=1,y=1;
	for(int i=1;i<=n;i++){
		x=t[0].T[x].s[s[0][i]-'a'];
		y=t[1].T[y].s[s[1][i]-'a'];
		for(int j=x;j;j=t[0].T[j].f)
			for(int k:t[0].T[j].id)
				cnt[k]++;
		for(int j=y;j;j=t[1].T[j].f)
			for(int k:t[1].T[j].id)
				ans+=cnt[k];
		for(int j=x;j;j=t[0].T[j].f)
			for(int k:t[0].T[j].id)
				cnt[k]--;
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s[0]+1,s[1]+1);
		t[0].I(s[0],i);t[1].I(s[1],i);
	}
	t[0].B();t[1].B();
	while(q--){
		scanf("%s%s",s[0]+1,s[1]+1);
		n=strlen(s[0]+1);
		if(n!=strlen(s[1]+1)){
			puts("0");
			continue;
		}
		ans=0;
		Q();
		printf("%d\n",ans);
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
const int mxn=226;
char s[mxn][2][mxn];
int n,m,q,l[mxn],ans;
inline bool C(char *a,int la,int ra,char *b,int lb,int rb){
	for(int i=la,j=lb;i<=ra&&j<=rb;i++,j++)
		if(a[i]!=b[j])
			return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s[i][0]+1,s[i][1]+1);
		l[i]=strlen(s[i][0]+1);
	}
	for(int i=1;i<=q;i++){
		scanf("%s%s",s[0][0]+1,s[0][1]+1);
		m=strlen(s[0][0]+1);
		if(m!=strlen(s[0][1]+1)){
			puts("0");
			continue;
		}
		ans=0;
		for(int j=1;j<=n;j++)
			for(int k=1;k+l[j]-1<=m;k++)
				if(C(s[0][0],1,k-1,s[0][1],1,k-1)&&\
					C(s[0][0],k+l[j],m,s[0][1],k+l[j],m)&&\
					C(s[0][0],k,k+l[j]-1,s[j][0],1,l[j])&&\
					C(s[0][1],k,k+l[j]-1,s[j][1],1,l[j]))
						ans++;
		printf("%d\n",ans);
	}
	return 0;
}
