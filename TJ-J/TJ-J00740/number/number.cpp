#include<bits/stdc++.h>
using namespace std;
string q;
int a[1000005],id,ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>q;
	for(int i=0;i<q.size();i++){
		if(q[i]>='0'&&q[i]<='9'){
			//cout<<"awa";
			a[id++]=q[i]-'0';
		}
	}
	//cout<<11223344<<endl;
	sort(a,a+id);
	//cout<<id;
	for(int i=id-1;i>=0;i--){
		printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
