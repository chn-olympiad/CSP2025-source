#include<bits/stdc++.h>
using namespace std;
map <string,string> m;
int n,q;
string s1,s2,t1,t2;
void solve (){
	cin>>t1>>t2;
	int sum=0;
	if (t1.size()!=t2.size()){
		cout<<"0\n";
		return ;
	}
	int len=t1.size();
	for (int i=0; i<len; i++){
		string y="";
		for (int j=i; j<len; j++){
			y+=t1[j];
			if (m[y]!=""){
				string x=t1.substr (0,i),z=t1.substr (j+1,len-j-1);
				if (x+m[y]+z==t2){
					sum++;
				}
			}
		}
	}
	cout<<sum<<"\n";
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	while (n--){
		cin>>s1>>s2;
		m[s1]=s2;
	}
	while (q--){
		solve ();
	}
	return 0;
}
