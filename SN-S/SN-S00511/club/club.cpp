#include"bits/stdc++.h"
using namespace std;
const int N = 1e5+7;
int t, n, a1[N], a2[N], a3[N];
int bm1, bm2, bm3;
int bms1, bms2, bms3; 
bool vis[N];
struct Node{
	int a1, a2, a3;
}student[N];
bool cmp1(Node x, Node y){
	return x.a1 > y.a1;
}
bool cmp2(Node x, Node y){
	return x.a2 > y.a2;
}
bool cmp3(Node x, Node y){
	return x.a3 > y.a3;
}

int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		int num = 0;
		bm1 = 0;bm2 = 0; bm3 = 0;
		bms1 = 0;bms2 = 0;bms3 = 0;
		for(int j = 1; j <= n; j++){
			vis[j] = false;
			a1[j] = 0;
			a2[j] = 0;
			a3[j] = 0;
		}
		for(int j = 1; j <= n; j++){
			cin >> a1[j] >> a2[j] >> a3[j];
			student[j].a1 = a1[j];
			student[j].a2 = a2[j];
			student[j].a3 = a3[j];
			vis[j] = true;
			if(a1[j] != 0) bms1++;
			if(a2[j] != 0) bms2++;
			if(a3[j] != 0) bms3++;
		}
		if(bms2 == 0 && bms3 == 0){
			sort(student+1, student+n+1, cmp1);
			for(int z = 1; z <= n / 2; z++){//只能进入第一个部门 
				num += student[z].a1;
			}
			cout << num << endl;
			continue;
		}
		if(bms1 == 0 && bms3 == 0){
			sort(student+1, student+n+1, cmp2);
			for(int z = 1; z <= n / 2; z++){//只能进入第二个部门 
				num += student[z].a2;
			}
			cout << num << endl;
			continue;
		}
		if(bms1 == 0 && bms2 == 0){
			sort(student+1, student+n+1, cmp3);
			for(int z = 1; z <= n / 2; z++){//只能进入第三个部门 
				num += student[z].a3;
			}
			cout << num << endl;
			continue;
		}
		for(int j = 1; j <= n; j++){
			if(a1[j] == 0){
				if(a2[j] == 0 && bm3 < n / 2){
					bm3++;
					num += a3[j];
				}else if(a3[j] == 0 && bm2 < n / 2){
					bm2++;
					num += a2[j];
				}else{
					if(a2[j] >= a3[j]){//第二个部门最满意 
						if(bm2 < n / 2){//第二个部门没满员 
							bm2++;
							num += a2[j];
						}else{//第三个部门
							bm3++;
							num += a3[j];
						} 
					}else{//第3个部门最满意 
						if(bm3 < n / 2){//第3个部门没满员 
							bm3++;
							num += a3[j];
						}else{//第2个部门
							bm2++;
							num += a2[j];
						}
					}
				}
			}
			if(a2[j] == 0){
				if(a3[j] == 0 && bm1 < n / 2){
					bm1++;
					num += a1[j];
				}else{
					if(a1[j] >= a3[j]){//第1个部门最满意 
						if(bm1 < n / 2){//第1个部门没满员 
							bm1++;
							num += a1[j];
						}else{//第三个部门
							bm3++;
							num += a3[j];
						} 
					}else{//第3个部门最满意
						if(bm3 < n / 2){//第3个部门没满员 
							bm3++;
							num += a3[j];
						}else{//第1个部门
							bm1++;
							num += a1[j];
						} 
					}
				}
			}
		}
		for(int j = 1; j <= n; j++){
			if(a1[j] >= a2[j] && a1[j] >= a3[j]){//第一个部门最满意 
				if(bm1 < n / 2){//第一个部门没满员 
					bm1++;
					num += a1[j];
				}else if(a2[j] >= a3[j] && bm2 < n / 2){//第二个部门 
					bm2++;
					num += a2[j];
				}else{//第三个部门
					bm3++;
					num += a3[j];
				} 
			}else if(a2[j] >= a1[j] && a2[j] >= a3[j]){//第二个部门最满意 
				if(bm2 < n / 2){//第二个部门没满员 
					bm2++;
					num += a2[j];
				}else if(a1[j] >= a3[j] && bm1 < n / 2){//第一个部门 
					bm1++;
					num += a1[j];
				}else{//第三个部门
					bm3++;
					num += a3[j];
				} 
			}else{//第三个部门最满意 
				if(bm3 < n / 2){//第三个部门没满员 
					bm3++;
					num += a3[j];
				}else if(a1[j] >= a2[j] && bm1 < n / 2){//第一个部门
					bm1++;
					num += a1[j];
				}else{//第二个部门
					bm2++;
					num += a2[j];
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}
