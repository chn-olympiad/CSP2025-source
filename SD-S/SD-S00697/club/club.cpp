// 100pts
// 首先贪心分配 
// 若有部门超出 n/2 个，那么将所有人按与其他部门满意度的差排序，将差值小的放到其他部门 
#include<bits/stdc++.h>
using namespace std;
int read(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e5+10;
int ren[N][5],len[5];
void solve(){
	int n=read();
	vector<int>a[5]; // 存放着成员编号 
	for(int i=1;i<=n;++i){
		int x=read(),y=read(),z=read();
		ren[i][1]=x,ren[i][2]=y,ren[i][3]=z;
		if(x>=y&&x>=z)
			a[1].push_back(i);
		else if(y>=x&&y>=z)
			a[2].push_back(i);
		else a[3].push_back(i);
	}
	len[1]=a[1].size(),len[2]=a[2].size(),len[3]=a[3].size();
	int sum=0;
	for(int j=1;j<=3;++j)
		for(int i:a[j])
			sum+=ren[i][j];
	if(len[1]<=n/2&&len[2]<=n/2&&len[3]<=n/2){
		printf("%d\n",sum);
		return;
	}
	int p=0;
	for(int j=1;j<=3;++j)
		if(len[j]>n/2){
			p=j;
			break;
		}
	vector<int>jian;
	for(int i:a[p]){
		vector<int>temp;
		temp.push_back(ren[i][1]);
		temp.push_back(ren[i][2]);
		temp.push_back(ren[i][3]);
		sort(temp.begin(),temp.end());
		jian.push_back(temp[2]-temp[1]);
	}
	sort(jian.begin(),jian.end());
	int tot=len[p]-n/2; // 需要去掉多少个人
	int cnt=0; // 已经去掉了多少人 
	for(auto val:jian){
		sum-=val;
		++cnt;
		if(cnt>=tot)
			break;
	}
	printf("%d\n",sum);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
		solve();
	return 0;
}
/*
Input #1:

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

Output #1:

18
4
13

My Input #1:

1
6
9 8 0
9 7 0
9 6 0
9 5 0
9 4 0
9 3 0

My Output #1:

48

*/
