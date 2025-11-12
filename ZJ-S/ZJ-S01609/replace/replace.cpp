#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=2e5+10;
int n,q;
string s[N][2],v,u;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0];
		cin>>s[i][1];
	}
	while(q--){
		
		cin>>v>>u;
		int vl=v.size(),ul=u.size();
		v=" "+v;
//		if(vl!=ul){
			
//		}else{
			int cnt=0;
//			for(int l=1;l<=vl;l++){
				for(int i=1;i<=vl;i++){
//					int r=i+l-1;
					for(int j=1;j<=n;j++){
						int sjl=s[j][0].size();
//						cout<<sjl<<endl;
						if(vl-i+1>=sjl){
							
							string t=v.substr(i,sjl);
//							cout<<t<<endl;
							if(t==s[j][0]){
								
								string qq=v.substr(1,i-1);
								
								string hh=v.substr(i+sjl,vl-i-sjl+1);
								string zh=qq+s[j][1]+hh;
								if(zh==u)cnt++;
//								cout<<i<<":"<<j<<":(Q)"<<qq<<"(Z)"<<t<<"(H)"<<hh<<endl<<zh<<" "<<u<<endl;
							}
						}	
					}
				}
//			}
			cout<<cnt<<endl;
//		}
		
	}
	return 0;
}

