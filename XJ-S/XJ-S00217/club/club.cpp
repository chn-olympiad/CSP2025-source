#include<bits/stdc++.h>
using namespace std;
int data[100000][3];
int useData[100000][3];
int px[3][100000][3];
//1- 部门列表 2- 部门成员 3- 权重和意愿以及是否录取 
long long bmSigma[3][2];
int ans[5];
int main(){
	freopen("club.in", "r", stdin);
 	freopen("club.out", "w", stdout);

	int t;
	cin >> t;
	// 这样，我们先记录数据
	for (int d = 0; d<t; d++){
		// 这里就是我们的代码主体
		
		int people[3] = {0,0,0}; 
		int okok = 0;
		int n;
		cin >> n;
		for(int i = 0;i<n; i++){
			cin >> data[i][0] >> data[i][1] >> data[i][2];
		}
		for(int i = 0; i<n; i++){
			int m = 100000000;
			for(int p = 0; p<3; p++){
				m = min(data[i][p], m);
			}
			for(int p = 0; p<3; p++){
				useData[i][p] = data[i][p] - m;
//				cout << useData[i][p] << " "; 
			}
//			cout << "\n";
			for(int j = 0; j<3; j++){
				px[j][i][1] = data[i][j];
				px[j][i][0] = useData[i][j];
				px[j][i][2] = 0;
			}
		}
		for(int i =0; i<n; i++){
			for(int p = 0; p<3; p++){
				bmSigma[p][1] += useData[i][p]; 
				bmSigma[p][0] = p;
			}
		}
	//		这里需要一次排序以保证数据顺序 
		for(int i = 0; i<3; i++){
			for(int p = 0; p<n; p++){
				 for(int j = 0; j<n-1; j++){
				 	if(px[i][j][0] < px[i][j+1][0]){
				 		int swap[6];
						swap[0] = px[i][j][0];
						swap[1] = px[i][j][1];
						swap[2] = px[i][j][2];
						swap[3] = px[i][j+1][0];
						swap[4] = px[i][j+1][1];
						swap[5] = px[i][j+1][2];
						px[i][j][0] = swap[3];
						px[i][j][1] = swap[4];
						px[i][j][2] = swap[5];
						px[i][j+1][0] = swap[0];
						px[i][j+1][1] = swap[1];
						px[i][j+1][2] = swap[2];
					 } 
				 }
			}
		}
		//debug
//		for(int i = 0; i<3; i++){
//			for(int p = 0; p<n; p++){
//				for(int j = 0; j<3; j++){
//					cout << px[i][p][j] << " ";
//				}
//				cout << "\n";
//			}
//			cout << "-----\n";
//		}
		while((people[0] + people[1] + people[2])<n){
			// 排序和选人每次都要进行， 先排序再选人； 
			for(int i = 0; i<3; i++){
				for(int p = 0; p < 2; p++){
					if(bmSigma[p][1] < bmSigma[p+1][1]){
						int swap[4];
						swap[0] = bmSigma[p][0];
						swap[1] = bmSigma[p][1];
						swap[2] = bmSigma[p+1][0];
						swap[3] = bmSigma[p+1][1];
						bmSigma[p][0] = swap[2];
						bmSigma[p][1] = swap[3];
						bmSigma[p+1][0] = swap[0];
						bmSigma[p+1][1] = swap[1];
					}
				}
			}
//			cout << "aaaaaaaaaaaaa\n" << bmSigma[0][0] << " " << bmSigma[1][0] << " " << bmSigma[2][0] << "\n" << bmSigma[0][1] << " " << bmSigma[1][1] << " " << bmSigma[2][1] << "\n";
			int big = bmSigma[0][0];
			//这里记录的最大数组的索引
			//拿到最大部门就开始在该部门找权重最大者，每次找一个，找完一个就加people减bmSigma
			for(int i = 0; i<n; i++){ 
				if(px[big][i][2] == 1){
	//				cout << "j\n";
					continue;
				}
//				cout << "debug\n";
				// 早退出
				// 能走到这里就代表找到最大者了 
				// 纯抽象，这里的数据不连通，胡退出呢
				// 我需要一个函数，用于数据联通的同步
				// 要想想办法 要想想办法
				px[big][i][2] = 1;
	//			cout << "bz" << big << "\n";
				for(int k = 0; k<n; k++){
					if (data[k][big] == px[big][i][1]){
//						cout << "zhaodaole";
						int aaa[3] = {data[k][0],data[k][1],data[k][2]};
						for(int h = 0; h<n; h++){
							if((big!=0)&&(aaa[0]==px[0][h][1])){
								px[0][h][2] = 1;
								break;
							}if((big!=1)&&(aaa[1]==px[1][h][1])){
								px[1][h][2] = 1;
								break;
							}if((big!=2)&&(aaa[2]==px[2][h][1])){
								px[2][h][2] = 1;
								break;
							}
						} 
					}
				} 
				bmSigma[0][1] -= px[big][i][0];
				people[big]++;
				okok+=px[big][i][1];
				break;
			}
			if((n/2)==people[big]){
				bmSigma[0][1] = -1;
//				cout << "chufa\n";
			}
		}
		ans[d] = okok;
//		cout << okok << endl;
		okok = 0;
	}
//	输出结果
	for(int d = 0; d<t; d++){
		cout << ans[d] << "\n";
	} 
	return 0;
}
