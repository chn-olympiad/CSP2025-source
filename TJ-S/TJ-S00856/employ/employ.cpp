#include<bits/stdc++.h>
using namespace std;
const long long N=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string b;
	long long a[510]={},s[510]={};
	cin>>b;
	int c;
	for(int i=0;i<m;i++){
		cin>>c;
		a[c+1]++;
	}
	s[0]=a[0];
	for(int i=1;i<510;i++){
		s[i]=s[i-1]+a[i];
	}
	long long ans=1;
	int ji=0;
	for(int i=0;i<b.length();i++){
		if(b[i]=='1'){
			ji++;
			long long vl;
			if(s[i-1]<i){
				vl=s[509]-i;
			}else{
				vl=s[509]-s[i-1];
			}
			if(vl!=0){
				ans=((ans%N)*(vl%N))%N;
			}
		}
	}
	if(ji<m){
		cout<<0;
	}else{
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

