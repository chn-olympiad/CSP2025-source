//谢翔宇 西安市曲江第一学校 SN-J00990  
#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+10;
string s;
int a[N];
bool cmp(int x_1,int y_1){
	return x_1>y_1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		a[i]=s[i]-'0';
	}
	sort(a,a+len+1,cmp);
	for(int i=0;i<len;i++){
		if(a[i]<10&&a[i]>=0){
			cout<<a[i];
		}
	}	
	
	return 0;
}
