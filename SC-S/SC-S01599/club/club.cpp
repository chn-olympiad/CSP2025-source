#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-'){
			f=-f;
		}
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
int s[100001][3];
int rs[3][100001];
pair<int,int>ss[100001];
int gs[3];
int md(int a){
	return a<3?a:a-3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,b,c,d;
	long long e;
	a=read();
	while(a--){
		gs[0]=0;
		gs[1]=0;
		gs[2]=0;
		b=read();
		e=0;
		for(int v=1;v<=b;++v){
			s[v][0]=read();
			s[v][1]=read();
			s[v][2]=read();
			if(s[v][0]>=s[v][1]&&s[v][0]>=s[v][2]){
				rs[0][++gs[0]]=v;
				e=e+s[v][0];
			}
			else if(s[v][1]>=s[v][2]){
				rs[1][++gs[1]]=v;
				e=e+s[v][1];
			}
			else{
				rs[2][++gs[2]]=v;
				e=e+s[v][2];
			}
		}
		c=-1;
		for(int v=0;v<3;++v){
			if(gs[v]>b/2){
				c=v;
				break;
			}
		}
		if(c>=0){
			for(int v=1;v<=gs[c];++v){
				d=rs[c][v];
				ss[v]={s[d][c]-max(s[d][md(c+1)],s[d][md(c+2)]),d};
			}
			sort(ss+1,ss+gs[c]+1);
			for(int v=1;v<=gs[c]-b/2;++v){
				e=e-ss[v].first;
			}
		}
		cout<<e<<'\n';
	}
	return 0;
} 