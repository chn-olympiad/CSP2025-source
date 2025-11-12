#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,c[100005],per[100005],ans,m;
string s;
bool check(){
	int cnt=0,ch=0;
	for(int i=1;i<=n;i++){
		if(s[per[i]]=='0') cnt++;
		else if(cnt>=c[i]) cnt++;
		else ch++;
	}
	return ch>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) per[i]=i;
	do{
		if(check()){
			ans++;
		//	for(int i=1;i<=n;i++) cout<<per[i]<<' ';
		//	cout<<'\n';
		}
		//cout<<'*';
	}while(next_permutation(per+1,per+n+1));
	cout<<ans;
}
