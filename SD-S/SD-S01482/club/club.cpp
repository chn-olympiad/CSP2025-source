#include<bits/stdc++.h>
using namespace std;
int a[100005][4];
int cha[100005][4];
//bool cmp1(int t1,int t2){
//	return a[t1][1]>a[t2][1];
//}
//bool cmp2(int t1,int t2){
//	return a[t1][1]>a[t2][1];
//}
//bool cmp3(int t1,int t2){
//	return a[t1][1]>a[t2][1];
//}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	int n;
	while(T--){
		memset(a,0,sizeof a);
		cin>>n;
		vector<int> t1,t2,t3;
		for(int i=1,t;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
				t1.push_back(i);
				t=a[i][1];
			}else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
				t2.push_back(i);
				t=a[i][2];
			}else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
				t3.push_back(i);
				t=a[i][3];
			}
			cha[i][1]=t-a[i][1];
			cha[i][2]=t-a[i][2];
			cha[i][3]=t-a[i][3];
		}
		if(t1.size()<=n/2&&t2.size()<=n/2&&t3.size()<=n/2){
			int ans=0;
			for(int i=0;i<t1.size();i++){
				ans+=a[t1[i]][1];
			}
			for(int i=0;i<t2.size();i++){
				ans+=a[t2[i]][2];
			}
			for(int i=0;i<t3.size();i++){
				ans+=a[t3[i]][3];
			}
			cout<<ans<<"\n";
		}else{
			int minn1=0x7fffffff,minn2=0x7fffffff,minn3=0x7fffffff;
			int mini1=0,mini2=0,mini3=0;
			if(t1.size()>n/2){
				while(t1.size()>n/2){
					minn1=0x7fffffff,minn2=0x7fffffff,minn3=0x7fffffff;
					mini1=0,mini2=0,mini3=0;
					for(int i=0;i<t1.size();i++){
						if(cha[t1[i]][2]<minn2){
							minn2=cha[t1[i]][2];
							mini2=i;
						}
						if(cha[t1[i]][3]<minn3){
							minn3=cha[t1[i]][3];
							mini3=i;
						}
					}
					if(minn2<minn3){
						t2.push_back(mini2);
						vector<int>::iterator t=t1.begin()+mini2;
						t1.erase(t);
					}else{
						t3.push_back(mini3);
						vector<int>::iterator t=t1.begin()+mini3;
						t1.erase(t);
					}
				}
			}else if(t2.size()>n/2){
				while(t2.size()>n/2){
					minn1=0x7fffffff,minn2=0x7fffffff,minn3=0x7fffffff;
					mini1=0,mini2=0,mini3=0;
					for(int i=0;i<t2.size();i++){
						if(cha[t2[i]][1]<minn1){
							minn1=cha[t2[i]][1];
							mini1=i;
						}
						if(cha[t2[i]][3]<minn3){
							minn3=cha[t2[i]][3];
							mini3=i;
						}
					}
					if(minn1<minn3){
						t1.push_back(mini1);
						vector<int>::iterator t=t2.begin()+mini1;
						t2.erase(t);
					}else{
						t3.push_back(mini3);
						vector<int>::iterator t=t2.begin()+mini3;
						t2.erase(t);
					}
				}
			}else if(t3.size()>n/2){
				while(t2.size()>n/2){
					minn1=0x7fffffff,minn2=0x7fffffff,minn3=0x7fffffff;
					mini1=0,mini2=0,mini3=0;
					for(int i=0;i<t3.size();i++){
						if(cha[t3[i]][1]<minn1){
							minn1=cha[t3[i]][1];
							mini1=i;
						}
						if(cha[t3[i]][2]<minn2){
							minn2=cha[t3[i]][2];
							mini2=i;
						}
					}
					if(minn2<minn3){
						t1.push_back(mini1);
						vector<int>::iterator t=t3.begin()+mini1;
						t3.erase(t);
					}else{
						t2.push_back(mini2);
						vector<int>::iterator t=t3.begin()+mini2;
						t3.erase(t);
					}
				}
			}
			int ans=0;
			for(int i=0;i<t1.size();i++){
				ans+=a[t1[i]][1];
			}
			for(int i=0;i<t2.size();i++){
				ans+=a[t2[i]][2];
			}
			for(int i=0;i<t3.size();i++){
				ans+=a[t3[i]][3];
			}
			cout<<ans<<"\n";
			cout<<"\n";
		}
	}
	return 0;
}

