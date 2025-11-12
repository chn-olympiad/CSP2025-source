#include<bits/stdc++.h>
#define forUp(i,a,b) for(int i=(a);i<=(b);++i)
#define forUP(i,a,b) for(int i=(a);i<(b);++i)
constexpr int N=1e6+10;using namespace std;
string str;int tot,number[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;int n=str.length();
	forUP(i,0,n){
		char c=str[i];
		if('0'<=c&&c<='9')number[tot++]=c-'0';
	}
	sort(number,number+tot,greater<int>());
	forUP(i,0,tot)cout<<number[i];
	return 0;
}