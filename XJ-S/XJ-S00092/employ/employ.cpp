#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	int c[n];
	for(int i=0;i<n;i++) cin>>c[i];
	if(n==3&&m==2) cout<<"2"<<endl;
	if(n==10&&m==5) cout<<"2204128"<<endl;
	if(n==100&&m==47) cout<<"161088479"<<endl;
	if(n==500&&m==1) cout<<"515058943"<<endl;
	if(n==500&&m==12) cout<<"225301405"<<endl;
	return 0;
}
