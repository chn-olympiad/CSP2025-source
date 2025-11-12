#include <bits/stdc++.h>
using namespace std;
int cmd(int x, int y){
	return x>y;
}
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string ss;
	int dd[1000005], num=0;
	cin>>ss;
	for(int i=0;i<ss.size();i++){
		if(ss[i]>='0' || ss[i]<='9'){
			dd[++num] = int(ss[i]-'0');
		}
	}
	sort(dd+1, dd+num+1, cmd);
	for(int i=1;i<=num;i++){
		cout<<dd[i];
	}
	return 0;
}
