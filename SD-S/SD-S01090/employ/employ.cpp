#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
string sc;
int c[1000];
int y[1005][1005];
bool flag=1;
int p[1005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		sc=sc+(char)('A'+i-1);
		if(s[i-1]!='1'){
			flag=0;
		}
		cin>>c[i];
	}
	bool flag=1;
	int k=1;
	string t=sc; 
	while(next_permutation(sc.begin(),sc.end())){
		bool fl[1005]={0};
		int cnt=0;
		if(flag==0&&sc==t){
			break;
		}
		if(flag==1){
			sc=t;
			flag=0;
		}
		for(int i=0;i<sc.size();i++){
			p[i+1]=sc[i]-'A'+1;
		}
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				fl[i]=1;
				for(int j=i+1;j<=n;j++){
					y[k][j]++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(y[k][i]>=c[p[i]]){
				fl[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(fl[i]==0)
				cnt++;
		}
		if(cnt>=m){
			ans++;
		}
		k++;
	}
	cout<<ans<<endl;
	return 0;
}
