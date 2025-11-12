#include<cstdio>
#include<algorithm>
using namespace std;
int line[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	bool flag=1;
	int n,m,r;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&line[i]);
	}
	r=line[1];
	sort(line+1,line+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		//printf("%d:%d%d\n",line[i],x,y);
		if(line[i]==r){
			printf("%d %d",y,x);
			return 0;
		}
		if(flag==1){
			x++;
			if(x>n){
				x=n;
				y++;
				flag=0;
			}				
		}
		else{
			x--;
			if(x==0){
				x=1;
				y++;
				flag=1;
			}
		}
	}
	return 0;
} 
