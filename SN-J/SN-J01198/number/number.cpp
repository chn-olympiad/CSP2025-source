//SN-J01198 鱼馨月 西安市曲江第一学校
#include<bits/stdc++.h> 
#define ll long long
using namespace std;
const int N=1e6+10;
string s;
char b[N];
int a[N],lena=0;
int cmp(int x,int y){
	return s[a[x]]<s[a[y]];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<sizeof(s);i++){
		int k=1;
		if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' || s[i]=='0' ){
			a[k]=i;
			k++,lena++;
		}
		else continue;
	}
	sort(a+1,a+lena+1,cmp);
	for(int i=lena;i>=1;i--){
		cout<<s[a[i]];
	}
	return 0;
}
//number 8 
