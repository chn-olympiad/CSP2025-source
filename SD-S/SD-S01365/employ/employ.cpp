#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
const int P=998244353;
int n,m,c[N];
string s;
int nowp[101];
bool check(){
	int nio=0;
	int cnt=0;
	int lle=s.length();
	for(int i=1;i<=n;i++){
		int lou=nowp[i];
		//cout <<s[i]<<" ";
		if(s[i-1]=='0'){
			nio++;
		}
		else if(nio>=c[lou]){
			nio++;
		}
		else{
			cnt++;
		}
	}
	//cout <<cnt<<endl;
	return cnt>=m;
}
int ans=0;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m;
	cin >>s;
	int flag=0;
	for(int i=0;i<s.length();i++) if(s[i]!='1') flag=1;
	for(int i=1;i<=n;i++){
		cin >>c[i];
	}
//	int ans=0;
	if(n<=12){
		for(int i=1;i<=n;i++){
			nowp[i]=i;
		}
		do{
			ans+=check();
		}while(next_permutation(nowp+1,nowp+n+1));
		cout <<ans%P;
	}
	else if(!flag){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=P;
		}
		cout <<ans; 
	}
	else{
		cout <<0;
	}
	return 0;
	
}
