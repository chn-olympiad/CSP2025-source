#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,c[505],num,p[505]={0,1,2,3,4,5,6,7,8,9,10};
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for (int i=1;i<=n;i++)
		cin>>c[i];
	if (n>10)
		return 0;
	do{
		int refused=0,acepted=0;
		for (int i=1;i<=n;i++){
			if (refused>=c[p[i]])
				refused++;
			else if (s[i-1]=='0')
				refused++;
			else
				acepted++;
		}if (acepted>=m)
			num=(num+1)%M;
	}while (next_permutation(p+1,p+n+1));
	cout<<num;
	return 0;
}
