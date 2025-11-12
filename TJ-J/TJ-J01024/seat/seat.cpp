#include<bits/stdc++.h>
using namespace std;
int n,m,tmp,c,r;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>tmp;//标记特殊的（小R的） 
	a[1]=tmp;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}//初始定义A数组 
	sort(a+1,a+1+n*m);//对其排序，因为TMP以标记了小R的特殊值 
	for(int i=n*m;i>=1;i--){//寻找特殊值 
		if(a[i]==tmp){
			tmp=i;//找到了 
			break;//停止 
		}
	}
	tmp=(n*m)-tmp;//计算比小R成绩高的 
	c=(tmp/n)+1;//+1以防 C=0 
	if(c%2==1){//分类讨论（1）C是奇数 
		r=(tmp%m)+1;//奇数要+1以防=0 
	}
	if(c%2==0){//（2）C是偶数 
		r=m-(tmp%m);//偶数是倒着的，使用M减去，不可能=0 
	}
	cout<<c<<" "<<r;//输出 
	return 0;
}
