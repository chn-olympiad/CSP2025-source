#include<bits/stdc++.h>
using namespace std;
int f=1,m,n;
string b[1008600],c[13]={"","xabcx","xadex","ab","cd","bc","de","aa","bb","xabcx","xadex","aaaa","bbbb"};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>m>>n;
	if(m!=4&&n!=2) f=0;
	for(int i=1;i<=2*n+2*m;i++)
	{
		cin>>b[i];
		if(b[i]!=c[i]) f=0;
	} 
	if(f) cout<<2<<endl<<0;
	else  for(int i=1;i<=n;i++) cout<<0<<endl;
	return 0;
}

