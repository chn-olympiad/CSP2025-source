#include<bits/stdc++.h>
//#define int long long
using namespace std;
int tri[500005][26],tri2[500005][26],cnt1,cnt2;
char a[500005],b[500005];
vector<int>e[500005],g[500005];
int l,r;
void ins(int id){
	int n=strlen(a+1);
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		if(!tri[x][a[i]-'a'])tri[x][a[i]-'a']=++cnt1;
		if(!tri2[y][b[i]-'a'])tri2[y][b[i]-'a']=++cnt2;
		x=tri[x][a[i]-'a'];
		y=tri2[y][b[i]-'a'];
	}
	e[x].push_back(id);
	g[y].push_back(id);
}
char c[500001],d[500001];
int h[500001];
int job(int n,int ri){
	int x=0,y=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!tri[x][c[i]-'a']||!tri2[y][d[i]-'a'])return ans;
		x=tri[x][c[i]-'a'];
		y=tri2[y][d[i]-'a'];
		if(i>=ri){
			for(int v:e[x]){
				h[v]=1;
			}
			for(int v:g[y]){
				if(h[v])ans++;
			}
			for(int v:e[x]){
				h[v]=0;
			}
		}
	}
	return ans;
}
int work(){
	int n=strlen(a+1),m=strlen(b+1);
	if(n!=m){
		return 0;
	}
	l=1e9,r=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			l=min(l,i);
			r=max(r,i);
		}
	}
	int ans=0;
	for(int i=l;i>=1;i--){
		int tot=0;
		for(int j=i;j<=n;j++){
			c[++tot]=a[j];
		}
		tot=0;
		for(int j=i;j<=n;j++){
			d[++tot]=b[j];
		}
		ans+=job(n-i+1,r-i+1);
	}
	return ans;
}
struct node{
	int l,r,cha,len,type;
}que[500001];
int sum[5000005];
#define lowbit(x) (x&(-x))
void update(int x,int v){
	for(int i=x;i<=5000000;i+=lowbit(i))sum[i]+=v;
}
int query(int x){
	int res=0;
	while(x){
		res+=sum[x];
		x-=lowbit(x);
	}
	return res;
}
int ans[5000001];
bool cmp(node x,node y){
	if(x.cha==y.cha&&x.len==y.len)return x.type<y.type;
	return x.cha==y.cha?x.len<y.len:x.cha<y.cha;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	if(n<=1000&&q<=1000){
		for(int i=1;i<=n;i++){
			scanf("\n%s %s",a+1,b+1);
			ins(i);
		}
		for(int i=1;i<=q;i++){
			scanf("\n%s %s",a+1,b+1);
			printf("%d\n",work());
		}
	} else{
//		puts("114514");
		for(int i=1;i<=n;i++){
			scanf("%s %s",a+1,b+1);
			int len=strlen(a+1);
			for(int j=1;j<=len;j++){
				if(a[j]=='b')que[i].l=j;
				if(b[j]=='b')que[i].r=j;
			}
			que[i].cha=que[i].r-que[i].l;
			que[i].len=len-que[i].r+1;
			que[i].type=0;
		}
		int tot=n;
		for(int i=1;i<=q;i++){
			scanf("\n%s %s",a+1,b+1);
			int len=strlen(a+1),m=strlen(b+1);
			if(len!=m){
				ans[i]=0;
				continue;
			}
			++tot;
			for(int j=1;j<=len;j++){
				if(a[j]=='b')que[tot].l=j;
				if(b[j]=='b')que[tot].r=j;
			}
//			printf("%d %d\n",que[i].l,que[i].r);
			que[tot].cha=que[tot].r-que[tot].l;
			que[tot].len=len-que[tot].r+1;
			que[tot].type=i;
		}
		sort(que+1,que+1+tot,cmp);
		int las=1;
		for(int i=1;i<=tot;i++){
			if(que[i].cha!=que[i-1].cha){
				for(int j=las;j<=i-1;j++){
					if(que[j].type==0){
						update(que[j].l,-1);
					}
				}
				las=i;
			} 
//				if(que[i].cha==-2){
//					printf("%d %d %d %d\n",que[i].type,que[i].l,que[i].r,que[i].len);
//				}
			if(que[i].type==0){
				update(que[i].l,1);
			}else{
				ans[que[i].type]=query(que[i].l);
			}
		}
		for(int i=1;i<=q;++i){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}
/*
3 1
ab ac
aba aca
abaa acaa
aabaaa
aacaaa

题目太鬼了，不可战胜，这还是提高组吗

为什么我不复习字符串 
为什么我不复习字符串 
为什么我不复习字符串 


*/