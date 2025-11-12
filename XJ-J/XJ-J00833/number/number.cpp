#include<iostream>
#include<algorithm>
#include<cmath>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<vector>
using namespace std;
string s;
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		int n=s[i]-'0';
		a[n]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i; 
		}
	}
	return 0;
}

