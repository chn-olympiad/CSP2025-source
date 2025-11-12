//SN-J00345 张时墉 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int ans[1000005],k;
int cmp(int r1,int r2){
	return r1>r2;
}
int main(){
	freopen("number4.in","r",stdin);
	freopen("number4.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			k++;
			ans[k]=s[i]-'0';
			
		}
	}
	
	sort(ans+1,ans+k+1,cmp);
	for(int i=1;i<=k;i++){
		cout<<ans[i];
	}
	return 0;
} 
