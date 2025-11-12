#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+5;
char a[N];
bool vis[N];
int idx=0,box[N],ans=-1e9;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	//×Ö·û´®²ð·Ö 
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			idx++;
			a[idx]=s[i];
		}
	}
//	for(int i=1;i<=idx;i++){
//		cout<<a[i]<<" ";
//	}
	sort(a+1,a+1+idx,cmp);
	for(int i=1;i<=idx;i++){
		cout<<a[i];
	}
	return 0;
}

