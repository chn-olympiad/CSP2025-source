#include<bits/stdc++.h>
using namespace std;
int a,s;
string s1[200005],s2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>s;
	for(int z=1; z<=a; z++){
		cin>>s1[z]>>s2[z];
	}
	for(int z=1; z<=s; z++){
		string de,ds;
		cin>>de>>ds;
		int h=0;
		for(int x=1; x<=a; x++){
			if(de.find(s1[x])==ds.find(s2[x])){
				int u=de.find(s1[x]);
				for(int c=u; c<u+s1[x].size(); c++){
					de[c]=s2[x][c-u];
				}
				//cout<<"                    "<<de<<endl;
				if(de==ds)h++;
				for(int c=u; c<u+s1[x].size(); c++){
					de[c]=s1[x][c-u];
				}
			}
		}
		cout<<h<<endl;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/
