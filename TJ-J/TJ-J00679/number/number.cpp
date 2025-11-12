#include<bits/stdc++.h>
using namespace std;
string s,p;
long long cnt,a[100009],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		s[i]-='0';
		if(s[i]>=0&&s[i]<=9){
			a[i]=s[i];
			cnt+=1;
		}
	}
	long long k=s.size();
	sort(a,a+k+1);
	for(int i=k;i>0;i--){
		if(a[i]!=0){
			ans+=a[i]*pow(10,cnt);
		}if(cnt==0&&a[i]!=0){
			ans+=a[i];
		}
		cnt--;
	}
	cout<<ans/10;
	return 0;
}
