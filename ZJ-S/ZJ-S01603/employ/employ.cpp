#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int m,n,cn,ans;
bool flag[100001];
bool s[100001];
int c[100001];
void search(int k,int d){
	if(d==n){
		if(k==m)ans++;
		return;
	}
	for(int i=0;i<n;i++)
		if(!s[i]){
			s[i]=1;
			if(!flag[i]||cn>=c[i]){
				cn++;search(k,d+1);cn--;
			}else{
				search(k+1,d+1);
			}
		}
}
int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;char t;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t=='1')flag[i]=1;
	}
	for(int i=0;i<n;i++)cin>>c[i];
	search(0,0);
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);return 0;
}