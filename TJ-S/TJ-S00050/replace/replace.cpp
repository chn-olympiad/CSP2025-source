#include<bits/stdc++.h>
using namespace std;
const int MX=3e5+29;
string a[MX],b[MX];
string c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	int z=0;
	for(int i=0;i<m;i++){
		cin>>c>>d;
		int z=0;
		for(int j=0;j<n;j++){
			string s=c;
			long long ll=s.find(a[j]);
			int l2=a[j].size();
//			cout<<ll<<" ";
			if(ll>=0){
				string cc=s.replace(ll,l2,b[j]);
//				cout<<cc<<" ";
				if(cc==d)z++;
			}
//			cout<<'\n';
		}
		cout<<z<<'\n';
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
