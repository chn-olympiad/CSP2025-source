// csp-s-2025 T1 club
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn=1e5+10;

struct stu{
	int s1,s2,s3;
	bool flag;
}a[maxn];

int ans1,ans2,ans3;

int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		ans1=ans2=ans3=0;
		for(int i=0;i<n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			a[i].flag=false;
			ans+=max(a[i].s1,max(a[i].s2,a[i].s3));
		}
		cout<<ans<<endl;
	}
	return 0;
}
//分配n个人进入三个部门，每个部门人数不超过n/2，每个人进入部门时存在贡献，现在计算三个部门得到贡献的最大值 
//现将每个人放入自己满意度大的部门当中，如果某个部门人数超出限制
//那么留下满意度大的人到n/2，被删除的人放入次大满意度的部门当中，易得到下一个部门不会超出人数限制 n/2
//hack: 5 3 1 7 6 5 8 2 1 4 2 1 该贪心不成立 

