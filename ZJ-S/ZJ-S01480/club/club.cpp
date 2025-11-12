#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int st[N],nd[N],rd[N],cl[7];//club
struct person{
	int st,nd,rd,now,next,w1,w2,w3;//first,second,third
}p[N];//people
int cmp(person a,person b){
	return (a.now-a.next)<(b.now-b.next);
}
void find(int a,int b,int c,int x){
	int t=max(a,max(b,c));
	if(t==a){
		cl[1]++;p[x].w1=1;
		if(b>=c){
			p[x].st=a,p[x].nd=b,p[x].rd=c;
			p[x].w2=2;p[x].w3=3;
		}else{
			p[x].st=a,p[x].nd=c,p[x].rd=b;
			p[x].w2=3;p[x].w3=2;
		}
	}else if(t==b){
		cl[2]++;p[x].w1=2;
		if(a>=c){
			p[x].st=b,p[x].nd=a,p[x].rd=c;
			p[x].w2=1;p[x].w3=3;
		}else{
			p[x].st=b,p[x].nd=c,p[x].rd=a;
			p[x].w2=3;p[x].w3=1;
		}
	}else{
		cl[3]++;p[x].w1=3;
		if(a>=b){
			p[x].st=c,p[x].nd=a,p[x].rd=b;
			p[x].w2=1;p[x].w3=2;
		}else{
			p[x].st=c,p[x].nd=b,p[x].rd=a;
			p[x].w2=2;p[x].w3=1;
		}
	}
	p[x].now=p[x].st,p[x].next=p[x].nd;
	return ;
}
void change(int club,int n,int maxn){
	for(int i=1;i<=n;i++){
		if(p[i].w1==club){
			p[i].now=p[i].next;
			p[i].next=p[i].rd;
			p[i].w1=p[i].w2;
			p[i].w2=p[i].w3;
			cl[club]--;
			if(cl[club]<=maxn){
				break;
			}
		}
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		cl[1]=cl[2]=cl[3]=0;
		int n,a,b,c;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a,&b,&c);
			find(a,b,c,i);
		}
		sort(p+1,p+n+1,cmp);
		int maxn=n/2;
		for(int i=1;i<=3;i++){
			if(cl[i]>maxn){
				change(i,n,maxn);
			}
		}
		long long sum=0;
		for(int i=1;i<=n;i++){
			sum+=1ll*p[i].now;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
