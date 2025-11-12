#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct stu{
	int vid,id,vid2;
} s[N];
struct stu1{
	int vid,id,vid2;
} s1[N];
struct stu2{
	int vid,id,vid2;
} s2[N];
int a[N];
bool cmp(stu a,stu b){
	if(a.vid==b.vid){
		return a.vid2<b.vid2;
	}
	else{
		return a.vid>b.vid;
	}
}
bool cmp1(stu1 a,stu1 b){
	if(a.vid==b.vid){
		return a.vid2<b.vid2;
	}
	else{
		return a.vid>b.vid;
	}
}
bool cmp2(stu2 a,stu2 b){
	if(a.vid==b.vid){
		return a.vid2<b.vid2;
	}
	else{
		return a.vid>b.vid;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n,a2=0,b2=0,c2=0,cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a1,b1,c1;
			cin>>a1>>b1>>c1;
			a[i]=max(a1,max(b1,c1));
			if(a[i]==a1){
				s[a2+1].id=i;
				s[a2+1].vid=a1;
				s[a2+1].vid2=max(b1,c1);
				a2++;
			} 
			else if(b1==a[i]){
				s1[b2+1].id=i;
				s1[b2+1].vid=b1; 
				s1[b2+1].vid2=max(a1,c1);
				b2++;
			}
			else{
				s2[c2+1].id=i;
				s2[c2+1].vid=c1;
				s2[c2+1].vid2=max(a1,b1); 
				c2++;
			}
		}
		if(a2>(n/2)){
			sort(s+1,s+a2+1,cmp);
			for(int i=1;i<=n/2;i++){
				cnt+=s[i].vid;
			}			
			for(int i=n/2+1;i<=a2;i++){
				cnt+=s[i].vid2;
			}
			for(int i=1;i<=b2;i++){
				cnt+=s1[i].vid;
			}
			for(int i=1;i<=c2;i++){
				cnt+=s2[i].vid;
			}
			cout<<cnt<<endl;						
		}
		else if(b2>(n/2)){
			sort(s1+1,s1+b2+1,cmp1);
			for(int i=1;i<=n/2;i++){
				cnt+=s1[i].vid;
			}			
			for(int i=n/2+1;i<=b2;i++){
				cnt+=s1[i].vid2;
			}
			for(int i=1;i<=a2;i++){
				cnt+=s[i].vid;
			}
			for(int i=1;i<=c2;i++){
				cnt+=s2[i].vid;
			}
			cout<<cnt<<endl;				
		}
		else if(c2>(n/2)){
			sort(s2+1,s2+c2+1,cmp2);
			for(int i=1;i<=n/2;i++){
				cnt+=s2[i].vid;
			}			
			for(int i=n/2+1;i<=c2;i++){
				cnt+=s2[i].vid2;
			}
			for(int i=1;i<=b2;i++){
				cnt+=s1[i].vid;
			}
			for(int i=1;i<=a2;i++){
				cnt+=s[i].vid;
			}
			cout<<cnt<<endl;				
		}
		else{
			for(int i=1;i<=a2;i++){
				cnt+=s[i].vid;
			}
			for(int i=1;i<=b2;i++){
				cnt+=s1[i].vid;
			}
			for(int i=1;i<=c2;i++){
				cnt+=s2[i].vid;
			}		
			cout<<cnt<<endl;	
		}
	}
	return 0;
}

