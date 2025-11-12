#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
int n,m,c[N],way,my;
string a;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c,c+n+1);
	int flag=0;
	for(int i=0;i<n;i++){
		if(a[i]!='1'){
			flag=1;
		}else{
			my++;
		}
	}
	if(m==n){
		if(flag==0){
			way=1;
			for(int i=1;i<=n;i++){
				way*=i;
			}
			way=way%mod;
		}else{
			way=0;
		}
	}else if(m==1){
		int first=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='1'){
				first=i;
				break;
			}
		}
		int ge=0;
		for(int i=1;i<=n;i++){
			if(c[i]>=first){
				ge++;
			}
		}
		way=ge;
		for(int i=1;i<n;i++){
			way*=i;
		}
		way=way%mod;
	}else if(my>=m){
		int fg=0;
		
		for(int i=1;i<=n;i++){
			int q=n+1-i;
			if(a[i]=='0'){
				fg++;
				
			}
			for(int j=i;j<=n-i+1;j++){
				if(c[j]<fg){
					q--;
				}
			}
			if(way==0){
				way=1;
			}
			way*=q;
		}
		way=way%mod;
	}else{
		way=0;
	}
	cout<<way;
	return 0;
}