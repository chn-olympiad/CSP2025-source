#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s1;
	cin>>s1;
	int cnt=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			a[++cnt]=(s1[i]-48);
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
