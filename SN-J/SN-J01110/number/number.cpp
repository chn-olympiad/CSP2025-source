#include<bits/stdc++.h>
using namespace std;
string z;
priority_queue<long long>p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>z;
	for(int i=0;i<z.size();i++){
		if(z[i]<='9'&&z[i]>='0') p.push(z[i]-48);
	}
	while(p.size()){
		cout<<p.top();
		p.pop();
	}
	return 0;
}

