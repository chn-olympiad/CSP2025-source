#include<bits/stdc++.h>
using namespace std;
struct stu{
	int point;
	int num;
}s[105];
int n,m; 
bool cmp(stu x,stu y){
	if(x.point==y.point){
		return x.num<y.num;
	}
	return x.point>y.point;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&s[i].point);
		s[i].num=i;
	}
	sort(s+1,s+1+n*m,cmp);
	int jl=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(s[jl++].num==1){
					printf("%d %d",i,j);
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}else{
			for(int j=1;j<=n;j++){
				if(s[jl++].num==1){
					printf("%d %d",i,j);
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		} 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
