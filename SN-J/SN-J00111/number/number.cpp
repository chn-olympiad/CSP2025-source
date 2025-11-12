#include <bits/stdc++.h>
using namespace std;
string s;
int A[10000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int num=1;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			A[num]=s[i]-'0';
			num++;
		}
	}
	for(int i=1;i<num;i++){
		int b=-2;
		int u;
		for(int j=1;j<num;j++){
			if(A[j]>b){
				b=A[j];
				u=j;
			}
		}
		A[u]=-3;
		cout<<b;
	}
	return 0;
}
