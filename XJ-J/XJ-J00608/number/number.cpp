#include<bits/stdc++.h>                              
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string a;
	cin>>a;
	int cnt[a.size()]={0},j=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			cnt[j]=a[i]-'0';
			j++;
		}
		else if(a[i]<='0' || a[i]>='9'){
			continue;
		}
	}
	sort(cnt,cnt+j,cmp);
	for(int i=0;i<j;i++){
		cout<<cnt[i];
	}
	return 0;
}

