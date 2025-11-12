#include<bits/stdc++.h>
using namespace std;
//注意精度、时间、空间、scanf不能读取bool和string
//不要使用endl，不要关闭流同步，不要使用fclose
//比赛结束前不要登出程序回收系统，电脑密码123
//爆栈、除以零、越界访问、指针错误会re，set容易re
//记得删除调式代码，去掉文件读写的注释
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,u,v,w,sum=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		sum+=w;
	}
	cout<<sum;
	return 0;
}
//你们觉得会有不改造乡村且把道路全部修复的样例吗