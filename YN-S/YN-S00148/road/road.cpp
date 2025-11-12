#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1e4+1000,RMAXN=3e6+1000;

struct node{
	long long u,v,w;
}; 

long long n,m,k,fa[MAXN],roadsln,jhn,ans;
long long town_data[20][2],tr_data[20][MAXN];
//long long char2num[9]={48,49,50,51,52,53,54,55,56};
long long test[RMAXN][3];
bool flag=1,rflag;
node roads[RMAXN];
char c;

void hb(long long x,long long y);
long long find(long long x);
bool cmp(node a,node b);
inline long long fread();
inline long long char2num(char c);

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	scanf("%lld %lld %lld",&n,&m,&k);
	n=fread(),m=fread(),k=fread();
	roadsln=m;
	jhn=n;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=0;i<m;i++){
//		roads[i]=node{fread(),fread(),fread()};
		roads[i].u=fread();
		roads[i].v=fread();
		roads[i].w=fread();
//		scanf("%lld %lld %lld",&roads[i].u,&roads[i].v,&roads[i].w);
//		scanf("%lld %lld %lld",&roads[i*2].u,&roads[i*2].v,&roads[i*2].w);
//		roads[i*2+1]=node{roads[i*2].v,roads[i*2].u,roads[i*2].w};
	}
	
	for (int i=0;i<k;i++){
//		scanf("%lld",&town_data[i][0]);
		town_data[i][0]=fread();
		if (town_data[i][0]!=0) flag=0;
		rflag=1;
		for (int j=1;j<=n;j++){
//			scanf("%lld",&tr_data[i][j]);
			tr_data[i][j]=fread();
			rflag&=(bool)tr_data[i][j];
			if (tr_data[i][j]==0){
				if (town_data[i][1]==0){
				    town_data[i][1]=j;
				}else{
					if (find(town_data[i][1])!=find(j)){
					    hb(town_data[i][1],j);
						jhn--;
					}
				}
			}
		}
		flag&=!rflag;
	}
	if (flag){
		for (int i=0;i<k;i++){
			for (int j=1;j<=n;j++){
				if (tr_data[i][j]!=0){
					roads[roadsln++]=node{town_data[i][1],j,tr_data[i][j]};
//					roads[roadsln++]=node{j,town_data[i][1],tr_data[i][j]};
				}
			}
		}
		sort(roads,roads+roadsln,cmp);
		for (int i=0;i<roadsln&&jhn>1;i++){
			if (find(roads[i].u)==find(roads[i].v)) continue;
			ans+=roads[i].w;
			hb(roads[i].u,roads[i].v);
			jhn--;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void hb(long long x,long long y){
	fa[find(x)]=find(y);
	return ;
}
long long find(long long x){
	if (fa[x]!=x) x=find(fa[x]);
	return fa[x];
}
bool cmp(node a,node b){
	return a.w<b.w;
}
inline long long fread(){
	char c='#';
	long long res=0LL;
	do{
		c=getchar();
	}while(c<'0'||c>'9');
	while (c>='0'&&c<='9'){
		res=res*10LL+char2num(c);
//		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
inline long long char2num(char c){
	if (c=='0') return 0LL;
	if (c=='1') return 1LL;
	if (c=='2') return 2LL;
	if (c=='3') return 3LL;
	if (c=='4') return 4LL;
	if (c=='5') return 5LL;
	if (c=='6') return 6LL;
	if (c=='7') return 7LL;
	if (c=='8') return 8LL;
	if (c=='9') return 9LL;
}
