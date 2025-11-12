#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=2e5+10;
int n,q;
string t1,t2;
int ans;
string s1[maxn],s2[maxn];
int dex[maxn];
int dexnow;
int len1,len2;
int pos1=0,pos2=0;
int check1(string a,string b){	
	pos1=0,pos2=0;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]=='b')pos1=i;
		if(b[i]=='b')pos2=i;
	}
	return pos2-pos1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >>q;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
		dex[i]=check1(s1[i],s2[i]);
//		cout << pos1 << " " << pos2 << endl;
//		cout << dex[i] << endl;
	}
	while(q--){
		ans=0;
		cin >> t1 >> t2;
		len1=t1.size();len2=t2.size();
		if(len1!=len2){
			cout << "0" << endl;
			continue;
		}
//		for(int i=1;i<=n;i++){
//			if(s1[i]==t1&&s2[i]==t2)ans++;
//		}
		dexnow=check1(t1,t2);
		for(int i=1;i<=n;i++){
//			cout << dexnow << " " << dex[i] << endl;
			if(dexnow==dex[i]){
				ans++;
			}
		}
		cout << ans << endl;
	}
	
	
	return 0;
}
/*
2 1
aab aba 
baa aba  
aabaa abaaa 

3 1
aab aba 
baa aba  
abaaaaaaaaa aaaaaaaaaba
baaaaaaaa aaaaaaaab
*/
