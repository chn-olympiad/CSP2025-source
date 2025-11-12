#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a=0,y=0,huan=0;
	string s;
	cin>>s;
	char b[s.size()+1];
	int shu[s.size()];
	for(int i=0;i<s.size();i++){
		if(s[i]>='1'&&s[i]<='9'){
			b[y]=s[i];
			y++;
		}
	}
	for(int i=0;i<y;i++){
		if(b[i]=='0')
			shu[i]=0;
		if(b[i]=='1')
			shu[i]=1;
		if(b[i]=='2')
			shu[i]=2;
		if(b[i]=='3')
			shu[i]=3;
		if(b[i]=='4')
			shu[i]=4;
		if(b[i]=='5')
			shu[i]=5;
		if(b[i]=='6')
			shu[i]=6;
		if(b[i]=='7')
			shu[i]=7;
		if(b[i]=='8')
			shu[i]=8;
		if(b[i]=='9')
			shu[i]=9;
	}
	for(int i=0;i<y;i++){
		for(int t=0;t<y;t++)
		if(shu[t]<shu[t+1]){
		huan=shu[t];
		shu[t]=shu[t+1];
		shu[t+1]=huan;
		}
	}
	for(int i=0;i<=y;i++){
		cout<<shu[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}