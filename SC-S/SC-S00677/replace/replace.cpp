#include<bits/stdc++.h>
using namespace std;

struct node{
	string a;
	string b;
};
node s[200005];

bool cmp(node temp,int a,int b){
	int i=0;
	for(;i<a;i++){
		if(temp.a[i]!=temp.b[i])return 0;
	}
	for(;i<s[b].a.size()+a;i++){
		if(temp.a[i]!=s[b].a[i-a])return 0;
		if(temp.b[i]!=s[b].b[i-a])return 0;
	}
	for(;i<temp.a.size();i++){
		if(temp.a[i]!=temp.b[i])return 0;
	}
	return 1;
}

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].b;
		
	}
	for(int i=0;i<q;i++){
		node temp;
		cin>>temp.a>>temp.b;
		long long ans=0;
		
		for(int j=0;j<n;j++){
			if(temp.a.length()>=s[j].a.length())
			for(int l=0;l<=(temp.a.length()-s[j].a.length());l++){
				if(cmp(temp,l,j)){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<endl;
		
	}
	return 0;
}