#include<bits/stdc++.h>
using namespace std;
char a[(10*10*10*10*10*10+1)]; 
bool cmp(int a,int b){
	if(a<b)
		return 0;
	else if(a>b)
		return 1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long sum=0;
	for(long long i=0;i<=s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[sum]=s[i];
			sum++;
		}
	}
	sort(a,a+sum,cmp);
	for(long long i=0;i<=sum;i++){
		cout<<a[i];
	}
	return 0;
} 
