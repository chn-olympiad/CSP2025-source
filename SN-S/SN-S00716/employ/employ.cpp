//郭子羽 SN-S00716 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
void BFS(){
	queue<int> qx,qy;
	qx.push(1);
	qy.push(1);
	while(!qx.empty()){
		int nx = qx.front();
		int ny = qx.front();
		qx.pop(); qy.pop();
		for(int i = 0;i < 4;i++){
			int tx = nx + dx[i];
			int ty = ny + dy[i];
		}
	} return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	
	
	return 0;
}
