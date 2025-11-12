#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,q,ch[N][26],tot,ans;
vector<pair<int,int>> tag[N];
char s[N],t1[N],t2[N];
vector<char>ss[N][2];
void ins(int ix,int nm){
	int u=0,len=strlen(s+1);
	ss[ix][nm].emplace_back(' ');
	for(int i=1;i<=len;i++){
		ss[ix][nm].emplace_back(s[i]);
		int go=s[i]-'a';
		if(!ch[u][go])ch[u][go]=++tot;
		u=ch[u][go];
	}
//	printf("put %d\n",u);
	tag[u].emplace_back(make_pair(ix,nm));
}
bool hzxd[N];
bool chk(int ix,int nm,int bg){
//	printf("%d %d %d\n",ix,nm,bg);
	for(int i=1;i<ss[ix][nm].size();i++){
		if(ss[ix][nm][i]!=t2[bg+i-1])return 0;
	}
	return hzxd[bg+ss[ix][nm].size()-1];
}
void go(int bg){
	int u=0,len=strlen(t1+1);
	for(int i=bg;i<=len;i++){
		int go=t1[i]-'a';
		if(!ch[u][go])break;
		u=ch[u][go];
//		printf("%d %d\n",bg,u);
		if(tag[u].size()){
			for(auto x:tag[u])if(x.second==0)
				ans+=chk(x.first,x.second^1,bg);
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);ins(i,0);
		scanf("%s",s+1);ins(i,1);
	}
	while(q--){
		scanf("%s%s",t1+1,t2+1);
		int len1=strlen(t1+1),len2=strlen(t2+1);
		if(len1!=len2){
			printf("0\n");continue;
		}
		for(int i=0;i<=len1+1;i++)hzxd[i]=0;
		hzxd[len1+1]=1;
		for(int i=len1;i>0;i--){
			hzxd[i]=hzxd[i+1]&(t1[i]==t2[i]);
		}
		for(int i=1;i<=len1;i++){
			go(i);
			if(t1[i]!=t2[i])break;
		}
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
}