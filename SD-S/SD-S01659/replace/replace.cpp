#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=0,k=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') k=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) f=f*10+ch-'0';
	return f*k;
}
int q,n,sum=0,a[5000001][2]={0};
string s;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='b'){
				sum=j;
				break;
			}
			if(s[j]!='a'){
				break;
			}
		}
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='b'){
				if(sum<j){
					a[j-sum][0]++;
				}
				else{
					a[sum-j][1]++;
				}
				break;
			}
			if(s[j]!='a'){
				break;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='b'){
				sum=j;
				break;
			}
			if(s[j]!='a'){
				break;
			}
		}
		cin>>s;
		if(s[0]!='a'&&s[0]!='b'){
			cout<<0;
			continue;
		}
		if(s[1]!='a'&&s[1]!='b'){
			cout<<0;
			continue;
		}
		for(int j=0;j<s.size();j++){
			if(s[j]=='b'){
				if(sum<j){
					cout<<a[j-sum][0]<<endl;
				}
				else{
					cout<<a[sum-j][1]<<endl;
				}
				break;
			}
			if(s[j]!='a'){
				break;
			}
		}
	}
	return 0;
} 
