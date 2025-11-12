//v11.20 3样例通过，输出的4种情况分别通过 
//v11.40 加了点注释 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int retotal;//排座位前面剩余多少人 
	int total=0;// 比小R高的人数 
	int b [1000];
	int n;//行数 
	int m;//列数 
	int d=1;//计数，计算到第几行 
	cin>>n>>m;
	for(int a=0;a<n*m;a++) { //输入 
		cin>>b[a];
	}
	for(int a=1;a<n*m;a++){ //检查比小R大的分数 
		if(b[0]<b[a]) total++;
	}
	retotal=total;//同步分数大于小R的人数 
	for(int c=1;c<=m;c++){ //计算第几列 
		if(retotal-n<=0) {d=c;break;} //每次把比小R高的人放入一列并切换下一行，如果剩下的人（分数比小R高的人）可以塞进一列，就跳出循环开始计算小R在哪 
		retotal=retotal-n;//重置比小R分数高且没有入座的人 
	} 
/*-----------------------------------计算座位的行位置（y轴）----------------------------*/ 
	if(d%2==0)// 剩下的（分数大于小R的）都可以进入偶数列的情况 
	{
		if(retotal+1<=n) cout<<d<<" "<<n-retotal;//人（包括小R）都在偶数列，依偶数方法计算
		if(retotal+1>n) cout<<d+1<<" "<<1;//小R被单独挤到奇数列，从上到下，直接输出第一行 
	} 
	if(d%2==1)//剩下的（分数大于小R的）都可以进入奇数列的情况 
	{
		if(retotal+1<=n)cout<<d<<" "<<retotal+1;//人（包括小R）都在奇数列，依奇数列计算方法计算 
		if(retotal+1>n) cout<<d+1<<" "<<n;//小R被单独挤到偶数列，从下到上，直接输出最后一行 
	} 
	return 0;//神秘return 0 
} 
//其实计算人数的时候可以直接把小R计算进去，可以把后面4if简化到2if，但是搞完了才发现，凑合着用吧 

