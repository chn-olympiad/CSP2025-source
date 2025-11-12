#include<bits/stdc++.h>
/*fjx 20120225 rp++*/
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAX=1e7+5;
const ll N=0;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	int l=s.size();
	int ii=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++ii]=s[i]-'0';
		}
	}
	sort(a+1,a+1+ii);
	for(int i=ii;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
