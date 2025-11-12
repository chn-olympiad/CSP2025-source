#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct Club{
	int s,d;
}a1[N],a2[N],a3[N];
struct Student{
	int d1,s1;
	int d2,s2;
	int si;
}st[N];
bool cmp(Student a,Student b){
	return a.d1>b.d1;
}
struct Student2{
	int c,s;
}a4[N],a5[N];
bool cmp2min(Student2 a,Student2 b){
	return a.c<b.c;
}
bool cmp2max(Student2 a,Student2 b){
	return a.c>b.c;
}
int a4n,a5n;
bool lk[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i].d,&a2[i].d,&a3[i].d);
			a1[i].s=1,a2[i].s=2,a3[i].s=3;
			if(a2[i].d<a3[i].d) swap(a2[i],a3[i]);
			if(a1[i].d<a2[i].d) swap(a1[i],a2[i]);
			if(a2[i].d<a3[i].d) swap(a2[i],a3[i]);
			st[i].d1=a1[i].d;
			st[i].s1=a1[i].s;
			st[i].d2=a2[i].d;
			st[i].s2=a2[i].s;
			st[i].si=i;
		}
		sort(st+1,st+n+1,cmp);
//		printf("New Students list\n");
//		for(int i=1;i<=n;i++){
//			printf("%d: %d-%d %d-%d %d\n",i,st[i].d1,st[i].s1,st[i].d2,st[i].s2,st[i].d1-st[i].d2); 
//		}
		int ans=0,cnt[4]={0,0,0,0};
		bool res=true;
		int breakpoint=0;	
		for(int i=1;i<=n;i++){
			if(cnt[st[i].s1]==n/2){
				res=false;
				breakpoint=i; 
				break;
			}
			ans+=st[i].d1;
			cnt[st[i].s1]++;
		}	
		if(res){
			printf("%d\n",ans);
			continue;
		}
		int cc=0;//人数超出的club编号 
		if(cnt[1]==n/2) cc=1;
		else if(cnt[2]==n/2) cc=2;
		else cc=3;
//		printf("club %d reached the limit\n",cc);
		a4n=0,a5n=0;
		for(int i=1;i<=n;i++){
			if(st[i].s1==cc){
				if(a4n<n/2){
//					printf("a4 push %d\n",i);
					a4[++a4n]=(Student2){st[i].d1-st[i].d2,i};//以cc为最优选择,且已选择cc的学生 
				}else{
//					printf("a5 push %d\n",i);
					a5[++a5n]=(Student2){st[i].d1-st[i].d2,i};//以cc为最优选择,但未能选择cc的学生 
				}				
			}
		}
		sort(a4+1,a4+a4n+1,cmp2min);
		sort(a5+1,a5+a5n+1,cmp2max);//尝试替换已决定选择cc的学生 
		for(int i=1;i<=n;i++) lk[i]=false;
		for(int i=1;i<=a5n;i++){
			if(a5[i].c>a4[i].c){
//				printf("replace %d with %d\n",a4[i].s,a5[i].s); 
				ans-=st[a4[i].s].d1;
				ans+=st[a4[i].s].d2;
				cnt[st[a4[i].s].s2]++;
				ans+=st[a5[i].s].d1;
				lk[a5[i].s]=true;
			}
		}
		for(int i=breakpoint;i<=n;i++){
			if(lk[i]) continue;
			if(cnt[st[i].s1]>=n/2){
				ans+=st[i].d2;
				cnt[st[i].s2]++;
			}else{
				ans+=st[i].d1;
				cnt[st[i].s1]++;					
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
