#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
const int maxl=5000005;
int n,q,nxt[maxl],ans;
string a[maxn][2];
string tx,ty;
int l,r;
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}

void check(int i,int j,int x,int y){
	string s=ty.substr(l,r-l+1);
	string ss=a[i][1].substr(j-r+l,r-l+1);
	if(s!=ss)return;
	s=a[i][0].substr(0,j-r+l);
	ss=a[i][1].substr(0,j-r+l);
	if(l-(j-r+l)<0)return;
	string sss=tx.substr(l-(j-r+l),j-r+l);
	if(s!=ss)return;
	if(s!=sss)return;
	s=a[i][0].substr(j+1);
	ss=a[i][1].substr(j+1);
	if(r+y-j-1>=x)return;
	sss=tx.substr(r+1,y-j-1);
	if(s!=ss)return;
	if(s!=sss)return;
	ans++;
}
void solve(){
	ans=0;
	cin>>tx>>ty;
	int x=tx.size(),y=ty.size();
	if(x!=y){printf("0\n");return;}
	l=-1;r=-1;
	for(int i=0;i<x;i++){
		if(tx[i]!=ty[i])r=i;
		if(tx[i]!=ty[i]&&l==-1)l=i;
	}
	string s=tx.substr(l,r-l+1);
//	for(int i=1;i<=n;i++){
//		y=a[i][0].size();
//		for(int j=0;j<y;j++){
//			bool flg=0;
//			for(int k=0;k<r-l+1;k++)
//				if(a[i][0][j+k]!=s[k]){flg=1;break;}
//			if(!flg){check(i,j+r-l);}
//		}
//	}
	s=' '+s;nxt[1]=0;
	for(int i=2;i<=r-l+1;i++){
		int j=i-1;
		while(j&&s[nxt[j]+1]!=s[i])j=nxt[j];
		if(s[nxt[j]+1]==s[i])nxt[i]=nxt[j]+1;
	}
	for(int i=1;i<=n;i++){
		y=a[i][0].size();
		if(r-l+1>y)continue;
		for(int j=0,k=1;j<y;j++){
			while(k!=1&&a[i][0][j]!=s[k])k=nxt[k-1]+1;
			if(a[i][0][j]==s[k])k++;
			if(k==r-l+2){check(i,j,x,y);}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	while(q--)solve();
	return 0;
}