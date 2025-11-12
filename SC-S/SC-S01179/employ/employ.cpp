#include <bits/stdc++.h>
using namespace std;

#define mod 998244353

int n,m;
int pat[550];
int jc[550];
string har;

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	cin>>har;
	//cout<<har<<" debug"<<endl;
	int cntz=0;
	for(int i=1;i<=n;i++){
		cin>>pat[i];
		if(pat[i]==0){
			cntz++;
		}
	}
	//cout<<cntz<<" debug"<<endl;
	
	if(m==1){
		//cout<<har[0]<<" debug"<<endl;
		if(har[0]=='1'){
			cout<<n-cntz;
			return 0;
		}
		else if(har[0]=='0'){
			int st;
			for(int i=0;i<=har.size();i++){
				if(har[i]=='1'){
					st=i+1;
					break;
				}
			}
			//cout<<st<<" debug"<<endl;
			int cntxy;
			for(int i=1;i<=n;i++){
				if(pat[i]<st){
					cntxy++;
				}
			}
			//cout<<cntxy<<" debug"<<endl;
			cout<<n-cntxy;
			return 0;
		}
	}
	
	return 0;
	
}

/*
5 1
00100
0 2 3 0 0
*/
 
/*
3 1
101
1 1 2
*/