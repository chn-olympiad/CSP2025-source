//吴启豪 - SN-J00188 - 西安滨河学校 
#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[40],num;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int ss=s[i]-'0';
			a[ss]++;
		//	printf("%d %d\n",ss,a[ss]);
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			printf("%d",i);
			a[i]--;
		}
		
	}
	return 0;
}
