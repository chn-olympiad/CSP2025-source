#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,n,m;
string aaa,bbb;
struct node{
	string s1,s2;
};
node aa[200005];
string bb[1005];
//祭天初一(10)班全体（尤其是我周围那几个)十年阳寿，换我S组AK！ 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>aa[i].s1>>aa[i].s2;
	}
	for(int ii=1;ii<=b;ii++){
		cin>>aaa>>bbb;
		for(int i=0;i<aaa.size();i++){
			for(int j=i;j<a.size();j++){
				for(int k=i;k<=j;k++){
					bb[i]=bb[i]+aa[i].s2
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
