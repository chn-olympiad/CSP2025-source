#include<bits/stdc++.h>
using namespace std;

int n,full,last;
struct mem{
	int x;
	int y;
	int z;
	bool canx;
	bool cany;
	bool canz;
//	mem(int in1, int in2, int in3):
//		x(in1),y(in2),z(in3){}
}mems[100005];

int ans = 0;
int choose[100005];
vector<int> choosex;
vector<int> choosey;
vector<int> choosez;
int sumx = 0, sumy = 0,sumz = 0;
int cntx = 0,cnty = 0,cntz = 0;

bool cmpx(int a, int b){
//	if(mems[a].x == mems[b].x) return max(mems[a].y,mems[a].z) < max(mems[b].y,mems[b].z);
//	return mems[a].x > mems[b].x;
	if(min(mems[a].x - mems[a].y,mems[a].x - mems[a].z) == min(mems[b].x - mems[b].y,mems[b].x - mems[b].z)){
		if(mems[a].x == mems[b].x){
			return max(mems[a].y,mems[a].z) > max(mems[b].y,mems[b].z);
		}
		return mems[a].x > mems[b].x;
	}
	return min(mems[a].x - mems[a].y,mems[a].x - mems[a].z) > min(mems[b].x - mems[b].y,mems[b].x - mems[b].z);
}
bool cmpy(int a, int b){
//	if(mems[a].y == mems[b].y) return max(mems[a].x,mems[a].z) < max(mems[b].x,mems[b].z);
//		else if(mems[a].x == mems[b].x && mems[a].z == mems[b].z)return m
//	return mems[a].y > mems[b].y;
	if(min(mems[a].y - mems[a].x,mems[a].y - mems[a].z) == min(mems[b].y - mems[b].x,mems[b].y - mems[b].z)){
		if(mems[a].y == mems[b].y){
			return max(mems[a].x,mems[a].z) > max(mems[b].x,mems[b].z);
		}
		return mems[a].y > mems[b].y;
	}
	return min(mems[a].y - mems[a].x,mems[a].y - mems[a].z) > min(mems[b].y - mems[b].x,mems[b].y - mems[b].z);
}
bool cmpz(int a, int b){
//	if(mems[a].z == mems[b].z) return max(mems[a].y,mems[a].x) < max(mems[b].y,mems[b].x);
//	return mems[a].z > mems[b].z;
	if(min(mems[a].z - mems[a].y,mems[a].z - mems[a].x) == min(mems[b].z - mems[b].y,mems[b].z - mems[b].x)){
		if(mems[a].z == mems[b].z){
			return max(mems[a].y,mems[a].x) > max(mems[b].y,mems[b].x);
		}
		return mems[a].z > mems[b].z;
	}
	return min(mems[a].z - mems[a].y,mems[a].z - mems[a].x) > min(mems[b].z - mems[b].y,mems[b].z - mems[b].x);
}

void solve(){
	cin >> n;
	for(int i = 1;i <= n;++i)mems[i].x = mems[i].y = mems[i].z = 0,mems[i].canx = mems[i].cany = mems[i].canz = 1;
	ans = 0;
	memset(choose,0,sizeof(choose));
	choosex.clear();
	choosey.clear();
	choosez.clear();
	sumx = 0, sumy = 0, sumz = 0;
	cntx = 0, cnty = 0, cntz = 0;
	full = n / 2;
	for(int i = 1;i <= n;++i){
		cin >> mems[i].x >> mems[i].y >> mems[i].z;
		if(mems[i].x >= mems[i].y && mems[i].x >= mems[i].z){
			choose[i] = 1;
			choosex.push_back(i);
			sumx += mems[i].x;
			++cntx;
		}
		else if(mems[i].y >= mems[i].x && mems[i].y >= mems[i].z){
			choose[i] = 2;
			choosey.push_back(i);
			sumy += mems[i].y;
			++cnty;
		}
		else if(mems[i].z >= mems[i].y && mems[i].z >= mems[i].x){
			choose[i] = 3;
			choosez.push_back(i);
			sumz += mems[i].z;
			++cntz;
		}
	}
//	cerr << sumx + sumy + sumz << endl;
	while(cntx > full || cnty > full || cntz > full){
		if(cntx > full){
			sort(choosex.begin(),choosex.end(),cmpx);
			while(cntx > full){
				last = choosex.back();
				
//				cerr << "-" << last << endl;
				
				mems[last].canx = 0;
				if(mems[last].cany * mems[last].y > mems[last].canz * mems[last].z){
					choose[last] = 2;
					choosey.push_back(last);
					sumy += mems[last].y;
					++cnty;
				}
				else{
					choose[last] = 3;
					choosez.push_back(last);
					sumz += mems[last].z;
					++cntz;
				}
				--cntx;
				choosex.pop_back();
				sumx -= mems[last].x;
			}
		}
		if(cnty > full){
			sort(choosey.begin(),choosey.end(),cmpy);
			while(cnty > full){
				last = choosey.back();
				mems[last].cany = 0;
				
//				cerr << "-" << last << endl;
				
				if(mems[last].canx * mems[last].x > mems[last].canz * mems[last].z){
					choose[last] = 1;
					choosex.push_back(last);
					sumx += mems[last].x;
					++cntx;
				}
				else{
					choose[last] = 3;
					choosez.push_back(last);
					sumz += mems[last].z;
					++cntz;
				}
				--cnty;
				choosey.pop_back();
				sumy -= mems[last].y;
//				--cnty;
			}
		}
		if(cntz > full){
			sort(choosez.begin(),choosez.end(),cmpz);
			while(cntz > full){
				last = choosez.back();
				
//				cerr << "-" << last << endl;
				
				mems[last].canz = 0;
				if(mems[last].canx * mems[last].x > mems[last].cany * mems[last].y){
					choose[last] = 1;
					choosex.push_back(last);
					sumx += mems[last].x;
					++cntx;
				}
				else{
					choose[last] = 2;
					choosey.push_back(last);
					sumy += mems[last].y;
					++cnty;
				}
				--cntz;
				choosez.pop_back();
				sumy -= mems[last].z;
			}
		}
	}
	cout << sumx + sumy + sumz << '\n';
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
//保佑今年CSP-J/S都是一等奖
// CCF的各位你们好
//工作辛苦了
//正好这几天马上就就要过万圣节了 
//那我就献上我这份糖(代码) 
//希望你们天天开心身体健康
//事业有成事事顺心
//这是我唯一能做的了
//thank for your reading 
