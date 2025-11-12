#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
string s;
int num[1000005]={};
int k=0;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[k]=s[i]-'0';
			k++;
		}
	}
	sort(num,num+k,cmp);
	for(int i=0;i<k;i++){
		cout<<num[i];
	}
	return 0;
}
