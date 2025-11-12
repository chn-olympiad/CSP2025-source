#include<bits/stdc++.h>
using namespace std;
int a[22000][22000],k,s[500010],n,z=0,me,c[500010];
struct whatt{
	int st,en;
}b[100000];
bool csp(whatt a,whatt b){
	if(a.st!=b.st){
		return a.st<b.st;
	}
	return a.en<b.en;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		a[i][i]=s[i];
		if(a[i][i]==k){
			b[++z]={i,i};
			if(i>=me){
				me=i;
			}
		}
		for(int j=1;j<i;j++){
			a[i][j]=a[j][i]=a[j][i-1]^s[i];
			if(a[i][j]==k){
				b[++z]={j,i};
				if(i>=me){
					me=i;
				}
			}
		}
	}
	sort(b+1,b+z+1,csp);
	for(int j=1;j<=n;j++){
		c[b[j].en]=max(c[b[j].en],c[b[j].st-1]+1);
		for(int k=b[j].en;k<=me;k++){
			c[k]=max(c[k],c[b[j].en]);
		}
	}
	cout<<c[me];
	return 0;
}
//《《真·只过样例1，其他直接运行错误 》》 
//经过修改,123AC,45WA,6RE 
//温馨提示：洋娃娃和小熊跳舞
//1234555434443213512345554344432131
//666545554344432135666545554344432131
//1234555434443213512345554344432131
//戴炎炳是  陈浩的爸爸  陈浩的七八  12345554344432
//没  1
//七  3
//八  5
//有一天他遇到了Lucia  1234555543
//大喊了一声  444432
//草  1
//你  3
//马  1
//Lucia听了  非常的高兴  回敬了一句  666654555543444432
//你  1
//马  3
//逼  5
//之后他们就结婚了  生了一个儿子   666654555543444432
//樊  1
//又  3
//齐  1
//樊又齐是一个钻头  一个钻头  1234555543444432
//M(没)  1
//C(七)  3
//C(七)  5
//有一天他遇到了挖掘机  1234555543
//大喊了一声  444432
//我  1
//爱  3
//你  1
//
//
// 
//大事不好，时间要超，内存要无 
//打表过样例
//暴力出奇迹 
//膜拜巨佬
//我是蒟蒻 
