#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
/*bool cmp(int a,int b){
	if(a>=b) return a;
	return b; 
}*/
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	//string shu="";
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++cnt]=s[i]-'0';
			//shu.push_back(s[i]);
			/*if(s[i]>=shu[0]){
				shu=s[i]+shu;
			}else shu.push_back(s[i]);*/
			
		}		
	}
	//cout<<shu;
	//for(int i=1;i<=cnt;i++) printf("%d",a[i]);
	sort(a+1,a+cnt+1);
	//cout<<endl;
	if(a[cnt]==0){
		cout<<0;
		return 0;
	}
	for(int i=cnt;i>=1;i--){
		printf("%d",a[i]);
	} 
	return 0;
}
