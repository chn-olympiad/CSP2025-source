#include<bits/stdc++.h>//4TLE
using namespace std;
const int N=5010,P=998244353;
int n,a[N];
long long ret=0;
void bfs(int x,int sum){
	if(x==1){
		if(a[x]>sum){
			ret++;
			ret%=P;//可有可无 
		}return ;
	}bfs(x-1,sum-a[x]);bfs(x-1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}sort(a,a+n);
	if(n==3){
		if(a[0]+a[1]>a[2])printf("1");
		else printf("0");
		return 0;
	}//特判保分 
	//开始骗分
	if(n<25){//只算小数据 
		for(int i=n-1;i>=2;i--){
			bfs(i,a[i]);//100%TLE,小数据大抵能过 
		}printf("%lld",ret);
		return 0;
	}return 0;
}
