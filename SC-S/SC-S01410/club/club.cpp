#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][3],n;
void update(int &f,int &s,int x){
	if(x>=f) s=f,f=x;
	else if(x>=s) s=x;
}
multiset<int> st[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int Tsk;cin>>Tsk;
	while(Tsk--){
		cin>>n;st[0].clear(),st[1].clear(),st[2].clear();
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		int ans=0;
		for(int i=1;i<=n;i++){
			int mxm=0,sec=0;
			for(int j=0;j<3;j++) update(mxm,sec,a[i][j]);
			for(int j=0;j<3;j++){
				if(a[i][j]==mxm){
					if((int)st[j].size()<n/2){
						st[j].insert(mxm-sec),ans+=mxm;
					}else{
						int beg=*st[j].begin();
						if(beg<=mxm-sec)
							st[j].erase(st[j].begin()),
							st[j].insert(mxm-sec),
							ans-=beg,ans+=mxm;
						else ans+=sec;
					}
					break;
				}	
			}
		}
		cout<<ans<<"\n";	
	}
	return 0;
}
/*FOOTNOTE
如果限制不存在，我们可以考虑直接贪心，
可是现在存在限制，那么我们可以考虑反悔贪心，
如果发现当前最大值已经放满，那么考虑找出替换之后
损失最少的人，尝试将其替换即可。我们知道
不可能在某次决策时存在两个集合都已经放满的情况
至多只有一个集合放满，同时这也意味着，
我们的贪心不会出问题，因为如果已经执行了满人替换操作，
那么对其他集合必然不可能再执行此操作了。我们不必
考虑其他集合的情况。 
做法的验证步骤已经完成。 
*/
