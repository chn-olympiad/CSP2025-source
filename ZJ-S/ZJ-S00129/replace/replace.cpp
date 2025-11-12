#include<iostream>
using namespace std;
const int N=200001;
string S[N][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>S[i][0]>>S[i][1];
	for(int i=1;i<=q;i++){
		string Str1,Str2;
		int Cnt=0;
		cin>>Str1>>Str2;
		for(int j=1;j<=n;j++){
			int Ptr=Str1.find(S[j][0]);
			if(Ptr==string::npos)continue;
			string t=Str1;
			for(int k=0;k<S[j][0].length();k++)
				t[Ptr+k]=S[j][1][k];
			if(t==Str2)Cnt++;
		}
		cout<<Cnt<<endl;
	}
	return 0;
}
