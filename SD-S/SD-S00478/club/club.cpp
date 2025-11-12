#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define mkp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
//value
const int inf=2147483647;
const int mod=1e9+7;
const int N=1e5+5;
int a[N][3];
priority_queue<int,vector<int>,greater<int>>pq[3]; 


//function
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2;j++)cin>>a[i][j];
	}
	while(!pq[0].empty())pq[0].pop();
	while(!pq[1].empty())pq[1].pop();
	while(!pq[2].empty())pq[2].pop();
	int ans=0,cnt[3]={0,0,0};
	for(int i=1;i<=n;i++){
		//找最大与次大 
		int ma1,ma2;
		if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2]){
			ma1=0;
			if(a[i][1]>=a[i][2])ma2=1;
			else ma2=2;
		}
		if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2]){
			ma1=1;
			if(a[i][0]>=a[i][2])ma2=0;
			else ma2=2;
		}
		if(a[i][2]>=a[i][1] && a[i][2]>=a[i][0]){
			ma1=2;
			if(a[i][1]>=a[i][0])ma2=1;
			else ma2=0;
		}
		//统计答案 
		if(cnt[ma1]<n/2){
			cnt[ma1]++;
			ans+=a[i][ma1];
			pq[ma1].push(a[i][ma1]-a[i][ma2]);
		}
		else {
			int tmp=pq[ma1].top();
			int ans1=ans-tmp+a[i][ma1],ans2=ans+a[i][ma2];
			if(ans2>=ans1){
				ans=ans2;
			}
			else {
				ans=ans1;
				pq[ma1].pop();
				pq[ma1].push(a[i][ma1]-a[i][ma2]);
			}
		}
	} 
	cout<<ans<<endl;
	
	return;
}


int main(){
	ios::sync_with_stdio(0); 
	cin.tie(); 
	cout.tie();
	
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--)solve();
	
	//14:38看完所有题面，感觉有点完蛋 
	//14:47好像有点思路，贪心吗？
	//当一个社团满了另外两个社团一定没满
	//对于i，我贪心的把他放到他最喜欢的社团
	//如果没满我一定可以把他放进去
	//如果满了我就考虑二选一
	//14:51感觉出来了，写一写 
	//14:54不知道哪里在放歌，好神秘 
	//15:06草我好像不会优先队列的结构体 
	//15:09让我想一个奇妙方法 
	//15:37终于过了全部样例，严格不爆ll我就不开了 
	//谢谢你ccf
	
	return 0;
}

