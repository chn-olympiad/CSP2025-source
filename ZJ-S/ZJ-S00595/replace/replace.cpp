#include<bits/stdc++.h>
using namespace std;
#define rep1(i,x,y) for(int i=(x);i<=(y);++i)
#define rep2(i,x,y) for(int i=(x);i>=(y);--i)
#define sp putchar(' ')
#define ln putchar('\n')
//#define int long long
int read(){
	int x=0;
	char c=getchar();
	bool p=0;
	while(c<'0'||c>'9'){
		p=(c=='-'?1:p);
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}return (p?~(x-1):x);
}void write(int x){
	if(x<0){
		putchar('-');
		x=~(x-1);
	}if(x>9)write(x/10);
	putchar(x%10|48);
}int n,q,l[200010],kmp[5000010];
char ch[5000010],chh[5000010];
vector<char>v1[200010],v2[200010];
int check(int p,int x,int le,int len){
	rep1(i,0,x-1)
		if(ch[i]!=chh[i])return 0;
	rep1(i,x,x+le-1)
		if(v2[p][i-x+1]!=chh[i])return 0;
	rep1(i,x+le,len)
		if(ch[i]!=chh[i])return 0;
	return 1;
}signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	rep1(i,1,n){
		cin>>ch;
		l[i]=strlen(ch);
		v1[i].push_back(' ');
		rep1(j,0,l[i]-1)v1[i].push_back(ch[j]);
		cin>>ch;
		v2[i].push_back(' ');
		rep1(j,0,l[i]-1)v2[i].push_back(ch[j]);
	}while(q--){
		cin>>ch>>chh;
		int len=strlen(ch),sum=0;
		if(len!=strlen(chh)){
			puts("0");
			continue;
		}rep1(i,1,n){
			int k=0;
			rep1(j,1,l[i])kmp[j]=0;
			rep1(j,1,l[i]){//kmp感觉要挂qwq 
				while(kmp[k]!=k&&v1[i][j]!=v1[i][k+1])k=kmp[k];
				if(v1[i][j]==v1[i][k+1])k++;
				kmp[j]=k;
//				puts("qwq");
			}
//			rep1(j,1,l[i])write(kmp[j]),sp;
//			ln;
			k=0;
			rep1(j,1,len){
				while(kmp[k]!=k&&ch[j-1]!=v1[i][k+1])k=kmp[k];
				if(ch[j-1]==v1[i][k+1])k++;
				if(k==l[i]){
					sum+=check(i,j-l[i],l[i],len);
					k=0;
				}
//				puts("qwq");
			}
		}write(sum);ln;
	}
	return 0;
}/*
期望 AC :1~5
期望得分:25pts
保守得分:10pts 
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

部分分给的太少了，而且极不可做:( 
*/
