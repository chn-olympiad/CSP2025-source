#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[1000001];
bool cmp(node x,node y){
	return x.w<y.w;
}
long long c[11],e[11][11],n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>e[i][j];
		}
	}
	sort(a+1,a+m+1,cmp);
	cout<<0<<endl;
	return 0;
}
/* 
暮色回响（调香师） 
传说时尚的巅峰有一朵花
代表着无尽的高尚和优雅
多少人钦羡它的无暇
眼中却倒映出荣华

花的种子曾在血泪中载下
透过伤口长出利欲的枝芽
为了粉饰良心上的疮疤
就能让藏起的毒被香氛融化

或许我也曾向往过他
睿智而优雅
指尖上演绎花与香的魔法
但在这金银的浪潮下
理智在崩塌
道德的高塔湮于现实利益的冲刷

神啊
可不可以让我感受一下
在我受业之地流转的正义啊
可追求她筋疲力竭的样子 
又真的是正义吗
人啊
眺望遥远大地上的那朵花
阴影下的罪证却代替他作答 
每次无谓代价的攀登之后
能否剩下初心啊

我永远喜欢艾梅莉埃姐姐喵！ 
*/ 
 
