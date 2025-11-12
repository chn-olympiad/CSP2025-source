#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

//luogu SproutPower

//duo ce yao qing kong.  duo ce yao qing kong.  duo ce yao qing kong.  duo ce yao qing kong.  duo ce yao qing kong.  
//duo ce yao qing kong.  duo ce yao qing kong.  duo ce yao qing kong.  duo ce yao qing kong.  duo ce yao qing kong.  
//duo ce yao qing kong.  duo ce yao qing kong.  duo ce yao qing kong.  duo ce yao qing kong.  duo ce yao qing kong.  
struct node{
	int x,y,z;//op = 1-x 2-y 3-z
	int cha,op;//cha = zui_da - ci_da
	bool operator <(const node b)const{return b.cha<cha;}
}a[N];

int n,ans;
int cntx,cnty,cntz;
priority_queue<node> pq;

void init(){
	cntx=cnty=cntz=0;
	while(!pq.empty())pq.pop();
	ans=0;
	return ;
}

void SOLVE(){
	
	init();
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		
		int max1,max2;
		if(a[i].x>=a[i].y && a[i].x>=a[i].z)
			max1=a[i].x,max2=max(a[i].y,a[i].z),cntx++,a[i].op=1;
		else if(a[i].y>=a[i].x && a[i].y>=a[i].z)
			max1=a[i].y,max2=max(a[i].x,a[i].z),cnty++,a[i].op=2;
		else 
			max1=a[i].z,max2=max(a[i].y,a[i].x),cntz++,a[i].op=3;
			
		a[i].cha=max1-max2;
		ans+=max1;
	}
	
//	for(int i=1;i<=n;i++)printf("%d %d\n",a[i].op,a[i].cha);puts("");

	if(cntx>(n>>1)){
		int k=cntx-(n>>1);
		for(int i=1;i<=n;i++)if(a[i].op==1)pq.push(a[i]);
		while(k--)ans-=pq.top().cha,pq.pop();
	}else if(cnty>(n>>1)){
		int k=cnty-(n>>1);
		for(int i=1;i<=n;i++)if(a[i].op==2)pq.push(a[i]);
		while(k--)ans-=pq.top().cha,pq.pop();
	}else if(cntz>(n>>1)){
		int k=cntz-(n>>1);
		for(int i=1;i<=n;i++)if(a[i].op==3)pq.push(a[i]);
		while(k--)ans-=pq.top().cha,pq.pop();		
	}
	
	printf("%d\n",ans);

	
	
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int Test_time=1;
	scanf("%d",&Test_time);
	while(Test_time--)SOLVE();
	return 0;
}
/*
I can't describe that I'm so stupid
I spend almost 30min in thinking T1

wo ben lai yi wei shi ge DP
jie guo fa xian zhi shi yi dao tang ti

I'm so lucky that I'm just 0'th grade
Some of my classmate are 2'th grade
they're 0 rong cuo

zen me mei ge da yang li dou yao shu mi ma
xian cun yi xia ba
password:
Ren5Jie4Di4Ling5%

o wo shi *** 
wo zhen de chun dao jia le

duo ce yao qing kong
duo ce yao qing kong
duo ce yao qing kong

15:15 pass the T1
*/
