#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch-'0'),ch=getchar();
	return x*f;
}
const int N=2e5+10;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read();
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}	
	while(q--){
		string x,y;
		cin>>x>>y;
		int l=0,r=0,ans=0,fg=0;
		for(int i=0;i<x.length();i++){
			if(x[i]!=y[i]){
				if(l!=0&&x[i-1]==y[i-1])l=-1;
				else if(fg==0){
					l=i;
					fg=1;
				}
			}
			if(x[i]==y[i]&&i>0&&x[i-1]!=y[i-1]){
				r=i-1;
			}
			if(r==0)r=x.length()-1;
		}
		if(l==-1){
			printf("0\n");
			continue;
		}
//		cout<<l<<' '<<r<<endl;
		for(int i=1;i<=n;i++){
			int flagsum=-1;
			for(int j=0;j<a[i].length();j++){
				if(j+(r-l)<a[i].length()&&a[i][j]==x[l]&&a[i][j+(r-l)]==x[r]){
//					cout<<i<<' '<<"hahaha\n";
					int flag=1;
					for(int k=j;k<=j+(r-l);k++){
						if(a[i][k]!=x[l+(k-j)]){
							flag=0;
							break;
						}
					}
					if(flag)flagsum++;
				}
			}
			for(int j=0;j<a[i].length();j++){
				if(j+(r-l)<a[i].length()&&b[i][j]==y[l]&&b[i][j+(r-l)]==y[r]){
					int flag=1;
					for(int k=j;k<=j+(r-l);k++){
						if(b[i][k]!=y[l+(k-j)]){
							flag=0;
							break;
						}
					}
					if(flag)flagsum++;
				}
			}
			if(flagsum==1){
				ans++;
//				cout<<a[i]<<' '<<b[i]<<endl;
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
