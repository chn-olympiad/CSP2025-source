/*
深搜枚举所有方案
再判断每个方案是否可行 
*/
#include<iostream>
#include<algorithm>
using namespace std;

bool b[5005];
int n,a[5005],y,wsum=0;

void polygon(int num)
{
	if(num<3){
		return;
	}else{
		int sum=0,maxn=-1;
		for(int i=1;i<=n;i++){
			if(b[i]){
				sum+=a[i];
				if(maxn<a[i]){
					maxn=a[i];
				}
			}
		}
		if(sum>maxn*2){
			wsum++;
		}
	}
}

void dfs(int num,int x)
{
	if(x>n){
		polygon(num);
		return;
	}
	b[x]=false;
	dfs(num,x+1);
	b[x]=true;
	dfs(num+1,x+1);
	return;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,1);
	printf("%d",wsum);
	
	fclose(stdin);
	fclose(stdout);
	
	
	return 0;
}
