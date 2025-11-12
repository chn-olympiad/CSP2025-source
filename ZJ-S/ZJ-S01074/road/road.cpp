#include<bits/stdc++.h>
using namespace std;
const int M=1e6+50;
const int N=1e5+50;
#define LL long long
int in(){
	char cc=getchar();
	int aa=0,bb=1;
	while(cc<'0'||cc>'9'){
		if(cc=='-')	bb=-1;
		cc=getchar();
	}
	while(cc>='0'&&cc<='9'){
		aa=aa*10+cc-'0';
		cc=getchar();
	}
	return aa*bb;
}
void out(LL aa){
	if(aa<0){
		aa=-aa;
		putchar('-');
	}
	if(aa<=9)	putchar(aa+'0');
	else{
		out(aa/10);
		putchar(aa%10+'0');
	}
	return ;
}

struct S{
	int go,w;
	bool operator <(const S & kks)const{
		if(w!=kks.w)	return w>kks.w;
		else return go>kks.go;
	}
};
vector<S> mp[N];
bool b[N];
priority_queue<S> q;
LL bfs1(){
	LL num=0;
	b[1]=1;
	int len=mp[1].size();
	for(int i=0;i<len;i++){
		if(b[mp[1][i].go]==0){
			q.push(mp[1][i]);
		}
	}
	while(!q.empty()){
		S now=q.top();
		q.pop();
		int from=now.go;
		if(b[from]==1)	continue;
	//	printf("%d %d\n",now.go,now.w);
		b[from]=1;
		num+=now.w;
		int len=mp[from].size();
		for(int i=0;i<len;i++){
			if(b[mp[from][i].go]==0){
				q.push(mp[from][i]);
			}
		}
	}
	return num;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=in(),m=in(),k=in();
	if(k==0){
		int u,v,w;
		for(int i=1;i<=m;i++){
			u=in();
			v=in();
			w=in();
			S s;
			s.go=v;
			s.w=w;
			mp[u].push_back(s);
			s.go=u;
			mp[v].push_back(s);
		}
		LL ans=bfs1();
		out(ans);
	}
	else{
		int u,v,w;
		for(int i=1;i<=m;i++){
			u=in();
			v=in();
			w=in();
			S s;
			s.go=v;
			s.w=w;
			mp[u].push_back(s);
			s.go=u;
			mp[v].push_back(s);
		}
		for(int i=1;i<=k;i++){
			int x=in();
			S s;
			for(int j=1;j<=n;j++){
				x=in();
				s.w=x;
				s.go=j;
				mp[n+i].push_back(s);
				s.go=n+i;
				mp[j].push_back(s);
			}
		}
		LL ans=bfs1();
		out(ans);
	}
}
/*
5 6 0
1 5 1
5 2 1
1 2 3
1 3 2
4 6 5
1 4 0
ans: 9
5 6 0
2 1 1
2 3 0
5 3 0
3 4 9
5 4 3
2 5 1
ans 4
*/
