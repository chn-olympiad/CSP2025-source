#include<bits/stdc++.h>
using namespace std;
int n,q;
char in[10000];
char a[1000][2010],b[1000][2010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		cin>>in;
		int cnt=0;
		int len=strlen(in);
		for(int i=1;i<=n;i++){
			int len2=strlen(a[i]);
			if(len2<=len){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
//rp++;
//rp++;
//rp++;
//rp++;
//rp++;
//rp++;
//rp++;
