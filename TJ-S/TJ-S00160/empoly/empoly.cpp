#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int N=510;
int n,m;
string s;
bool flag=true;
int ch=0;
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			flag=false;
		}else{
			ch++;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			cnt++;
		}
	}
	long long ans=0;
	/*if(flag){
		sort(a+1,a+1+n);
		for(int i=cnt;i<=n;i++){
			if(a[i]<=cnt){
				cnt--;
			}
		}
		ans=1;
		for(int i=1;i<=cnt;i++){
			ans=(ans*i)%Mod;
		}
	}else if(ch<=18){
		if(m<=ch){
			
		}
	}*/
	cout<<ans;
	return 0; 
}
