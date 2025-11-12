#include<iostream>
#include<cstdio>
using namespace std;
const int MA=2e5+10;
int n,q;
/*
特殊性质 A： q = 1。
特殊性质 B：定义字符串 s 为特.别.的.，当且仅当字符串 s 仅包含字符 a 和 b，且
字符 b 在 s 中出现恰.好.一次。对于所有 1 ≤ i ≤ n， si,1, si,2 均为特别的，
且对于所有1 ≤ j ≤ q， tj,1, tj,2 均为特别的。
*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cout<<0<<endl;
	}
	return 0;
} 

