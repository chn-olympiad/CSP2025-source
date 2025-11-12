#include<bits/stdc++.h>
using namespace std;
int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
	return f*r;
}
const int maxn=200005,maxl=5000005;
int n,q,ans;
struct YXZ{
	string st[3];
}s[maxn],t[maxn];
int fd(char ch){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(s[mid].st[1][1]>=ch)r=mid-1;
		else if(s[mid].st[1][1]<ch)l=mid+1;
	}
	if(s[l].st[1][1]!=ch)return -1;
	return l;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)cin>>s[i].st[1]>>s[i].st[2];
	for(int i=1;i<=q;i++)cin>>t[i].st[1]>>t[i].st[2];
	sort(s+1,s+1+n);
	for(int i=1;i<=q;i++){
		ans=0;
		for(int j=0;t[i].st[1][j];j++){
			int pos=fd(t[i].st[1][j]);
			if(pos==-1)continue;
			for(;s[pos].st[1][1]==t[i].st[1][j];pos++){
				bool f=0;int k;
				for(k=0;s[pos].st[1][k];k++){
					if(s[pos].st[1][k]!=t[i].st[1][j+k]){f=1;break;}
				}
				if(f)continue;
				string r="";
				for(int ij=0;ij<j;ij++)r+=t[i].st[1][ij];
				for(int ij=0;ij<=k;ij++)r+=s[pos].st[2][ij];
				for(int ij=j+k;t[i].st[1][ij];ij++)r+=t[i].st[1][ij];
				if(r==t[i].st[2])ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}