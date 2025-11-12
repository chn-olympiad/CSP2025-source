#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define ull unsigned long long
using namespace std;
const int N=1e6+10;
string s;
int l,a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	s=' '+s;
	int w=1;
	for (int i=1;i<=l;i++){
		if (s[i]-'0'>=0 and s[i]-'0'<=9){
			a[s[i]-'0']++;
			
		}
	}
	for (int i=9;i>=0;i--){
		if (a[i]){
			for (int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
