//SN-J00364 张柏洋 延安市新区培文学校
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	priority_queue<long long,vector<long long>,less<long long>> pq;
	while(cin>>c){
		if(c>='0' && c<='9'){
			long long l=int(c)-48;
			pq.push(l);
		}
	}
	long long n=pq.size();
	for(int i=1;i<=n;i++){
		cout<<pq.top();
		pq.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
