#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100005;

struct node{
	int id;
	long long num;
};

node p[N][4];

int n;
bool cmp(node x, node y){
	return x.num > y.num;
}
bool cmp1(pair<int, node> x, pair<int, node> y){
	return (x.second.num - p[x.first][2].num) < (y.second.num - p[y.first][2].num);
}
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++){
		long long a, b, c;
		cin>>a>>b>>c;
		p[i][1].id=1;
		p[i][1].num=a;
		p[i][2].id=2;
		p[i][2].num=b;
		p[i][3].id=3;
		p[i][3].num=c;
		sort(p[i]+1, p[i]+4, cmp);
	}
	long long ans=0;
	vector<pair<int, node> > A, B, C;
	for(int i=1; i<=n; i++){
		if(p[i][1].id==1){
			A.push_back(make_pair(i, p[i][1]));
		}else if(p[i][1].id==2){
			B.push_back(make_pair(i, p[i][1]));
		}else{
			C.push_back(make_pair(i, p[i][1]));
		}
		ans += p[i][1].num;
	}
	sort(A.begin(), A.end(), cmp1);
	sort(B.begin(), B.end(), cmp1);
	sort(C.begin(), C.end(), cmp1);
	if(A.size()>(n/2)){
		int len = A.size()-(n/2);
		for(int i=0; i<len; i++){
			ans -= A[i].second.num - p[A[i].first][2].num;
		}
	}
	if(B.size()>(n/2)){
		int len = B.size()-(n/2);
		for(int i=0; i<len; i++){
			ans -= B[i].second.num - p[B[i].first][2].num;
		}
	}
	if(C.size()>(n/2)){
		int len = C.size()-(n/2);
		for(int i=0; i<len; i++){
			ans -= C[i].second.num - p[C[i].first][2].num;
		}
	}
	cout << ans << endl;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
} 
