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
const int N=505;
int n,m;
string s;
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	freopen("D:\\temp\\csps\\down\\employ\\employ1.in","r",stdin);
	n=read(),m=read();
	cin>>s;
	sort(s.begin(),s.end());
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	int ans=0;
	do{
		int cnt_broken=0;
		int passed=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='1'||cnt_broken>a[i]){
				cnt_broken++;
			}else{
				passed++;
				if(passed>m){
					break;
				}
			}
		}
		if(passed==m){
			ans=(ans+1)%998244353;
		}
	}while(next_permutation(s.begin(),s.end()));
	print(ans);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


*/

