#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>line[1000010];
int a[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	scanf("%d %d %d",&n,&m,&k);
	if(k==0){
		for(int i=1;i<=m;i++){
			int u,v,l;
			a[i]=l;
		}		
		sort(a+1,a+1+m);
		for(int i=1;i<n;i++){
			ans+=a[i];
		}
		printf("%d",ans);
	}
	else{
		printf("0");
	}
	
	
	
	return 0;
} 
