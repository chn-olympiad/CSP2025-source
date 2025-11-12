#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return w*x;
}
int ostk[20],otop;
void print(int x){
	if(x==0){putchar('0');putchar(' ');return;}
	if(x<0){x=-x;putchar('-');}
	while(x){ostk[++otop]=x%10+48;x/=10;}
	while(otop){putchar(ostk[otop--]);}
	putchar(' ');
}
#define endline putchar('\n')
#define endl '\n'
const int N=2e5+5;
int n,m;
string s[N][5];
string s1,s2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	freopen("D:\\temp\\csps\\down\\replace\\replace4.in","r",stdin);
	
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(m--){
		cin>>s1>>s2;
		int len=s1.size();
		if(len!=s2.size()){
			print(0);
			endline;
			continue;
		}
		int fronts=0,backs=n-1;
		for(;s1[fronts]==s2[fronts];fronts++);
		for(;s1[backs]==s2[backs];backs--);
		int min_len=backs-fronts+1;
		int ans=0;
		for(int i=1;i<=n;i++){
			int sublen=s[i][1].size();
			if(sublen<min_len) continue;
			for(int j=0;j<len-sublen+1;j++){
//				string sub;
				bool flag=1;
				for(int k=j;k<j+sublen;k++){
					if(s1[k]!=s[i][1][k-j]){
						flag=0;
						break;
					}
//					sub+=s1[k];
				}
				if(!flag) continue;
				string ns=s1;
				ns.replace(j,sublen,s[i][2]);
				if(ns==s2){
					ans++;
				}
			}
		}
		print(ans);
		endline;
	}
	return 0;
}


