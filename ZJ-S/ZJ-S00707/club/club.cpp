#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+100;
inline int read(){
	int x=0,f=1;
	char s=getchar();
	while(!isdigit(s)){
		if(s=='-')f=-1;
		s=getchar();
	}
	while(isdigit(s)){
		x=(x<<3)+(x<<1)+(s^48);
		s=getchar();
	}
	return x*f;
}
int n[N][5];
int tot[5];
bool p[N];
struct node{
	int val;
	int id;
	int type;
	bool operator<(const node&x)const{
		return val<x.val;
	}
};
node st[5][N];
int len[5];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int T;
	T=read();
	while(T--){
		priority_queue<node>v;
		while(!v.empty())v.pop();
		int a;
		a=read();
		ll ans=0;
		node t;
		tot[1]=tot[2]=tot[3]=0;
		len[1]=len[2]=len[3]=0;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=3;j++){
				n[i][j]=read();
			}
			if(n[i][1]>=n[i][2]&&n[i][1]>=n[i][3]){
				st[1][++len[1]]={n[i][1],i,1};
				tot[1]++;
				ans+=n[i][1];
			}
			else if(n[i][2]>=n[i][1]&&n[i][2]>=n[i][3]){
				st[2][++len[2]]={n[i][2],i,2};
				tot[2]++;
				ans+=n[i][2];
			}
			else if(n[i][3]>=n[i][2]&&n[i][3]>=n[i][1]){
				st[3][++len[3]]={n[i][3],i,3};
				tot[3]++;
				ans+=n[i][3];
			}
		}
		memset(p,0,sizeof p);
		int val,id,type;
		int s=1,x,y;
		int lim=a/2;
		if(tot[1]>lim)s=1,x=2,y=3;
		if(tot[2]>lim)s=2,x=1,y=3;
		if(tot[3]>lim)s=3,x=1,y=2;
		if(tot[s]>lim){
			while(len[s]){
				t=st[s][len[s]--];
				val=t.val;
				id=t.id;
				type=t.type;
				v.push({n[id][x]-n[id][s],id,x});
				v.push({n[id][y]-n[id][s],id,y});
			}
			node u;
			while(tot[s]>lim){
				u=v.top();
				v.pop();
				id=u.id;
				val=u.val;
				type=u.type;
				if(p[id])continue;
				tot[s]--;
				ans+=val;
				p[id]=1;
			}
		}
		cout<<ans<<"\n";
	}
	//Ren5Jie4Di4Ling5%
	
	
	return 0;
}