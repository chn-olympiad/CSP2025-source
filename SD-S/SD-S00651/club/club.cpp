#include<bits/stdc++.h>
using namespace std;
int n;
int a1[100005],a2[100005],a3[100005];
int num1,num2,num3;
int dfs(int dep,int sum){
	if(dep>n){
		return sum;
	}
	int ans1,ans2,ans3;
	if(num1<n/2){
		num1++;
		ans1=dfs(dep+1,sum+a1[dep]);
		num1--;
	}
	if(num2<n/2){
		num2++;
		ans2=dfs(dep+1,sum+a2[dep]);
		num2--;
	}
	if(num3<n/2){
		num3++;
		ans3=dfs(dep+1,sum+a3[dep]);
		num3--;
	}
	printf("%d",dep);
	return max(ans1,max(ans2,ans3));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		num1=0,num2=0,num3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		}
		printf("%d\n",dfs(1,0));
	}


	fclose(stdin);
	fclose(stdout);
	return 0;
}


