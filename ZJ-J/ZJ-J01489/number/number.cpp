#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int> num;
char c[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c;
	for(int i=0;;i++){
		if((c[i]<'a'||c[i]>'z')&&(c[i]<'0'||c[i]>'9')){
			break;
		}
		if(c[i]>='0'&&c[i]<='9') num.push_back(c[i]-'0');
	}
	sort(num.begin(),num.end(),cmp);
	for(auto i:num) cout<<i;
	return 0;
}
