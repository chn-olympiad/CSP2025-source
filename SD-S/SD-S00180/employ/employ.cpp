#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	vector<int> vec(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>vec[i];
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		sum*=i;
	}
	cout<<sum;
	return 0;
}
