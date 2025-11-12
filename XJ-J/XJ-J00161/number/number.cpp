#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int a[maxn];
bool cmp(long long aa,long long bb){
	if(aa>bb){
		return aa;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long ans;
	long long len=s.length();
	sort(a+1,a+1+len);
	for(long long i=1;i<len;i++){
		for(long long j=1;j<len;j++){
			if( len<='9'||len>='1' ){
				len=len+a[i]+a[j];
			ans=a[len];
			}
		}
	}
	cout<<ans;
		return 0;
}

