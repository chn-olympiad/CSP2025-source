#include<bits/stdc++.h>
using namespace std;
const int inff=1e6;
string words;
char st1[3000][3000],at2[3000][3000];
int n,q,ind[inff];
int main(){
	freopen("replace.in","r","std.in");
	freopen("replace.out","w","std.out");
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>words;
		ind[i]=words.size()/2;
//		cout<<ind[i]<<endl;
		for(int j=1;j<=ind[i];j++){
			st1[i][j]=words[j];
		}
		for(int j=1;j<=ind[i];j++){
			st2[i][j+ind[i]+1]=words[j+ind[i]+1];
		}
	}
	return 0;
}

