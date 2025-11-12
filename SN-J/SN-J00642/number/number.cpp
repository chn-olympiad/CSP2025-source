#include<bits/stdc++.h>
using namespace std;
string ans,s1;
char maxs=INT_MIN;
int n;
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=0;
	int d=0;
	for(int i=0; i<=s.size()-1; i++) {
		if(s[i]>='0'&&s[i]<='9') {
			t++;
			n++;
			s1[t]=s[i];
			//cout<<s1[t];
		}
		if(s[i]=='0'){
			d++;
		}
	}
	//cout<<endl;
	int sum=0;
	for(int i=1; i<=n; i++) {
		sum=0;
		maxs='0';
		for(int j=0; j<=n-1; j++) {
			if(s1[j]>='0'&&s[j]<='9') {
				//cout<<"j="<<j<<" ×Ö·û="<<maxs<<endl;
				if(s1[j]>maxs) {
					maxs=s1[j];
					sum=j;
				}
			}
		}
		//cout<<"½áÊø"<<endl; 
		ans[i]=maxs;
		s1[sum]='-1';
	}
	//cout<<n<<" "<<d;
	for(int i=n-1;i<=n+d-1;i++){
		ans[i]='0';
	}
	for(int i=1; i<=n; i++) {
		cout<<ans[i];
	}
	return 0;
}
