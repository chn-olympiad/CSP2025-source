#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct road{
	int start;
	int end;
	int weigh;
	short newcity;
}Roads[1100005];


int quick_read(){
	int p=0;
	while (1){
		char c=getchar();
		if ('0'<=c && c<='9'){
			p=c-'0';
			break;
		}
	}
	while (1){
		char c=getchar();
		if ('0'<=c && c<='9'){
			p=p*10+(c-'0');
		}
		else{
			break;
		}
	}
	return p;
}


int roads_cnt;
long long ans;
long long preans;
bool newcity[12];
int newcost[12];

bool operator<(road A,road B){
	if (A.weigh>B.weigh){
		return false;
	}
	return true;
}

int boss[10025];
int find_boss(int A){
	int t=A;
	while (boss[t]!=t){
		t=boss[t];
	}
	boss[A]=t;
	return t;
}
void join_boss(int A,int B){
	int a=find_boss(A);
	int b=find_boss(B);
	if (a!=b){
		boss[b]=a;
	}
}

void myinit(){
	for (int i=1;i<=n+k;i++){
		boss[i]=i;
	}
	ans=0;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//´æ´¢ 
	newcity[0]=1;
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=n;i++){
		boss[i]=i;
	}
	for (int i=1;i<=m;i++){
		int u,v,w;
		//scanf("%d %d %d",&u,&v,&w);
		u=quick_read();
		v=quick_read();
		w=quick_read();
		Roads[i].start=u;
		Roads[i].end=v;
		Roads[i].weigh=w;
	}
	roads_cnt=m;
	
	for (int i=1;i<=k;i++){
		//scanf("%d",&newcost[i]);
		newcost[i]=quick_read();
		for (int j=1;j<=n;j++){
			Roads[roads_cnt+1].start=n+i;
			Roads[roads_cnt+1].end=j;
			//scanf("%d",&(Roads[roads_cnt+1].weigh));
			Roads[roads_cnt+1].weigh=quick_read();
			Roads[roads_cnt+1].newcity=i;
			roads_cnt+=1;
		} 
	}
	sort(Roads+1,Roads+roads_cnt+1);
	
	for (int i=1;i<=roads_cnt;i++){
		int u=Roads[i].start;
		int v=Roads[i].end;
		int w=Roads[i].weigh;
		bool t=newcity[Roads[i].newcity];
		if (t){
			if (find_boss(u)!=find_boss(v)){
				join_boss(u,v);
				ans+=w;
			}
		}	
	}
	//printf("%lld \n",ans);
	
	preans=ans; 
	for (int ct=1;ct<=k;ct++){
		myinit();
		ans=0;
		newcity[ct]=1;
		ans+=newcost[ct];
		for (int i=1;i<=roads_cnt;i++){
			int u=Roads[i].start;
			int v=Roads[i].end;
			int w=Roads[i].weigh;
			bool t=newcity[Roads[i].newcity];
			if (t){
				if (find_boss(u)!=find_boss(v)){
					join_boss(u,v);
					ans+=w;
				}
			}
		}
		//printf("%lld \n",ans);
		if (ans<preans){
			preans=ans;
			
		}else{
			newcity[ct]=0;
		}
	}
	
	printf("%lld\n",preans);
	
	
	

	fclose(stdin);
	fclose(stdout);
	return 0;
} 
