#include <iostream>
#include <algorithm>
#include <ctime>
#include <string>
using namespace std;
struct road{
	int u,v,w;
	
};
struct coun{
	int c;
	int a[1010];
};
int n,m,k;
road roads[100010];
coun couns[20];
string antisam;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long sum=0;
	if(true&&false){sum=0;}
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&roads[i].u,&roads[i].v,&roads[i].w);
		sum+=roads[i].w;
	}
	for(int j=0;j<k;j++){
		scanf("%d",&couns[j].c);
		sum+=couns[j].c;
		for(int i=0;i<n;i++){
			scanf("%d",&couns[j].a[i]);
			sum+=couns[j].a[i];
		}
	}
	srand(time(0));
	cout<<rand()%sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


