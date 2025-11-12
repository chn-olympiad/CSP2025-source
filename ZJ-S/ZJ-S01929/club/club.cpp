#include<cstdio>
#include<queue>
#define MAXN 100005
namespace IO{
	inline int read(void){
		register char c;
		register int res=0,e=1;
		do{c=getchar();}while(!(c<='9'&&c>='0'||c=='-'));
		if(c=='-')c='0',e=-1;
		do{res=(res<<1)+(res<<3)+c-'0';c=getchar();}while(c<='9'&&c>='0');
		return e*res;
	}
	inline void write(int x){
		if(x<0)x=-x,putchar('-');
		if(x>9)write(x/10);
		putchar(x%10+'0');
		return ;
	}
}using namespace IO;
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a<b?a:b;}
int T;//T<=5
int n;//n%2==0 n<=1e5
int a[MAXN][3];//a[i][j]<=2e4
struct node{
	int del,id;
	operator <(const node &th)const{
		return del>th.del;
	}
};
std::priority_queue<node> qt0,qt1,qt2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		int hn=n/2;
		for(int i=1;i<=n;i++){
			a[i][0]=read();
			a[i][1]=read();
			a[i][2]=read();
			
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				node f=(node){a[i][0]-max(a[i][1],a[i][2]),i};
				if(qt0.size()<hn)qt0.push(f);
				else{
					node bf=qt0.top();
					if(f.del>bf.del){
						qt0.pop();
						qt0.push(f);
						if(a[bf.id][1]>a[bf.id][2])qt1.push(bf);
						else qt2.push(bf);
					}else{
						if(a[i][1]>a[i][2])qt1.push(f);
						else qt2.push(f);
					}
				}
			}
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				node f=(node){a[i][1]-max(a[i][0],a[i][2]),i};
				if(qt1.size()<hn)qt1.push(f);
				else{
					node bf=qt1.top();
					if(f.del>bf.del){
						qt1.pop();
						qt1.push(f);
						if(a[bf.id][0]>a[bf.id][2])qt0.push(bf);
						else qt2.push(bf);
					}else{
						if(a[i][0]>a[i][2])qt0.push(f);
						else qt2.push(f);
					}
				}
			}
			else{
				node f=(node){a[i][2]-max(a[i][0],a[i][1]),i};
				if(qt2.size()<hn)qt2.push(f);
				else{
					node bf=qt2.top();
					if(f.del>bf.del){
						qt2.pop();
						qt2.push(f);
						if(a[bf.id][0]>a[bf.id][1])qt0.push(bf);
						else qt1.push(bf);
					}else{
						if(a[i][0]>a[i][1])qt0.push(f);
						else qt1.push(f);
					}
				}
			}
		}int ans=0;
		while(!qt0.empty()){
			node sft=qt0.top();
			qt0.pop();
			ans+=a[sft.id][0];
		}
		while(!qt1.empty()){
			node sft=qt1.top();
			qt1.pop();
			ans+=a[sft.id][1];
		}
		while(!qt2.empty()){
			node sft=qt2.top();
			qt2.pop();
			ans+=a[sft.id][2];
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}/*
it is impossible that 2 club over the limit together;
1 2 4     2
2 4 6     6
3 5 7     7
5 10 15   15
1 3 5     3
2 9 11    11
*/
