#include<bits/stdc++.h>
using namespace std;

const int maxn=1e4+100;

int n,m,k; 	//n原有城市,m原有道路,k乡镇个数 
struct edge{
	int from,to,weigh;
}Edge[1000005+100005];
int num_of_bian;

int a[maxn];
long long sum=0;
int vis[maxn];
long long exsum=0; 
edge exbian[maxn];
int num_of=0;
bool visd[maxn];
int cij[100];

bool cmp(edge x,edge y){
	return x.weigh<y.weigh;
}

int find(int x){
	if(a[x]==x)return x;
	return a[x]=find(a[x]);
}

void unionn(int x,int y){
	a[find(x)]=y;
}

void kruskal(){
	int N=n+k;
	for(int i=1;i<=n+k;i++){
		a[i]=i;
	}
	sort(Edge,Edge+num_of_bian,cmp);
	for(int i=0;i<num_of_bian;i++){
		if(find(Edge[i].from)!=find(Edge[i].to)){
			unionn(Edge[i].from,Edge[i].to);
			N--;
			sum+=Edge[i].weigh;
			if(Edge[i].from>n){
				if(vis[Edge[i].from]>1){
					exsum+=cij[Edge[i].from-n-1]/2;
				}
				if(vis[Edge[i].from]==1){
					vis[Edge[i].from]=2;
					exsum-=exbian[Edge[i].from].weigh;
					if(visd[Edge[i].from]){
						sum-=1;
					}
				}
				else if(vis[Edge[i].from]==0){
					exsum+=Edge[i].weigh;
					exbian[Edge[i].from]=Edge[i];
					vis[Edge[i].from]=1;
				}
			}
		}
		if(N==1){
			break;
		}
	}
	sum-=exsum-1;
}





int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	
	int fromi,toi,weighi;
	
	for(int i=0;i<m;i++){
		cin>>Edge[num_of_bian].from>>Edge[num_of_bian].to>>Edge[num_of_bian].weigh;
		num_of_bian++;
	}
	int aij;
	for(int i=0;i<k;i++){
		cin>>cij[i];
		if(cij[i]%2!=0){
			visd[i]=true;
		}
		for(int j=0;j<n;j++){
			cin>>aij;
			Edge[num_of_bian].from=i+n+1;
			Edge[num_of_bian].to=j;
			Edge[num_of_bian].weigh=aij+cij[i]/2;
			num_of_bian++;
		}
	}
	kruskal();
	cout<<sum;
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int m=0;m<k;m++){
				if(bian[i][j]>xiang[m][i]+xiang[m][j]+xiang[m][n]){
					bian[i][j]=xiang[m][i]+xiang
				}
			}
		}
	}*/
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
