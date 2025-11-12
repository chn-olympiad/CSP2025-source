#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][5];// a[i][1-3]:记录学生满意度；
int sum[5];
struct Node{
	int val,id;
}data[5][N];// 储存社团学生信息（差值+编号）、社团人数；
bool cmp(Node a,Node b){
	if(a.val!=b.val) return a.val<b.val;
	else return a.id<b.id;
} 
long long int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=sum[1]=sum[2]=sum[3]=0;
		for(int i=1;i<=n;i++){// 初始化计算 
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2] and a[i][1]>=a[i][3]){
				ans+=a[i][1];
				if(a[i][2]>=a[i][3]) data[1][++sum[1]]={a[i][1]-a[i][2],i};
				else data[1][++sum[1]]={a[i][1]-a[i][3],i};
			}else if(a[i][2]>=a[i][1] and a[i][2]>=a[i][3]){
				ans+=a[i][2];
				if(a[i][1]>=a[i][3]) data[2][++sum[2]]={a[i][2]-a[i][1],i};
				else data[2][++sum[2]]={a[i][2]-a[i][3],i};
			}else if(a[i][3]>=a[i][1] and a[i][3]>=a[i][2]){
				ans+=a[i][3];
				if(a[i][1]>=a[i][2]) data[3][++sum[3]]={a[i][3]-a[i][1],i};
				else data[3][++sum[3]]={a[i][3]-a[i][2],i};
			}
		}
//		for(int i=1;i<=3;i++) cout<<sum[i]<<" ";
//		cout<<"\n";
//		cout<<ans<<"\n";
		for(int i=1;i<=3;i++){
			if(sum[i]>(n/2)){
				stable_sort(data[i]+1,data[i]+sum[i]+1,cmp);
				for(int j=1;j<=sum[i]-n/2;j++){
					ans-=data[i][j].val;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*

答题可能思路：

F1：思路分析： 
	先将假设所有学生成员都可以加入他们最满意的学校社团；
	再将已经“人满为患”学校社团找出对数个社团满意度差值较小的学生，更换社团；
	容易想到：不需要考虑到两个社团同时“人满为患”的情况，除非另一个社团一个人也没有；
	 
	可行性设计：
	先求出总理想ans值，在此过程中计算出学生最满意与次满意社团的差值；O(n) 
	计算出有哪一个社团人满为患，对差值最小的这部分学生进行社团更改。O(n)
	
	期望得分：
	100pts 
*/

/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13

*/