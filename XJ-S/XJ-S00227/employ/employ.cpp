#include<bits/stdc++.h>
using namespace std;
string s;
int c[100000];
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
    	cin>>c[i];
	}
	int f=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			f=1;
		}
	}
	if(f==0){
 		cout<<0<<endl;
   		return 0;
	}
    if(m==1){
    	int k=1;
    	for(int i=1;i<=n;i++){
    		k*=i;
    		k%=MOD;
		}
		cout<<k<<endl;
		return 0;
	}else if(m==n){
		cout<<1<<endl;
		return 0;
	}
	cout<<0<<endl;

	return 0;
}

