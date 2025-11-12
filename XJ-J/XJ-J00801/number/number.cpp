#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[10001]={' '};
	vector<int>c;
	cin>>a;
	for(int i=0;i<=10000;i++){
		if(a[i]=='a'||a[i]=='b'||a[i]=='c'||a[i]=='d'||a[i]=='e'||a[i]=='f'||a[i]=='g'||a[i]=='h'||a[i]=='i'||a[i]=='j'||a[i]=='k'||a[i]=='l'||a[i]=='m'||a[i]=='n'||a[i]=='o'||a[i]=='p'||a[i]=='q'||a[i]=='r'||a[i]=='s'||a[i]=='t'||a[i]=='u'||a[i]=='v'||a[i]=='w'||a[i]=='x'||a[i]=='y'||a[i]=='z'||a[i]==' ')continue;
		else c.push_back(int(a[i])-48);
	}
	for(int hh=9;hh>=0;hh--){
		for(int j=0;j<=c.size()-1;j++){
			if(c[j]==hh)cout<<c[j];
		}
	}
	return 0; 
}
