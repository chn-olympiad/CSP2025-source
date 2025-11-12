#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct myst{
	long long qian1=0,qian2=0,hou1=0,hou2=0,houcha=-1,qiancha=-1;
	string str1,str2;
}a[1000005],q; 
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].str1>>a[i].str2;
		bool flag=0;
		for(long long j=0;j<a[i].str1.size();j++){
			if(a[i].str1[j]=='b')flag=1;
			else if(flag==0)a[i].qian1++;
			else a[i].hou1++;
		}
		flag=0;
		for(long long j=0;j<a[i].str2.size();j++){
			if(a[i].str2[j]=='b')flag=1;
			else if(flag==0)a[i].qian2++;
			else a[i].hou2++;
		}
		if(a[i].qian1<a[i].qian2)a[i].houcha=a[i].qian2-a[i].qian1;
		else a[i].qiancha=a[i].qian1-a[i].qian2;
	}
	for(long long i=1;i<=m;i++){
		ans=0;
		cin>>q.str1>>q.str2;
		bool flag=0;
		for(long long j=0;j<q.str1.size();j++){
			if(q.str1[j]=='b')flag=1;
			else if(flag==0)q.qian1++;
			else q.hou1++;
		}
		flag=0;
		for(long long j=0;j<q.str2.size();j++){
			if(q.str2[j]=='b')flag=1;
			else if(flag==0)q.qian2++;
			else q.hou2++;
		}
		if(q.qian1<q.qian2)q.houcha=q.qian2-q.qian1;
		else q.qiancha=q.qian1-q.qian2;
		for(long long j=1;j<=n;j++){
//		cout<<a[j].houcha<<" "<<a[j].qiancha<<" "<<a[j].qian1<<" "<<a[j].hou1<<" "<<a[j].qian2<<" "<<a[j].hou2<<" "<<q.houcha<<" "<<q.qiancha<<" "<<q.qian1<<" "<<q.hou1<<" "<<q.qian2<<" "<<q.hou2<<endl;
			if(a[j].houcha==q.houcha&&a[j].qiancha==q.qiancha&&a[j].qian1<=q.qian1&&a[j].hou1<=q.hou1)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
5 4
aaabaa aabaaa
aabaaa baaaaa
aba baa
baaaa aabaa
abaaa aaaba
*/

