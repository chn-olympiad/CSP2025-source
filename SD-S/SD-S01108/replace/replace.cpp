#include<bits/stdc++.h>
#define N 3000500
#define ed puts("")
//#define mod 1000000007
#define p_ putchar(' ')
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar(45);
		x=~x+1;
	}
	static int sta[40];
	int top=0;
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while(top) putchar(sta[--top]+48);
	return;
}
struct node{
	string s1;
	string s2;
}mp[N];
int n,q,ans,num;
char s[3][N];
string s1,s2,s3,x,y,z,t1,t2;
char t[3][N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;++i){
		s1=s3,s2=s3;
		scanf("%s%s",s[1]+1,s[2]+1);
		for(int i=1;i<=strlen(s[1]+1);++i) s1+=s[1][i];
		for(int i=1;i<=strlen(s[2]+1);++i) s2+=s[2][i];
		mp[++num].s1=s1;
		mp[num].s2=s2;
	}
	for(int i=1;i<=q;++i){
		t1=s3,t2=s3;
		scanf("%s%s",t[1]+1,t[2]+1);
		for(int i=1;i<=strlen(t[1]+1);++i) t1+=t[1][i];
		for(int i=1;i<=strlen(t[2]+1);++i) t2+=t[2][i];
		int size1=t1.size();
		t1=" "+t1;
//		write(size1),ed;
		for(int j=1;j<=num;++j){
			int len=mp[j].s1.size();
			for(int k=1;k<=size1-len+1;++k){
				if(t1[k]==mp[j].s1[0]){
					x=s3;
					y=s3;
					z=s3;
					for(int l=1;l<k;++l) x+=t1[l];
					for(int l=k;l<=k+len-1;++l) y+=t1[l];
					for(int l=k+len;l<=size1;++l) z+=t1[l];
//					cout<<x<<" "<<y<<" "<<z<<endl; 
					if(y==mp[j].s1){
						if(x+mp[j].s2+z==t2) ++ans;
					}
				}
			}
		}
		write(ans),ed;
		ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
