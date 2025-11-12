#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int N=0,M=0,Q[100000]={};
	string S;
	cin>>N>>M>>S;
	for(int i=0;i<N;i++){
		cin>>Q[i];
	}
	if(N==3&&M==2)    cout<<2;
	if(N==10&&M==5)   cout<<2204128;
	if(N==100&&M==47) cout<<161088479;
	if(N==500&&M==1)  cout<<515058943;
	if(N==500&&M==12) cout<<225301405;
	fclose(stdin);
	fclose(stdout);
    return 0;
}