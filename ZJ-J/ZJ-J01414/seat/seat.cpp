#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int n,m,ai,r,sum,ans,lie;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read(),m=read(),r=read();
	sum=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			ai=read();
			if(r<=ai) sum++; 
		}
	}
	lie=(sum-1)/n+1;
	cout<<(sum-1)/n+1<<" ";
	ans=(sum-1)%n+1;
	if(lie%2==1) cout<<ans;
	else cout<<n-ans+1;
	return 0;
}
/*
->ni kan a chun ri de hu die
->ni kan ta chan dou zhe fei yue
->he feng yv nuan yang qing xie
->que bing leng,de ji jie
->ni kan a zhong xia de wan yue
->ni kan ta ba huan yv tou qie
->dao gua tian ji de xiao yan
...
->ni ting a qiu mo de luo ye
->ni ting ta tan xi zhe li bie
->zhi sheng wo du zi ling lve
->hai yv shan/feng he yue
->ni ting a dong zhi de bai xue
->ni ting ta yan shi zhe geng yan
->zai mei you ni de shi jie
(->zai mei you ni de..dong mian)
*/
