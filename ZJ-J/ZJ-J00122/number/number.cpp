#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
priority_queue<int,vector<int>,less<int> > q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
		    q.push((int)s[i]-'0');
		}
	}
	while(q.size()){
		cout<<q.top();
		q.pop();
	}
	fclose(stdin);
	fclose(stdout);
	//#Shang4Shan3Ruo6Shui4
	//0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx
	return 0;
}
