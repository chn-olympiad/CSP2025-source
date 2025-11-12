//code by JuRuoOIer(Luogu 476093)
//problem:club
//expected:100,O(n log n) for all
//time used:30mins
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#include<set>
#include<queue>
#include<deque>
#include<random>
#define ll long long
#define ull unsigned long long
#define lf double
#define ld long double
using namespace std;
void file(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
struct node{
	ll a[3],mx,sec;
};
bool operator <(node x,node y){
	return x.mx-x.sec<y.mx-y.sec;
}
ll T,n; 
inline ll getmx(node tmp){
	if(tmp.a[0]==tmp.mx)return 0;
	if(tmp.a[1]==tmp.mx)return 1;
	return 2;
}
node a[100010];
int main(){
	file();
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		ll s[3]={0,0,0},ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i].a[0]>>a[i].a[1]>>a[i].a[2];
			a[i].mx=max(a[i].a[0],max(a[i].a[1],a[i].a[2]));
			a[i].sec=a[i].a[0]+a[i].a[1]+a[i].a[2]-a[i].mx-min(a[i].a[0],min(a[i].a[1],a[i].a[2]));
			s[getmx(a[i])]++;
			ans+=a[i].mx;
		}
		ll id=3;
		if(s[0]>n/2)id=0;
		if(s[1]>n/2)id=1;
		if(s[2]>n/2)id=2;
		if(id==3){
			cout<<ans<<endl;
			continue;
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			if(getmx(a[i])==id){
				ans-=a[i].mx-a[i].sec;
				s[id]--;
				if(s[id]==n/2)break;
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
}
/*
如果说 飞鸟是世界的旅客
所见打成包裹
能不能 寄给远方的你呢
风 被雨水打湿了
擦干净暗淡银河
星星和音符跳跃着 正闪烁
碎片勾轮廓 故事用梦解锁
背光处漂泊 沙砾堆砌王国
此刻 闭上眼睛跟我哼这首歌
稚嫩的白鸽 展翅浴火
点燃黎明时的绯色
此刻 任由禁锢散落 孤独褪去吧
我要在我的 朋友身侧
牵手高歌 

Ren5Jie4Di4Ling5%

tarjan
v:<=
e:<
*/
