#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	static int sta[35];
	int top=0;
	do{
		sta[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar('0'+sta[top--]);
}
const int N=2e5+5;
int n,q;
string s[N][2],x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int ans=0;
		for(int j=1;j<=n;j++){
			int pos=x.find(s[j][0]);
			if(pos==-1)continue;
			string tmp=x;
			for(int k=0;k<(int)s[j][0].size();k++){
				x[pos+k]=s[j][1][k];
			}
			if(x==y)ans++;
			x=tmp;
			++pos;
			while(pos!=-1&&pos<(int)x.size()){
				pos=x.find(s[j][0],pos);
				if(pos==-1)break;
				tmp=x;
				for(int k=0;k<(int)s[j][0].size();k++){
					x[pos+k]=s[j][1][k];
				}
				if(x==y)ans++;
				x=tmp;
				++pos;
			}
		}
		write(ans);
		puts("");
	}
	return 0;
}