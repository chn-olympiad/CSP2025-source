#include <bits/stdc++.h>
using namespace std;

//这题第一个点说n和m都为1，那就说小R就在11，直接输出
//只有一百个，先排一次座位，然后遍历即可
//问题：如何进行蛇形排列？
//rp++!!!

bool cmp(int a,int b){
	return a>b;
}

int n,m;//n,m是座位数 
const int N = 15;
int a[N][N];
int score[N*N];
int q;//q对应的下标
int r;//r的分数 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i = 1;i<=n*m;i++){
		scanf("%d",&score[i]);
	}
	
	r = score[1];
	sort(score+1,score+n*m+1,cmp);
	
	for(int i = 1;i<=n;i++){
		if(i%2 == 1){
			for(int j = 1;j<=m;j++){
			//如果i是单数，就从1开始，反之从m开始 
				q++;
				a[i][j] = score[q];
			}
		}
		else{
			for(int j = m;j>=1;j--){
			//如果i是单数，就从1开始，反之从m开始 
				q++;
				a[i][j] = score[q];
			}
		}
	}
	//就找100次，非常快，不用写二分 
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(a[i][j] == r){
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	
} 
