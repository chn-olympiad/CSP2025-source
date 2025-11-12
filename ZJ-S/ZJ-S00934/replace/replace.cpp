#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,Q,st[N],ans,len1,len2;
char s1[N],s2[N];
struct Node{
	int len,samef,sameb;
	char s1[N],s2[N];
}s[N];
bool cmp(Node x,Node y){return x.len>y.len;}
void check(int tag,int l,int r){
	int tot=0;
	if (s[tag].samef+s[tag].sameb+(r-l+1)<s[tag].len) return;
	for (int i=1;i<=min(l,len1-s[tag].len+1);i++){
		int flag=1;
		for (int j=1;j<=s[tag].len;j++)
			if (s1[j+i-1]!=s[tag].s1[j]){flag=0;break;}
		if (flag) st[++tot]=i;
	}
	for (int i=1;i<=tot;i++){
		int flag=1;
		for (int j=1;j<=s[tag].len;j++)
			if (s2[st[i]+j-1]!=s[tag].s2[j]){flag=0;break;}
		if (flag) ans++;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++){
		scanf("%s",s[i].s1+1);scanf("%s",s[i].s2+1);
		s[i].len=strlen(s[i].s1+1);
	}
	sort(s+1,s+n+1,cmp);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=s[i].len;j++)
			if (s[i].s1[j]==s[i].s2[j]) s[i].samef++;
			else break;
		for (int j=s[i].len;j>=1;j--)
			if (s[i].s1[j]==s[i].s2[j]) s[i].sameb++;
			else break; 
	}
	while (Q--){
		scanf("%s",s1+1);scanf("%s",s2+1);
		len1=strlen(s1+1);len2=strlen(s2+1);
		if (len1!=len2){printf("0\n");continue;}
		else{
			int l=len1,r=1;
			for (int i=1;i<=len1;i++)
				if (s1[i]!=s2[i]) l=min(l,i),r=max(r,i);
			int t=1,w=n,bao=-1;
			while (t<=w){
				int mid=(t+w)>>1;
				if (s[mid].len>=(r-l+1)) bao=mid,t=mid+1;
				else w=mid-1;
			}
			if (bao==-1){printf("0\n");continue;}
			ans=0;
			for (int i=1;i<=bao;i++) 
				check(i,l,r);
			printf("%d\n",ans);
		}
	}
	return 0;
}

