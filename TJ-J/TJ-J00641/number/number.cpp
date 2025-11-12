#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long sum;
string s;
	bool flag=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	scanf("%s",&s);
	cin>>s;
	for(int i=0;i<s.size();i++){
    if(s[i]>='1'&&s[i]<='9'||s[i]=='0'){
        char c=s[i];
        a[sum]=c-48;
			sum++;
    }
    }
	sort(a,a+sum);
	for(int i=sum-1;i>=0;i--){
	printf("%d",a[i]);
}
    
    return 0;
}

