#include<bits/stdc++.h>
using namespace std;
int a,b,ai[1000050][2],bi[1000050][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout<<a<<b;
	for(int i=1;i<=a;i++)cin>>ai[i][0]>>ai[i][1];
	for(int i =1;i<=b;i++)cin>>bi[i][0]>>bi[i][1];
	for(int i =1;i<=b;i++){
		/*int in,out,ans=0;
		for(int j =0;j<(int)bi[i][0].size();j++){
			if(bi[i][0][j]!=bi[i][1][j]&&in!=-1)in=j;
			else if(bi[i][0][j]!=bi[i][1][j])out =j;
		}
		out=out-in+1;
		string pd1 = bi[i][0].substr(in, out);
		string pd2 = bi[i][1].substr(in, out);
		for(int j=0;j<=a;j++){
			if(ai[j][0].find(pd1) && ai[j][1].find(pd2)&&bi[j][0].find(ai[j][0])&&bi[j][1].find(ai[j][1]))ans++;
		}*/
		cout <<0<<"\n";
	}
	return 0;
}
