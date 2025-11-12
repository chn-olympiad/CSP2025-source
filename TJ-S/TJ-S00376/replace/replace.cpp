#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[200100];
int timee[200100];
vector<short> b1[100][200100],b2[100][200100];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
//		a[i][timee[s1.size()]]=s1.size();
		for(int j=0;j<s1.size();j++){
			b1[s1.size()][timee[s1.size()]].push_back(s1[j]-'a');
		}
		for(int j=0;j<s2.size();j++){
			b2[s1.size()][timee[s1.size()]].push_back(s2[j]-'a');
		}
		timee[s1.size()]++;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		int ans=0,kkk=1;
		cin>>t1>>t2;
		for(int j=0;j<timee[t1.size()];j++){
			kkk=1;
			for(int k=0;k<t1.size();k++){
//			cout<<"z";
				if((t1[k]-'a')!=(b1[t1.size()][j][k])){
//				cout<<"h";
					kkk=0;
//					break;
				}
				if((t2[k]-'a')!=(b2[t1.size()][j][k])){
//					cout<<"a";
					kkk=0;
//					break;
				}
			}
//			cout<<endl;
			if(kkk){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//4 2
//b a
//a b
//baaa aaab
//aaba abaa
