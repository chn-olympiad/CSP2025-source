#include<bits/stdc++.h>
using namespace std;
long long z,ccc,sa,sb,sc,ans,t,n,cc[100002],maxx[100002],a[100002],b[100002],c[100002];
map <long long,long long> lkj[100],mp,mpp;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		sa=0;
		sb=0;
		sc=0;
		cin>>n;
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]==max(a[i],max(b[i],c[i]))){
				maxx[i]=1;
				sa++;
			}
			else if(b[i]==max(a[i],max(b[i],c[i]))){
				maxx[i]=2;
				sb++;
			}
			else{
				maxx[i]=3;
				sc++;
			}
			ans+=max(a[i],max(b[i],c[i]));
			cc[i]=max(a[i],max(b[i],c[i]))-(a[i]+b[i]+c[i]-max(a[i],max(b[i],c[i]))-min(a[i],min(b[i],c[i])));
			if(lkj[mp[cc[i]]][cc[i]]!=i){
				mp[cc[i]]++;
				lkj[mp[cc[i]]][cc[i]]=i;
			}
			
		}
//		cout<<ans<<'\n';
		if(sa>n/2||sb>n/2||sc>n/2){
			if(sa==max(sa,max(sb,sc))){
				z=1;
			}
			else if(sb==max(sa,max(sb,sc))){
				z=2;
			}
			else{
				z=3;
			}
			ccc=max(sa,max(sb,sc))-n/2;
			sort(cc+1,cc+n+1);
			
			for(long long i=1;i<=ccc;i++){
				mpp[cc[i]]++;
				if(maxx[lkj[mpp[cc[i]]][cc[i]]]==z){
//					cout<<cc[i]<<'\n';
					ans-=cc[i];
				}
				else{
					ccc++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
/*
先睡了20分钟再起来写 
跳了好久，应该有80 ，大样例时间很悬 
（听见周围人敲键盘声十分有力道）
 
距离考试结束：00:26:03
还好发现文件读写没改 

距离考试结束：00:18:55
再测一下，然后写点啥吧
距离考试结束：00:17:05
样例都没问题，总体分数预计80，应该有三等奖

今天 第一次考s组，第二次考j组（预计250） 
学的时间不算很多
比我的学校同年级大多数人晚学一年多，上次考试分数没想到还行，别人好多都退役了 
前期迷迷糊糊都能懂，进步很快，学到后面发现好难
上林老的课前面还听得懂一些
到了后面好难理解，自己没什么天赋，也没非常多时间学 
上的最懂得几节课就是并查集（很好写，好理解），但发现不怎么用得到

距离考试结束：00:08:26
确实提升了好多，但还是不太行 
但这次考的至少比之前考s模拟很多次要好
也是会做一道比较长的题了

距离考试结束：00:05:31
高中应该不会学信奥了，大学应该也不会了 
要终身退役了吧 

学的这两年挺开心的，挺有兴趣
但后面难的实在学不动了

就这样吧
还有一分钟了
————————————————
————————————————
——————退役——————
————————————————
————————————————
*/