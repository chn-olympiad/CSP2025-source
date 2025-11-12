#include<bits/stdc++.h> 
using namespace std;
string qq[2];
struct p{
	string sa,sb;

map<int,string>n1;
map<int,string>n2; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,q,j;
    cin>>n>>q>>j;
    for(int i=0;i<=n;i++){
    	cin>>n1[i];
    	cin>>n2[i];
		}
		int cnt=0;
		string a,b;
		for(int i=0;i<q;i++){
			cin>>qq[1]>>qq[2];
			for(int j=0;j<qq;size();j++){
				for(int k=0;k<j;k++){
					for(int l=j;l<k;l++){
						a+=qq[1][l];
						b+=qq[2][l];
					}
					a=" ";
					b=" ";
				}
			}
	    cout<<cnt;	
		cnt=0;
		} 
	return 0;
}
};
