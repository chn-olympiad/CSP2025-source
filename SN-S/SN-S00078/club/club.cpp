#include <bits/stdc++.h>
using namespace std;
struct{
	int a,b,c;
}s[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int x=0;x<t;x++){
		int n,m=0,ma=0,m1=0,m2=0,m3=0,mb=0,mc=0,s1=0,s2=0,s3=0;
		cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
	}
	for(int i=0;i<n;i++){
		ma=-1,mb=-1,mc=-1;
			if(s[i].a>ma&&i!=m2&&i!=m3&&n/2>s1){
				ma=s[i].a;
				s1++;
				m1=i;
				s[i].a=-2;
			}
			if(s[i].b>mb&&i!=m1&&i!=m3&&n/2>s2){
				mb=s[i].b;
				m2=i;
				s2++;
				s[i].b=-2;
			}
			if(s[i].c>mc&&i!=m1&&i!=m2&&n/2>s3){
				mc=s[i].c;
				m3=i;
				s3++;
				s[i].c=-2;
			}
			m=mb+mc+ma;
	}
	cout<<m<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
