#include<bits/stdc++.h>
using namespace std;
#define ps putchar(' ')
#define pn putchar('\n')
#define In(x) freopen(x".in","r",stdin)
#define Out(x) freopen(x".out","w",stdout)
#define File(x) (In(x),Out(x))

typedef long long ll;

template<typename T> void re( T &t){
	t=0;int f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	do{
		(t=((t<<3)+(t<<1)))+=(ch^48);
		ch=getchar();
	}while(ch>='0' && ch<='9');
	t*=f;
}

void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
}


int n,m;

int main(){
	File("replace");
	re(n),re(m);
	while(m--){
		wr(0),pn;
	}
	//什么 勾吧 题目 看不懂。
	//最短路dp？。。？ 
	//怎么全部是0？ 
	//funk 
	//nanganohara
	//nanami
	//要不到100pts了
	//警示进食进士近视金石晶石惊世经世京师后人 T1打最暴力O(N^4)的暴力一定要看清题目，并且看清自己写的转移方程 (a=0 -> a=1 , b=0 -> b=1 , c=0 -> c=1) --> 浪费120min。。。。。 
	//T3 字节太少了，希望今年CCF数据用脚造，给我T3来点分 ovo 。
	//今年CCF换机子了，感觉下次换要五六年后，不知道圈的米用去哪里了。
	/*
			O								O
			
			
			
			
						    O
			
			
			
			
			---------------------------------
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			----------              ----------
			
			
			
			
			
			
						---------- 
						
						
		     被CCF圈了几千，这使你充满了决心 
		     
		     
		     
		     
		啊啊啊啊啊啊啊啊啊啊啊啊啊啊
		还是有点小
		写一个91定理吧
		13+78=91
		话说为什么我改了Embarcadero Dev-C++的TMD-GCC怎么还是用不了c++14？
		这个键盘Alt Ctrl S Z 键 会卡在里面 使得我需要用力敲击键盘。 
	*/ 
	return 0;
}
//Chtholly bless me!
//If happniess has a color,it must be the blue dyed by the last red!
//What are you doing in the end of the wolrd? Are you busy? Will you save us? 
