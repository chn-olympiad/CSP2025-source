//SN-J00794 王美萱 西安市曲江第一学校 
#include<bits/stdc++.h>
#include<set>
using namespace std;
const int N=1e6+10;
string s;
int a[N],b[N];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	set <string> A;
	cin>>s;	
	if(s.length()==1){
		cout<<s;
		return 0;
	}
	if(s.length()==2){
		cout<<s;
		return 0;
	} 
	for(int i=1;i<=s.length();i++){
		if(b[i]-'A'>=32){
			for(int j=1;j;j++){
				a[j]=b[i];
			}
		}
	}
	sort(a+1,a+1+s.size(),cmp);
	for(int k=1;k<=s.size();k++){
		cout<<a[k];
	}
	return 0;
} 
