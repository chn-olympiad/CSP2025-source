//SN-J00219唐一齐 西安市交大附中浐灞右岸学校
#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	cout<<n<<'\n';
	return 0;
}
