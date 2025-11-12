//T2是我写的最后一份代码
//9：30
//1h已经拿到了324pts
//对于第2次参加csp的我已经足够满意
//不知道seat是不是保留字
//T2也不知道会不会挂
//100+100+60+64=324
//应该够了
//在检查了 
//uid: 992989 
//T3只会n^2，T4只会2^n和ai=1
//ai=1的式子应该是2^n-1-n-n*(n-1)/2吧
//数学方面还是比较自信的
//T1,T3,T4应该稳了啊
//显然我不可能写出T4正解
//冲一下T3
//去年因为T3没看题面被创飞了
//300->260 1= -> 2=
//今年J应该死不了了 
//也许T3有绿？？？
//n^2思路是找到所有成立的段然后贪心
//但这样预处理就n^2了
//wc!异或2次相当于没有异或！！！
//空间压下来了
//但是时间复杂度依然爆炸
//额啊难办
//新写法挂了???
//调不出来 
//预处理对了
//尝试降一下复杂度
//如果T3是二进制分拆的话那就直接扔了 
//希望西西弗数据水一点多过几个点 
//早知道多做这种2进制的题了
//昨天一直在复习图论啊啊啊啊啊啊啊
//下午S也许会考图论
//加油
//T3也许线段覆盖的方法只有60pts
//太难了
//last one hour
//不写了，检查了
//罚坐 
//T4刚才挂了，吓死了 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	int s=a[1],id=0;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i){
		if(a[i]==s){
			id=i;
			break;
		}
	}
	int t=(id-1)/n,x=id%n;
	if(x==0) x=n;
	if(t%2==0){
		cout<<t+1<<' '<<x<<endl;
	}else{
		cout<<t+1<<' '<<n+1-x<<endl;
	}
	return 0;
}
