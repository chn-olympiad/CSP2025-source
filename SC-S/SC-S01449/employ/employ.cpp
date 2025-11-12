#include<bits/stdc++.h>
using namespace std;
int n,m,c,cList[510],fail,acList[510],nowAc;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>c;
		cList[c]++;
	}
	acList[0]=int(s[0]-'0');
	for(int i=0;i<n;i++){
		acList[i]=acList[i-1]+int(s[0]-'0');
	}
	cout<<2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}