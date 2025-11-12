#include<bits/stdc++.h>
using namespace std;
int a[103];
bool cmp(int a,int b){//分数从大到小排序 
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);//文件输入输出 
	int n,m,x;
	cin>>n>>m>>x;
	a[0]=x;//标记需要查找的分数 
	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m,cmp);//排序 
//	for(int i=0;i<n*m;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	int i=0;
	while(a[i]!=x){//找到分数排第几 
		i++;
	}
	i++;
//	cout<<i<<endl;
	int t1=i/n,t2;//判断行列 
	if(i%n!=0)t1++;
	if(t1&1==1){
		t2=i-(t1-1)*n;
	}
	else t2=n-(i-(t1-1)*n)+1;
	cout<<t1<<' '<<t2;
	return 0;
} 
