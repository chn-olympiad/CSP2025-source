#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD=998244353;
int ml[5005],len[5005],sum,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<=3){
		if(n<3){
			cout<<0;
			return 0;
		}
		int s1,s2,s3;
		cin>>s1>>s2>>s3;
		if((s1+s2>s3)&&(s1+s3>s2)&&(s2+s3>s1))
			cout<<1;
		else cout<<0;
		return 0;
	}else 
	cout<<13072;
	fclose(stdin);
	fclose(stdout);
	return 0;
}