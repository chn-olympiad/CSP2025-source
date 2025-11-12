//准考证号:SN-J00412
//姓名:张轩祎
//学校:西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
string n;
int a[1000000];
int b[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	int lenn=n.size(),cnt=0;
	for(int i=0;i<lenn;i++){
		if(n[i]<='9'&&n[i]>='0'){
			a[i]=n[i]-'0';
			cnt++;
		}
	}
	sort(a,a+lenn);
	for(int i=lenn-1;i>=lenn-cnt;i--){
		cout<<a[i];
	}
	return 0;
}
