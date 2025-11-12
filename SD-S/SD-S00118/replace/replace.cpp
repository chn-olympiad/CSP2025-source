#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,q;
pair<string,string> a[5000010];
string l1,l2;
int maxLen;
long long cnt=0;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	while(q--){
		cnt=0;
		cin>>l1>>l2;
		int id1,id2;
		for(int i=0;i<=l1.size();i++){
			if(l1[i]!=l2[i]){
				id1=i;
				break;
			}
		}
		for(int i=l1.size()-1;i>=0;i--){
			if(l1[i]!=l2[i]){
				id2=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
		//	cout<<a[i].first<<endl;
			for(int j=max(id2-(int)a[i].first.size()+1,0);j+a[i].first.size()-1<l1.size()&&j<=id1;j++){
				
				if(a[i].first==l1.substr(j,a[i].first.size())&&a[i].second==l2.substr(j,a[i].second.size())){
					cnt++;
				}
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
} 
/*3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
