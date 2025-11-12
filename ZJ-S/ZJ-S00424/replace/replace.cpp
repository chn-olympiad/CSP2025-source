/* { | }*/
#include<bits/stdc++.h>
#define N 5000050
using namespace std;
int tr[N+1000050][30];
int num[N+1000050];
int fail[N+1000050];
int root=1,cnt=1;
int newnode(){
	cnt++;
	return cnt;
}
void insert(string s){
	int now=root;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(tr[now][s[i]-'a']==0){
			tr[now][s[i]-'a']=newnode();
		}
		now=tr[now][s[i]-'a'];
	}
	num[now]++;
	return;
}
int que[N+1000050];
void build(){
	int ta=0,he=1;
	fail[root]=root;
	for(int i=0;i<29;i++){
		if(tr[root][i]){
			fail[tr[root][i]]=root;
			que[++ta]=tr[root][i];
		}
		else tr[root][i]=1;
	}
	while(he<=ta){
		int now=que[he];he++;
		num[now]+=num[fail[now]];
		for(int i=0;i<29;i++){
			if(tr[now][i]){
				que[++ta]=tr[now][i];
				fail[tr[now][i]]=tr[fail[now]][i];
			}
			else {
				tr[now][i]=tr[fail[now]][i];
			}
		}
	}
	return;
}
int query(string s){
	int len=s.size();
	int now=root;
	int ans=0;
	for(int i=0;i<len;i++){
		now=tr[now][s[i]-'a'];
		ans+=num[now];
	}
	return ans;
}
char s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s %s",s1+1,s2+1);
		int len=strlen(s1+1);
		int l=n+1,r=0;
		for(int j=1;j<=len;j++){
			if(s1[j]!=s2[j]){
				l=min(l,j);
				r=max(r,j);
			}
		}
		if(l!=n+1&&r!=0){
			string xinchuan="";
			for(int j=1;j<l;j++)xinchuan.push_back(s1[j]);
			xinchuan.push_back('{');
			for(int j=l;j<=r;j++)xinchuan.push_back(s1[j]);
			xinchuan.push_back('|');
			for(int j=l;j<=r;j++)xinchuan.push_back(s2[j]);
			xinchuan.push_back('}');
			for(int j=r+1;j<=len;j++)xinchuan.push_back(s1[j]);
			insert(xinchuan);
		}
	}
	build();
	while(q--){
		scanf("%s %s",s1+1,s2+1);
		if(strlen(s1+1)!=strlen(s2+1)){
			puts("0");
			continue;
		}
		int len=strlen(s1+1);
		int l=n+1,r=0;
		for(int j=1;j<=len;j++){
			if(s1[j]!=s2[j]){
				l=min(l,j);
				r=max(r,j);
			}
		}
		string pipei="";
		for(int j=1;j<l;j++)pipei.push_back(s1[j]);
		pipei.push_back('{');
		for(int j=l;j<=r;j++)pipei.push_back(s1[j]);
		pipei.push_back('|');
		for(int j=l;j<=r;j++)pipei.push_back(s2[j]);
		pipei.push_back('}');
		for(int j=r+1;j<=len;j++)pipei.push_back(s1[j]);
		printf("%d\n",query(pipei));
	}
	return 0;
}