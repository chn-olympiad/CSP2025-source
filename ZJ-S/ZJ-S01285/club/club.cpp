#include<bits/stdc++.h>
using namespace std;
//tanxin with regret!
void read(int &x){//focus on types
	x=0;
	int c;
	bool flag=0;
	c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			flag=1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(flag) x=-x;
	return ;
}
void write(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
	return ;
}
#define N 100100
int n,ans;
struct Club{
	int sati,clid;
	bool operator <(const Club &a)const{
		return sati<a.sati;
	}
	bool operator >(const Club &a)const{
		return sati>a.sati;
	}
}a[N][4];
int get_delt(int x,int ch){
	return a[x][ch].sati-a[x][ch-1].sati;
}
struct InQ{
	int sati,memb,chos;
	bool operator <(const InQ &kkk)const{
		return get_delt(memb,chos)>get_delt(kkk.memb,kkk.chos);
	} 
};
priority_queue<InQ> q[4];
bool replace_compare(InQ cpa,int x,int ch){
	if(cpa.chos==1) return true;
	if(get_delt(cpa.memb,cpa.chos)!=get_delt(x,ch)) return get_delt(cpa.memb,cpa.chos)>get_delt(x,ch);
	if(cpa.chos==2) return true;
	return get_delt(cpa.memb,cpa.chos-1)>get_delt(x,ch-1);
}
void replacemin(int x,int ch){
	int toq=a[x][ch].clid;
	if((int)q[toq].size()+(int)q[toq].size()<n){
		ans+=a[x][ch].sati;
		q[toq].push(InQ{a[x][ch].sati,x,ch});
		return ;
	}
	InQ cpa=q[toq].top();
	if(replace_compare(cpa,x,ch)){
		replacemin(x,ch-1);
		return ;
	}
	else{
		ans-=cpa.sati;
		ans+=a[x][ch].sati;
		q[toq].pop();
		q[toq].push(InQ{a[x][ch].sati,x,ch});
		replacemin(cpa.memb,cpa.chos-1);
	}
	return ;
}
void work(){
	while(!q[1].empty()) q[1].pop();
	while(!q[2].empty()) q[2].pop();
	while(!q[3].empty()) q[3].pop();
	read(n);
	for(int i=1;i<=n;++i){
		read(a[i][1].sati);
		read(a[i][2].sati);
		read(a[i][3].sati);
		a[i][1].clid=1,a[i][2].clid=2,a[i][3].clid=3;
		sort(a[i]+1,a[i]+4);
//		printf("%d %d %d\n",a[i][1].sati,a[i][2].sati,a[i][3].sati);
	}
	ans=0;
	for(int i=1;i<=n;++i){
		replacemin(i,3);
	}
	write(ans);
	putchar('\n');
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	read(T);
	while(T--){
		work();
	}
	return 0;
}
