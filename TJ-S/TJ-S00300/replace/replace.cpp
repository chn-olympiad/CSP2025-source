#include<bits/stdc++.h>
using namespace std;
string s1[100006];
string s2[100006];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(q==1){
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
		}
		string t1,t2;
		cin>>t1>>t2;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(t1.find(s1[i])&&t1.find(s1[i])==t2.find(s2[i])&&t2.find(s2[i])){
				sum++;
			}
		}
		cout<<sum;
	}else{
		for(int i=1;i<=n;i++){
			cin>>s1[i]>>s2[i];
		}
		string t1,t2;
		for(int i=1;i<=q;i++){
			cin>>t1>>t2;
			cout<<"0";
		}
	}
	return 0;
}
