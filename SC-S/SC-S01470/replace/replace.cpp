#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int hashh(string s){
	int ans=0;
	int len=s.length();
	for(int i=0;i<len;i++){
		ans+=(s[i]-'a')*(s[i]-'a')*(len-i);
		ans%=131;
	}
	return ans;
}
int a[N][2],cnt;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s11,s22;
	for(int i=0;i<n;i++){
		cin>>s11>>s22;
		a[i][0]=hashh(s11);
		a[i][1]=hashh(s22);
	}
	for(int i=0;i<q;i++){
		cnt=0;
		cin>>s11>>s22;
		int ans1=hashh(s11);
		int ans2=hashh(s22);
		for(int j=0;j<n;j++){
			if(abs(ans1-ans2)%abs(a[j][0]-a[j][1])==0){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}

	return 0;
}
