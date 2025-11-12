#include<stdio.h>
#include<algorithm>
struct stu{
	int id,score;
	bool operator < (const stu&b){
		return score>b.score;
	}
};
namespace{
	int n,m;
	stu a[105];
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i].score),a[i].id=i;
	std::sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
		if(a[i].id==1) printf("%d %d",(i-1)/n+1,((i-1)/n+1)%2==0? n-(i-1)%n:(i-1)%n+1);
	fclose(stdin);fclose(stdout);
	return 0;
}