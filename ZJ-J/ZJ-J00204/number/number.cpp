#include <bits/stdc++.h>
using namespace std;
#define fr1(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define fr2(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
const int maxn=1e6+10;
long long sum[maxn]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	fr1(i,0,s.length()-1)if(s[i]>='0'&&s[i]<='9')sum[s[i]-'0']++;
	fr2(i,9,0)fr1(j,1,sum[i])cout<<i;
	cout<<endl;
	return 0;
}
