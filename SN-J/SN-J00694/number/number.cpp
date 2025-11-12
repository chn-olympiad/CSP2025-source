#include <bits/stdc++.h>
using namespace std;
string s;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    int k=0;
    for(int i=0;i<l;i++){
    	for(int j='0';j<='9';j++){
    		if(s[i]==j){
    			b[k++]=int(j-48);
			}
		}
	}
	sort(b,b+k+1);
	for(int i=k;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}
