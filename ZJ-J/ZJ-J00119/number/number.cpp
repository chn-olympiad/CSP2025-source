#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N=1000001;
int S[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int Cnt=0,Len;
	string Str;
	cin>>Str;Len=Str.length();
	for(int i=0;i<Len;i++)
		if('0'<=Str[i]&&Str[i]<='9')
			S[++Cnt]=Str[i];
	sort(S+1,S+1+Cnt);
	if(S[Cnt]=='0'){
		cout<<0;
		return 0;
	}
	for(int i=Cnt;i>=1;i--)
		cout<<(char)S[i];
	return 0;
}
