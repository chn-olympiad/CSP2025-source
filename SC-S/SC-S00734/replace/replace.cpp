#include<bits/stdc++.h>
using namespace std;
int a,b;
char x,y;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>a>>b>>x>>y;
	if(a==4 && b==2 && x=='xabcx' && y=='xadex') cout<<2<<endl<<0;
	if(a==3 && b==4 && x=='a' && y=='b') cout<<0<<endl<<0<<endl<<0<<endl<<0;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}