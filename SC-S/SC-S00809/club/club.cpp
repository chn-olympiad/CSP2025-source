#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7,inf=1e9+7;
int t,n,maxb=0,maxc=0,num[4]={0},ans=0;

struct node{
	int r,val,id_;
};
priority_queue<node>q[3];
bool operator <(const node &a,const node &b){
	return a.val>b.val;
}

struct ins{
	int a,b,c;
	int max1,max2,max3;
}val[N];

void dfs(int x,int sum,int na,int nb,int nc){
	if(max(na,max(nb,nc))*2>n){
		return;
	}
	if(x>n){
		if(max(na,max(nb,nc))*2<=n){
			ans=max(ans,sum);
		}
		return;
	}
	for(int i=x;i<=n;i++){
		dfs(i+1,sum+val[i].a,na+1,nb,nc);
		dfs(i+1,sum+val[i].b,na,nb+1,nc);
		dfs(i+1,sum+val[i].c,na,nb,nc+1);
	}	
}

bool cmp(const ins a,const ins b){
	return a.a>=b.a;
}

inline int find(int x,int i){
	if(x==val[i].a)return 1;
	else if(x==val[i].b)return 2;
	else return 3;
}

inline int finc(int x,int i){
	if(x==1)return val[i].a;
	else if(x==2)return val[i].b;
	else if(x==3)return val[i].c;
	else return 0;
}

inline int fink(int x,int i){
	if(x==1)return finc(val[i].max1,i);
	else if(x==2)return finc(val[i].max2,i);
	else return finc(val[i].max3,i);
}

inline int fint(int x,int i){
	if(x==1)return val[i].max1;
	else if(x==2)return val[i].max2;
	else return val[i].max3;
}
void add(int rank_,int i){
	int position=fint(rank_,i);
	if(rank_==3)return;
	q[position].push({rank_,(fink(rank_,i)-fink(rank_+1,i)),i});
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			val[i]={a,b,c};
			maxb=max(maxb,val[i].b);
			maxc=max(maxc,val[i].c);
			int max1,max2,max3;
			max1=max(a,max(b,c));
			if(max1==a){
				max2=max(b,c);
				max3=min(b,c);
			}else if(max1==b){
				max2=max(a,c);
				max3=min(a,c);
			}else{
				max2=max(a,b);
				max3=min(a,b);
			}
			val[i].max1=find(max1,i);
			val[i].max2=find(max2,i);
			val[i].max3=find(max3,i);
		}
		if(maxb==0&&maxc==0){
			sort(val+1,val+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=val[i].a;
			}
			printf("%d",ans);
		}else if(n<=10){
			dfs(1,0,0,0,0);
			printf("%d",ans);
		}else{
			for(int i=1;i<=n;i++){
				num[val[i].max1]++;
				ans+=finc(val[i].max1,i);
				add(1,i);
				for(int j=1;j<=3;j++){
					for(int z=1;z<=3;z++){
						if(num[z]>n/2){
							auto k=q[z].top();
							q[z].pop();
							int x=k.val;
							int r=k.r;
							ans-=x;
							num[z]--;
							num[fint(r+1,k.id_)]++;
							add(r+1,i);
						}
					}
				}
			}
			printf("%d",ans);
			for(int i=1;i<=3;i++){
				while(q[i].size()){
					q[i].pop();
				}
				num[i]=0;
			}
		}
		printf("\n");
	}
	return 0;
}
