#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[100005];

//void dfs(int i,int sum,int num){
//	if
//}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n<=2){
		int x,y;
		if(n==1){
			scanf("%d",&x);
			cout<<1;
			return 0;
		}
		else if(n == 2){
			scanf("%d%d",&x,&y);
			if(x==y){
				cout<<2;
			}
			else{
				cout<<1;
			}
			return 0;
		}
	}
//	else{
//		for(int i = 1;i<=n;i++){
//			scanf("%d",&a[i]);
//		}
//		for(int i = 1;i<=n;i++){
//			dfs();
//		}
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
