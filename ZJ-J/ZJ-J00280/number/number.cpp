#include <bits/stdc++.h>
using namespace std;
int n,m;
string a;
char s;
vector<int>  v;
bool cmp(int x, int y){
	if(x!=y) return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for(int i=0;i<a.size();i++){
		s=a[i];
		if('0'<=s&&s<='9'){
			v.push_back(s-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		cout << v[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
