#include<bits/stdc++.h>
using namespace std;
struct que{
	int s;
	int num;
	int now;
	bool r[10000];
};
int main(){
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	long long  m,Max=0;
	int n,k,sp,v,u,w;
	cin>>n>>m>>k;
	queue<que>q;
	for(long long i=0;i<m;i++){
		cin>>u>>v>>w;
		spd[u][v]=w;
		spd[v][u]=w;
	}
	que temp;
	temp.s=0;
	temp.num=1;
	temp.now=0;
	temp.r[0]=1;
	q.push(temp);
	while(!(q.empty())){
		for(int i=0;i<n;i++){
			if(q.front().r[i]==0){
				temp.s=q.front().s+spd[q.front().now][i];
				temp.now=i;
				temp.num=q.front().num+1;
				for(int j=1;j<n;j++){
					temp.r[j]=q.front().r[j];
				}
				temp.r[i]=1;
			}
			q.push(temp);
		}
		if(q.front().num==n){
			if(Max>q.front().s){
				Max=q.front().s;
			}
		}
		q.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
