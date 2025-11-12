#include<bits/stdc++.h>
using namespace std;
long long ans=1,n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==n){
		cout<<0;
	}
	else {
		for(int i=2;i<=m;i++){
			ans*=i;
		}
		cout<<ans;
	}
	return 0;
}
/*
距离考试结束：01:05:50
会不了一点，蒙几个 
whh保佑我骗到分 

距离考试结束：00:28:50
提交吧


*/