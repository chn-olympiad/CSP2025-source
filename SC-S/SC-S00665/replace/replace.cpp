#include<iostream>
using namespace std;
string s;
string ss[300010][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>ss[i][1]>>ss[i][2];
	while(m--){
		string a,b;
		cin>>a>>b;
		long long cnt=0;
		for(long long i=1;i<=n;i++){
			long long k=a.find(ss[i][1]);
			long long k1=b.find(ss[i][2]);
			if(k==-1||k1==-1)continue;
				string tt=a;
				for(long long j=0;j<ss[i][1].size();j++)
					tt[j+k]=ss[i][2][j];
				if(tt==b)cnt++;
			}
			cout<<cnt<<endl;
		}
	return 0;
}