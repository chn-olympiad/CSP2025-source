#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll T,n,a1,a2,a3;
struct node{
	ll x,y,z;
}a[100005];
bool cmp1(node X,node Y){
	return X.x>=Y.x;
}bool cmp2(node X,node Y){
	return X.y>=Y.y;
}bool cmp3(node X,node Y){
	return X.z>=Y.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cout<<T<<"\n";
		cin>>n;
		a1=0,a2=0,a3=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		sort(a+1,a+n+1,cmp1);
		ll b=n/2;
		for(ll i=1;i<=n;i++){
			if(b>0){
				a1+=a[i].x;
				b--;
			}else{
				a1+=max(a[i].y,a[i].z);
			}
		}sort(a+1,a+n+1,cmp2);
		b=n/2;
		for(ll i=1;i<=n;i++){
			if(b>0){
				a2+=a[i].y;
				b--;
			}else{
				a2+=max(a[i].x,a[i].z);
			}
		}sort(a+1,a+n+1,cmp3);
		b=n/2;
		for(ll i=1;i<=n;i++){
			if(b>0){
				a3+=a[i].z;
				b--;
			}else{
				a3+=max(a[i].y,a[i].x);
			}
		}
		cout<<max(a1,max(a2,a3))<<"\n";
	}
	return 0;
}
//哦太好了T1废了 ,玄关求条(bushi 
/*
要退役了
不知道写点什么
之前天天想着说着要退役
真要退役了 心里还是很难受啊
总之…
感谢陪伴吧
努力过了就好
不算太遗憾 
以我平均扣十分左右的作文成绩是写不出什么感人的话了(笑
考前颓废的时候就在想要写些什么了
但真到考场了发现肚子里没什么墨水
啥都写不出来
不过好的一点是今年天气虽然冷但是有太阳
去年SN还在下雨
浴谷的游记可能会写
但大概率是流水账 
*/
 
