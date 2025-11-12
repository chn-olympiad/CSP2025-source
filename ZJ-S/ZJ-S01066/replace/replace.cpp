#include<bits/stdc++.h>
using namespace std;
struct kun{
	string a1,a2;
}dic[200005];
int n,q,l,x,ans;
string x1,x2="hello";
bool flag=0;
int fi(int szx,int pyh){
	bool flag=0;
	for(int i=szx;i<l;i++){
		if(dic[pyh].a1[i-szx]==x1[i]){
			flag=0;
			for(int j=i+1;j<=i+dic[pyh].a1.size();j++){
				if(dic[pyh].a1[j-i]!=x1[j])flag=1;
			}
			if(!flag)return i;
		}
		return -1;
	}
	return -1;
}
bool pd(int szx){
	for(int i=0;i<szx;i++){
		if(x1[i]!=x2[i])return 1;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		cin>>dic[i].a1>>dic[i].a2;
	}
	while(q--){
		ans=0;
		cin>>x1>>x2;
		l=x1.size();
		for(int i=1;i<=n;i++){
//			cout<<1;
			x=x1.find(dic[i].a1);
			if(x==-1)continue;
			if(pd(x))continue;
//			cout<<i;
			for(int j=x;j!=-1;j=fi(j+1,i)){
//				cout<<1;
				flag=0;
//				cout<<j<<' ';
				for(int k=x;k<x+dic[i].a1.size();k++){
					if(dic[i].a2[k-j]!=x2[k]){
						flag=1;
						break;
					}
				}
				for(int k=x+dic[i].a1.size();k<l;k++){
					if(x1[k]!=x2[k]){
						flag=1;
						break;
					}
				}
				if(!flag){
					ans++;
//					cout<<i<<' ';
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
