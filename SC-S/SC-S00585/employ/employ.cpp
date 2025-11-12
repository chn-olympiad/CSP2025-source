#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
struct node{
	int pa;
	int Id;
} a[510];
int s[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	int flag=0;
	cin>>n>>m;
	string s;
	cin>>s;
	int len2=s.size();
	for(int i=0;i<len2;i++){
		if(s[i]==0) flag=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].pa;
		a[i].Id=i;
		if(a[i].pa==0) flag=1;
	}
	
	if(m==n&&flag==1){
		cout<<0;
		return 0;
	}
	
	if(m==n&&flag==0){
		int mul=1;
		for(int i=m;i>=1;i--){
			mul*=i;
            mul%=mod;
		}
		cout<<mul;
		return 0;
	}
	
	string ss="";
	for(int i=1;i<=n;i++){
		ss+=(i+'0');
	}
	
	do{
		int cnt1=0,cnt2=0;
		int len=ss.size();
		for(int i=0;i<len;i++){
			int num=ss[i]-'0';
			if(cnt1>=a[num].pa){
				cnt1++;
				continue;
			}
			
			if(s[i]=='0') cnt1++;
			else cnt2++;
		}
		if(cnt2>=m){
			ans++;
			ans%=mod;
		}
	} while(next_permutation(begin(ss),end(ss)));
	cout<<ans;
}