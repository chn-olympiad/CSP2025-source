#include<bits/stdc++.h>
using namespace std;

int a[1000010],l=1;
string s;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	memset(a,0,sizeof(a));
	cin>>s;
	int n=s.size(),t;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t=s[i]-'0';
			a[l]=t;
			l++;
		}
	}
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=l;i++)cout<<a[i];
}

