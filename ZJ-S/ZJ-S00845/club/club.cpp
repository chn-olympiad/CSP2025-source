#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e5+5;
int num[5],stp[N];

struct INFO{
	int idx,val;
	bool operator<(const INFO&b)const{
		return val>b.val;//从大到小排序 
	}
}a[N][5],c[N][5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	/*
	贪心：
	先求最理想，然后改组代价最小的 
	默认最高，然后其次，最后再其次 
	*/ 
	while(T--){
		int ans=0;
		memset(num,0,sizeof(num));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].val;
				a[i][j].idx=j;
			}
			sort(a[i]+1,a[i]+3+1);
			
			ans+=a[i][1].val;
			num[a[i][1].idx]++;//首选这个 
			//c数组： 值：1.记录数据要变的值 2.记录是从几组变的
			//        下标：排序过的人下标 
			c[1][i]={a[i][2].idx,a[i][1].val-a[i][2].val};
			c[2][i]={a[i][3].idx,a[i][2].val-a[i][3].val};
			memset(a[i],0,sizeof(a[i]));
		}
		sort(c[1]+1,c[1]+n+1);
		sort(c[2]+1,c[2]+n+1);
		bool flag=0;
		do{//知道改完了为止 
			flag=0;
			for(int j=1;j<=3;j++){
				for(int i=1;i<=n;i++){
					if(num[j]>n/2&&c[i][stp[i]].idx==j){//总得改的是这个组的吧 
						//要改了
						stp[i]++;
						ans-=c[stp[i]][i].val;
						num[j]--;
						num[j+1]++;
						flag=1;
					}
				} 
			}
		}while(flag);
		for(int i=1;i<=n;i++)
			memset(c[i],0,sizeof(c[i])),
			stp[i]=0;
		
		cout<<ans<<'\n';
	}
	return 0;
}
