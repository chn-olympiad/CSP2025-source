#include<bits/stdc++.h>
using namespace std;
//
//注意精度、时间、空间、scanf不能读取bool和string
//不要使用endl，不要关闭流同步，不要使用fclose
//比赛结束前不要登出程序回收系统，电脑密码123
//爆栈、除以零、越界访问、指针错误会re，set容易re
//记得删除调式代码，去掉文件读写的注释
int T,n,a[100050][3],sum=0,u,v,w;
vector<int>arr;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			int maxn=0,maxl=-1;
			if(maxn<a[i][0]&&u<=n/2)maxn=a[i][0],maxl=0,u++;
			if(maxn<a[i][1]&&v<=n/2)maxn=a[i][1],maxl=1,v++;
			if(maxn<a[i][2]&&w<=n/2)maxn=a[i][2],maxl=2,w++;
			if(maxl!=-1)arr.push_back(a[i][maxl]);
		}
		sort(arr.rbegin(),arr.rend());
		for(int i=0;i<n;i++){
			sum+=arr[i];
			arr[i]=0;
		}
		cout<<sum<<'\n';
	}
	return 0;
}
//这是什么**题