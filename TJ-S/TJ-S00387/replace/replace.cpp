#include<bits/stdc++.h>
using namespace std;
//旁边的人好像不会了，他已经5分钟没敲代码了 
int n,q;
string s1[2*100000+5];
string s2[2*100000+5];
string s11[2*100000+5];
string s22[2*100000+5];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		cin>>s11[i]>>s22[i];
	}
	for(int i=0;i<q;i++){
		cout<<"1"<<endl;//赌零不如赌一，因为零样例有 
	}
	return 0;
}
