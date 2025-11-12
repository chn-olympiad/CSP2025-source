#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	string a1,a2;
}a[1005000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int b1,b2;
		for(int i=1;i<=s1.length();i++){
			if(s1[i]=='b'){
				b1=i;
				break;
			}
		}
		for(int i=1;i<=s2.length();i++){
			if(s2[i]=='b'){
				b2=i;
				break;
			}
		}
		if(b1>b2)swap(b1,b2);
		int len=b2-b1;
		int ans=0;
		for(int j=1;j<=n;j++){
			if(a[j].a1.length()>=len){
				int shifou=0;
				int qa=0,ha=0;
				for(int k=0;k<a[j].a1.length();k++){
					if(!shifou)qa++;
					else ha++;
					if(a[j].a1[k]=='b'&&a[j].a2[k]=='b'){
						shifou=1;
					}else break;
				}
			}
		}
		cout<<0<<endl;
	}
	return 0;
}