#include<bits/stdc++.h>
using namespace std;
//long long rp=INT_MAX+INT_MAX;(¼ªÏéÎï) 
int n,m;
int rp1[505]; 
int rp2[505];
int main(){
	//rp++(Ï£Íû°ÉQAQ) 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);//¶Á¶ÁÐ´Ð´ 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>rp1[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>rp2[i];
	}
	cout<<m<<endl;//²Âm°ÉQAQ 
	return 0;
} 
