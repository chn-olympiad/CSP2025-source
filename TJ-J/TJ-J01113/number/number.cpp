#include<bits/stdc++.h>
using namespace std;
string str;
long long vis[101];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	for(long long i=0;i<str.length();i++){
		int num=str[i]-'0';
		vis[num]++;
	}
	//for(int i=0;i<=9;++i) cout<<vis[i];
	if(vis[1]==0&&vis[2]==0&&vis[3]==0&&vis[4]==0&&vis[5]==0&&vis[6]==0&&vis[7]==0&&vis[8]==0&&vis[9]==0){
		printf("%d",0);
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=vis[i];++j) printf("%d",i);
	}
	return 0;
}
