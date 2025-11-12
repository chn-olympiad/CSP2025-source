#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int n,k,ans = 0;
int nums[MAXN];
int qianzhui[MAXN];

struct qujian{
	int start;
	int endd;
	qujian(int a, int b):
		start(a),endd(b){}
};
vector<qujian> qj;

int getxor(int x, int y){
	return qianzhui[x-1] ^ qianzhui[y];
}

bool cmp(qujian a, qujian b){
	if(a.endd == b.endd)return a.start < b.start;
	else return a.endd < b.endd;
}

int askqj(int start,int endd){
	qj.clear();
	for(int i = start;i <= endd;++i){
		for(int j = i;j <= endd;++j){
			if(getxor(i,j) == k){
				qj.push_back(qujian(i,j));
			}
		}
	}
	sort(qj.begin(),qj.end(),cmp);
	
//	for(int i = 0;i < qj.size();++i){
//		cout << qj[i].start << ' ' << qj[i].endd << endl;
//	}
	
	int cnt = 0,index = 0;
	int lenth = qj.size();
	for(int i = 0;i < lenth;++i){
		if(qj[i].start > index){
			index = qj[i].endd;
			++cnt;
		}
	}
	
//	cout << start << "~" << endd << ":" << cnt << endl;
	
	return cnt;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;++i){
		cin >> nums[i];
		qianzhui[i] = qianzhui[i-1] ^ nums[i];
	}
	
	if(k == 1){
		int ans = 0;
		for(int i = 1;i <= n;++i){
			if(nums[i] == 1)++ans;
		}
		cout << ans;
		return 0;
	}
	
	ans = askqj(1,n);
	
	cout << ans;
	return 0;
}
