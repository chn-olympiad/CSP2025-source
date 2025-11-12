#include<bits/stdc++.h>
using namespace std;
string s;
string sum;
long long cnt[15],t,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size(); 
	for(long long i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t=s[i]-'0';												
			cnt[t]++;
		}
	}
	for(long long i=9;i>=1;i--){
		if(cnt[i]!=0){
			for(long long j=1;j<=cnt[i];j++){
				sum+=(i+'0');
			}
		}
	}
	for(long long i=1;i<=cnt[0];i++){
		sum+='0';	
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
