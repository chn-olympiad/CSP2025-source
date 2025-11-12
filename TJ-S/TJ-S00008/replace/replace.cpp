#include<bits/stdc++.h> 
using namespace std;
const int N=2e5;
int n,q,num,b[N],m;
string s1,s2;
int dao1[N];
struct number1{
	string yu,ti;
	int len;
}a[N];
bool cmp(number1 x,number1 y){
	return x.len<y.len;
}
int zhao(string t1,string t2,int l,int r,int be,int shang){
	int len=t1.length();
	for(int i=be;i<=n;i++){
		if(len==a[i].len){
			if(t1==a[i].yu&&t2==a[i].ti){
				num++;
			}
		}if(len<a[i].len){
			be=i-1;
			break;
		}
	}
	if(len<s1.length()&&len<a[n].len){
		if(l>0&&shang){
			string k1=s1[l-1]+t1,k2=s2[l-1]+t2;
			zhao(k1,k2,l-1,r,be,1);
		}if(r<s1.length()-1&&shang){
			string k1=t1+s1[r+1],k2=t2+s2[r+1];
			zhao(k1,k2,l,r+1,be,0);
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].yu>>a[i].ti;
		a[i].len=a[i].ti.length();
	}sort(a+1,a+n+1,cmp);
	while(q--){
		cin>>s1>>s2;
		if(s1.length()!=s2.length()){
			cout<<0<<endl;
			continue;
		}
		string t1,t2;
		int f1=1,f2=0,l,r;
		for(int i=0;i<s1.length();i++){
			if(s1[i]!=s2[i]&&(f1||b[i-1])){
				if(f1){
					l=i;
					f1=0;
				}
				t1+=s1[i];
				t2+=s2[i];
				r=i;
				b[i]=1;
			} 
		}
		zhao(t1,t2,l,r,1,1);
		cout<<num<<endl;
		num=0;
	}return 0;
}
