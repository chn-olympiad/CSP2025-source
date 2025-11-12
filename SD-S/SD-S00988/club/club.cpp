//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll ;
//typedef unsigned long long ull;
//const int INF = 1e5+7;
//int m0=0,m1=0,m2=0;
//int n,v,ct1,ct2,ct0;
//int dts[INF][5];
//int lb[INF];
//vector< pair<int,int> > bm0;//first is student, second is maxx
//vector< pair<int,int> > bm1;
//vector< pair<int,int> > bm2;
//	
//bool idy(int j){
//	if (j=0){
//		if (bm0.size()-ct0<=v)return true;
//	}if (j=1){
//		if (bm1.size()-ct1<=v)return true;
//	}if (j=2){
//		if (bm2.size()-ct2<=v)return true;
//	}
//	return false;
//}
//	
//void solve(){
//	memset(dts,0,sizeof(dts));
//	memset(lb,0,sizeof(lb));
//	m0=0,m1=0,m2=0;
//	cin >> n;
//	v = n/2;
//	for (int i=0; i<n; i++){
//		cin >> dts[i][0] >> dts[i][1] >> dts[i][2];
//		dts[i][4] = dts[i][0];
//		lb[i] = 0;
//		// 部门1为0 
//		if (dts[i][4]<dts[i][1]){
//			dts[i][4] = dts[i][1];
//			lb[i] = 1;
//		}
//		if (dts[i][4]<dts[i][2]){
//			dts[i][4] = dts[i][2];
//			lb[i] = 2;
//		}
//		if (lb[i] == 0){
//			bm0.push_back({i,dts[i][4]});
//			m0 += dts[i][4];
//		}if (lb[i] == 1){
//			bm1.push_back({i,dts[i][4]});
//			m1 += dts[i][4];
//		}if (lb[i] == 2){
//			bm2.push_back({i,dts[i][4]});
//			m2 += dts[i][4];
//		}
//	}
//	int cs=3;
//	while(cs--){
//		if (bm0.size()-ct0>v){
//			for (int i=0; i<sqrt(n); i++){
//				for (int j=0; j<n; j++){
//					if (bm0[i].second<bm0[i+1].second);
//					swap(bm0[i],bm0[i+1]);
//				}
//			}
//			for (int i=0; i<n; i++){
//			}
//			for (int i=0; i>bm0.size()-ct0-v; i++){
//				m0 -= bm0[i].second;
//				int idx = bm0[i].first+v;
//				int maxx = -10000;
//				int idd;
//				for (int j=0; j<3; j++){
//					if ((dts[idx][j]>maxx) && (dts[idx][j]!=bm0[i].second) && idy(j)){
//						maxx = dts[idx][j];
//						idd = j;
//					}
//				}
//				bm0[i].second = maxx;
//				if (idd = 1){
//					bm1.push_back(bm0[i]);
//					ct1++;
//				}if (idd = 2){
//					bm2.push_back(bm0[i]);
//					ct2++;
//				}
//			}
//		}
//		if (bm1.size()-ct1>v){
//			for (int i=0; i<sqrt(n); i++){
//				for (int j=0; j<n; j++){
//					if (bm1[i].second<bm1[i+1].second);
//					swap(bm1[i],bm1[i+1]);
//				}
//			}
//			for (int i=0; i>bm1.size()-ct1-v; i++){
//				m1 -= bm0[i].second;
//				int idx = bm1[i].first+v;
//				int maxx = -10000;
//				int idd;
//				for (int j=0; j<3; j++){
//					if (dts[idx][j] > maxx && dts[idx][j]!=bm1[j].second && idy(j)){
//						maxx = dts[idx][j];
//						idd = j;
//					}
//				}
//				bm1[i].second = maxx;
//				if (idd = 0){
//					bm0.push_back(bm1[i]);
//					ct0++;
//				}if (idd = 2){
//					bm2.push_back(bm1[i]);
//					ct2++;
//				}
//			}
//		}
//		if (bm2.size()-ct2>v){
//			for (int i=0; i<sqrt(n); i++){
//				for (int j=0; j<n; j++){
//					if (bm2[i].second<bm2[i+1].second);
//					swap(bm2[i],bm2[i+1]);
//				}
//			}
//			for (int i=0; i>bm2.size()-ct2-v; i++){
//				m0 -= bm0[i].second;
//				int idx = bm2[i].first+v;
//				int maxx = -10000;
//				int idd;
//				for (int j=0; j<3; j++){
//					if (dts[idx][j] > maxx && dts[idx][j]!=bm2[j].second && idy(j)){
//						maxx = dts[idx][j];
//						idd = j;
//					}
//				}
//				bm2[i].second = maxx;
//				if (idd = 1){
//					bm1.push_back(bm2[i]);
//					ct1++;
//				}if (idd = 0){
//					bm0.push_back(bm2[i]);
//					ct0++;
//				}
//			}
//		}
//	}
//	cout << m1+m2+m0 << endl;
//	return;
//}
//
//int main(){
//	freopen("club1.in","r",stdin);
//	freopen("club1.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
//	int t;
//	cin >> t;
//	while(t--){
//		solve();
//	}
//	return 0;
//}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef unsigned long long ull;
const int INF = 1e5+7;
int m0=0,m1=0,m2=0;
int n,v,ct1,ct2,ct0;
int dts[INF][5];
int lb[INF];
vector< pair<int,int> > bm0;//first is student, second is maxx
vector< pair<int,int> > bm1;
vector< pair<int,int> > bm2;
	
bool idy(int j){
	if (j=0){
		if (bm0.size()-ct0<=v)return true;
	}if (j=1){
		if (bm1.size()-ct1<=v)return true;
	}if (j=2){
		if (bm2.size()-ct2<=v)return true;
	}
	return false;
}
	
void solve(){
	memset(dts,0,sizeof(dts));
	memset(lb,0,sizeof(lb));
	m0=0,m1=0,m2=0;
	cin >> n;
	v = n/2;
	for (int i=0; i<n; i++){
		cin >> dts[i][0] >> dts[i][1] >> dts[i][2];
		dts[i][4] = dts[i][0];
		lb[i] = 0;
		// 部门1为0 
		if (dts[i][4]<dts[i][1]){
			dts[i][4] = dts[i][1];
			lb[i] = 1;
		}
		if (dts[i][4]<dts[i][2]){
			dts[i][4] = dts[i][2];
			lb[i] = 2;
		}
		if (lb[i] == 0){
			if (bm0.size()>v){
				bm0.push_back({i,dts[i][4]});
				m0 += dts[i][4];
			}else{
				bm2.push_back({i,dts[i][4]});
				m2 += dts[i][4];
			}
		}if (lb[i] == 1){
			if (bm1.size()>v){
				bm1.push_back({i,dts[i][4]});
				m1 += dts[i][4];
			}else{
				bm2.push_back({i,dts[i][4]});
				m2 += dts[i][4];
			} 
		}if (lb[i] == 2){
			bm2.push_back({i,dts[i][4]});
			m2 += dts[i][4];
		}
	}
	cout << m1+m2+m0 << endl;
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
