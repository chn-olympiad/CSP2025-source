#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;
string s;
int a[N],sum,j;
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	if(len==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<=len-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
			sum++;
		}else{
			continue;
		}
	}	
	sort(a,a+sum);
	for(int i=sum-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
