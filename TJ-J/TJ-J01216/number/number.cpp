#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
long long a[1000005],cnt=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++; 
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
