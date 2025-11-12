//SN-J00627 ÑîãëÌÎ ³¤Çì°ËÖĞ 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int s[100005]; 
	int cnt=0;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0'){
			s[cnt]=a[i]-'0';
			cnt++;
		}
	}
	sort(s,s+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<s[i];
	}

	return 0;
}
