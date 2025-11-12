#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s,n=" ";
int ans[1000006];
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	int siz = (int)s.size();
	for(int i=0;i<siz;i++)
		if(s[i]>='0'&&s[i]<='9'){
			n+=s[i];
			//cout << n << " ";
		} 
		//cout<<"\n";
	int siz1 = (int)n.size()-1;
	for(int i=1;i<=siz1;i++){
		ans[i]=(int)n[i]-'0';
		//cout << ans[i] << " ";
	}
	//cout << "\n";
	sort(ans+1,ans+1+siz1,cmp);
	for(int i=1;i<=siz1;i++) cout << ans[i];
	return 0;
}

