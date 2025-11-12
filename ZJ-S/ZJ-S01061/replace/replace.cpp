#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5+10;
i64 n,q;
struct SubStr{
	string StrBefore;
	string StrAfter;
}SubStrArr[N];
string SubIt(string S,i64 L,i64 R){
	string ans = "";
	for(int i=L;i<=R;i++){
		ans += S[i];
	}
	return ans;
}
bool PairIt(string S,i64 L,string PairString){
	for(int i=0;i<PairString.length();i++){
		if(S[L+i]!=PairString[i]) return false;
	}
	return true;
}
bool really(string A1,string B1,string A2,string B2,i64 pos){
	//cout<<endl;
	for(int i=0;i<pos;i++){
		//cout<<A1[i];
		if(A1[i] != B1[i]) return false;
	}
	for(int i=pos;i<pos+A2.length();i++){
		//cout<<B2[i-pos];
		if(B2[i-pos] != B1[i]) return false;
	}
	for(int i=pos+A2.length();i<A1.length();i++){
		//cout<<A1[i];
		if(A1[i] != B1[i]) return false;
	}
	return true;
}
int main(){
	freopen("replace.in ","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> SubStrArr[i].StrBefore >> SubStrArr[i].StrAfter;
	}
	while(q--){
		i64 ans = 0;
		string Before,After;
		cin >> Before >> After;
		i64 Len = Before.length();
		for(int i=1;i<=n;i++){
			i64 ReLen = SubStrArr[i].StrBefore.length();
			for(int j=0;j<=Len-ReLen;j++){
				if(PairIt(Before,j,SubStrArr[i].StrBefore)){
					if(really(Before,After,SubStrArr[i].StrBefore,SubStrArr[i].StrAfter,j))
					{
						ans += 1;
					}
				}
			}
		}
		cout << ans <<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}