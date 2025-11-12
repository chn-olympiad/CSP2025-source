#include<bits/stdc++.h>

using namespace std;

int main(){
//刘家豪 SN-00096 延安市新区第三中学
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long m,ans,a;
	cin>>m;
	vector<int> v;
	for(int i=1;i<=m;i++){
		cin>>a;
		v.push_back(a);
	}
	v.sort(v.begin(),v.end(),less);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

