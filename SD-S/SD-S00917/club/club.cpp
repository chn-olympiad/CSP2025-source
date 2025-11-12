#include<iostream>
#include<algorithm>
using namespace std;
long long t,n,sum = -9999999,flag2 = 0,flag3 = 0;
struct node{
	long long a,b,c;
}A[100100];
void dfs(long long step,long long ans,long long cnt1,long long cnt2,long long cnt3){
	if(step == n + 1){
		sum = max(sum,ans);
		return;
	}
	if(cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return;
	if(flag3 == 0 && flag2 != 0){
		dfs(step + 1,ans + A[step].a,cnt1 + 1,cnt2,cnt3);
		dfs(step + 1,ans + A[step].b,cnt1,cnt2 + 1,cnt3);
	}
	else{
		dfs(step + 1,ans + A[step].a,cnt1 + 1,cnt2,cnt3);
		dfs(step + 1,ans + A[step].b,cnt1,cnt2 + 1,cnt3);
		dfs(step + 1,ans + A[step].c,cnt1,cnt2,cnt3 + 1);
	}
	
}
int cmp(node x,node y){
	return x.a > y.a;
}
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	long long i,j;
	cin>>t;
	for(i = 1;i <= t;i++){
		cin>>n;
		for(j = 1;j <= n;j++){
			cin>>A[j].a>>A[j].b>>A[j].c;
			if(A[j].b != 0){
				flag2 = 1;
			}
			if(A[j].c != 0){
				flag3 = 1;
			}	
		}
		if(flag2 == 0 && flag3 == 0){
			sum = 0;
			sort(A + 1,A + 1 + n,cmp);
			for(j = 1;j <= n / 2;j++){
				sum += A[j].a;
			}
		}
		else{
//			sort(A + 1,A + 1 + n,cmp);
			dfs(1,0,0,0,0);
		}
		cout<<sum<<endl;
		sum = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Ren5Jie4Di4Ling5%
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
//1  2  3
	
      
    
