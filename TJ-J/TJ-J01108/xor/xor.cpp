#include<iostream>
#include<cstdlib>
#include<vector>
#include<string.h>
using namespace std;
const int MAXN = 5e5;
const int MAXK = 1048575;
const int MAXBIT = 20;
vector<vector<int>> a;
//第一维:多个分段
//第二维:所存数
int cntk = 0;//k的出现次数,ans的最小值
int n,k,ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	vector<int> v;
	for(int i=0;i<n;i++){
		int j;
		cin >> j;
		if(j==k){//k跳过
			if(!v.empty()&&v.size()>=2){
				a.push_back(v);
				v.clear();
			}
			cntk++;
		}else if(j){//非k0跳过
			v.push_back(j);
		}
	}
	if(!v.empty()&&v.size()>=2){
		a.push_back(v);
		v.clear();
	}
	ans = cntk;
	for(int i=0;i<a.size();i++){//遍历每个无k区间
		vector<int[2]> b;//存储合法区间起始和终点
		int maxl = a[i].size();
		vector<int> c = a[i];//起始为索引的组的异或
		b.push_back({0,maxl-1});
		for(int j=2;j<=maxl;j++){//分组长度在合法区间里
			int nmaxl = 0;
			for(int r=0;r<b.size();r++){//遍历每个区间
				vector<int[2]> b_;
				int s = b[r][0];
				for(int p=s;p+j<=b[r][1];p++){//遍历区间的起点
					c[p] = c[p]^a[i][p+j-1];//计算异或和
					if(c[p]==k){//将分段
						ans++;
						if(p-1-s>j){
							nmaxl = max(nmaxl,p-1-s);
							b_.push_back({s,p-1});
						}
						p += j;//[p,p+j-1]被征用了
					}
				}
				if(b[r][1]-s>j){
					nmaxl = max(nmaxl,b[r][1]-s);
					b_.push_back({s,b[r][1]});
				}
				b = b_;
			}
			maxl = nmaxl;
		}
	}
	cout << ans;
	return 0;
}


