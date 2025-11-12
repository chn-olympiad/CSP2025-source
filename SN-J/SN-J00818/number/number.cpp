//SN-J00818  甘智中  西安市雁塔区第一学校 
#include<bits/stdc++.h>
using namespace std;
long long a[1000005],k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0' && s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}       
	sort(a+1,a+k+1) ;
	for(int i=k;i>=1;i--){
		cout<<a[i];
	}     
	return 0;
}
