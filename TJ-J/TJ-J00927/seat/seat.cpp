#include<cstdio>//AC
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10*10+5;
int arr[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	int tot=n*m;
	int tag=1;
	scanf("%d",&arr[1]);
	for(int i=2;i<=tot;i++){
		scanf("%d",&arr[i]);
		if(arr[i]>arr[1]) tag++;
	}
	int line=tag/n,row=tag%n;
	if(row==0) row=n;
	if(tag!=line*n) line++;
	printf("%d ",line);
	if(line&1) printf("%d",row);
	else printf("%d",n-row+1);
	
	return 0;
}
