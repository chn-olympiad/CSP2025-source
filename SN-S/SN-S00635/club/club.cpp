#include <bits/stdc++.h>
using namespace std;
int t, n, a[1000005][3],mxans,mxts;
int k[3], chang[1000005][3];
struct toa{
	int gx; //离开贡献
	int pos;//去往的社团编号 
	int ybh;//原来的编号 
};
toa toanother[1000005];
vector <vector<int>> tow(3);
bool cmp(toa x, toa y){
	return x.gx <  y.gx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	tow[0].reserve(1000005);
	tow[1].reserve(1000005);
	tow[2].reserve(1000005);
	cin >> t;
	while(t--){
		mxans = 0;
		cin >> n;
		for (int i=0; i<n; i++){
			memset(a[i],0,3);
		}
		memset(k,0,3);
		for (int i=0; i<n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];//输入每个人对3个社团的满意度。 
			chang[i][0] = a[i][0] - a[i][1];//从0换到1会对满意度总数加多少 
			chang[i][1] = a[i][1] - a[i][2];//从1到2加多少 
			chang[i][2] = a[i][2] - a[i][0];//从2到0加多少 
			mxts = max(max(a[i][0],a[i][1]),a[i][2]);//最大的满意度 
			mxans += mxts;//加到答案里 
			if (mxts == a[i][0]) {//去了0，0的人数加一，此编号加入0的编号集 
				k[0] ++;
				tow[0].push_back(i);
			}
			if (mxts == a[i][1]) {//去了1 
				k[1] ++;
				tow[1].push_back(i);
			}
			if (mxts == a[i][2]) {//去了2 
				k[2] ++;
				tow[2].push_back(i);
			}
 		}
 		//没有限制时的最大满意度，mxans 
 		for (int i=0; i<3; i++){//查看限制-每组人是否超标 
		 	if (k[i] > n/2){ //如果超标 
			 	for (int j=0; j<k[i]; j++){//遍历这一组里边的所有人- tow[i][j]
			 		//if (tow[i][j] == -1) continue;
			 	    int p=chang[tow[i][j]][2], q=-chang[tow[i][j]][1];//本来在第i组，两种交换方式增加多少最大满意度，存入p,q 
				 	if (i==0) {p=chang[tow[i][j]][0]; q=-chang[tow[i][j]][2];}
				 	if (i==1) {p=chang[tow[i][j]][1]; q=-chang[tow[i][j]][0];}
			 		if (p < q){//两种交换方式里边，损失较小的存进待比较序列
					 	toanother[j].gx = p;
					 	if (i==0) toanother[j].pos = 1;//要去的编号：
						if (i==1) toanother[j].pos = 2;
						if (i==2) toanother[j].pos = 0; 
					 	toanother[j].ybh = tow[i][j];
					}else{
						toanother[j].gx = q;
						if (i==0) toanother[j].pos = 2;
						if (i==1) toanother[j].pos = 0;
						if (i==2) toanother[j].pos = 1;
						toanother[j].ybh = tow[i][j];
					}
				}
				sort(toanother,toanother+k[i],cmp);//排序待比较序列，从大到小，前边加的多 
				for (int j=0; j<n/2; j++){
					tow[toanother[j].pos].push_back(toanother[j].ybh);//把多的人弹出去，弹到贡献最大的社团里边，做个标记，不能再回到这里了 
					k[toanother[j].pos] ++;
					//for (int kkk=0; i<tow[i].size(); i++){
					//	if (tow[i][kkk] == toanother[j].ybh){
					//		tow[i][kkk] = -1;
					//		break;
					//	}
					//}
					k[i] --;
					mxans -= toanother[j].gx;
				}
			}
		 }
		
		cout << mxans << endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
