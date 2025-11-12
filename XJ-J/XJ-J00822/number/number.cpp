#include<bits/stdc++.h>

using namespace std;

const int N=1e6+5;
string s;
int a[N];

bool cmp(int p,int q){
	return p>q;	
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int tot=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++tot]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++){
		cout<<a[i];
	}
	return 0;
}
