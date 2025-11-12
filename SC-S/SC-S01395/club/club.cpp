#include<bits/stdc++.h>
#define MAXT 9//应该是5，免得越界 
#define MAXN 200050
#define MAXN30 35
using namespace std;
int tot,s[MAXT];//tot是总的测试组数，s[]是对应方案的满意度 
struct Test{//test是测试组 
	int n,sum[3];
	int a[MAXN][3];
}test[MAXT];


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>tot;
	for(int i=1;i<=tot;i++){
		cin>>test[i].n;
		for(int j=1;j<=test[i].n;j++){
			for(int k=1;k<=3;k++)cin>>test[i].a[j][k];
		}
	}
	for(int i=1;i<=tot;i++){
		
		s[i]=max(max(test[i].a[1][3]+test[i].a[2][3],max(test[i].a[1][1]+test[i].a[2][1],test[i].a[1][2]+test[i].a[2][2])),max(test[i].a[1][3]+test[i].a[2][2],max(test[i].a[1][1]+test[i].a[2][2],test[i].a[1][1]+test[i].a[2][3])));
		cout<<s[i]<<endl;
	}


	return 0;
} 