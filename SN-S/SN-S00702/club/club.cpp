//邹宋红  SN-S00702  杨凌衡水实验中学
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct nem{
	int a1;
	int a2;
	int a3;
};
long long t,n,ans,temp,num1,num2,num3;
int ye;
num ren[1000010];
bool used[100010];
vold dfs(int q){
	if(q==0){
	if(ans>tepm)temp=ans;
	return ;
}for (int i=1; i<=n; i++){
	if (used[i]){
		int tem;
		if (num1==n/2){
			if (num2==n/2){
				tem=ren[i].a1;
				}else{
					if(num3==n/2)tem=ren[i].a3
					else tem=max(ren[i].a2,max ren[1].a3)
				}
			}
			
		}
	}
	return ;
}
bool cup(num1,num2,num3){
	return nem1,nem2
}
int main{
	freopen("clud.in","r",stdin);
	freopen("clud.out","w",stdout);
	cin>>t;
	for (int j=1; j<=t; j++){
		temp=0;
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>ren[i].a1>>ren[i].a2;
		}
		dfs(n);
		cout<<temp<<endl;
	}
	return 0;
}
