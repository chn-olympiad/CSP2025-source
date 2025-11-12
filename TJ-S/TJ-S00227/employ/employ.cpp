#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,givup=0,tem=0;
string paper;
long long ans=1;
int candi[505],bckt[505]={0};
void solve1(int x){//A
    int y=x;
	for(int i=n;i>=n-x+1;i--){
		if(candi[i]<=givup) y--;
	}
	for(int i=2;i<=y;i++){
		ans*=i;
		ans%=998244353;
	}
}
void solveg(int x){
	ans=1;
	for(int i=2;i<=x;i++){
		ans*=i;
		ans%=998244353;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>paper;
	for(int i=1;i<=n;i++){
		cin>>candi[i];
		bckt[candi[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(candi[i]>bckt[0]) tem++;
	}
	/*sort(candi+1,candi+n+1);
	for(int i=1;i<=n;i++){
		if(candi[i]<=givup) continue;
		if(paper[i-1]=='0'){
			givup++;
			ans*=bckt[candi[i]];
			ans%=998244353;
		}else{
			m--;
			ans*=bckt[candi[i]];
			ans%=998244353;
		}
		if(m==0){
			solve1(n-i);
			break;
		}
	}*/
	solveg(tem);
	cout<<ans;
	return 0;
}
//My Final CSP-S Journal.
//17:06 It makes more sense than Replace.
//17:07 We Notice That:
//          Idiots can get 20pts too.
//      So Why Not NoGeneral First?
//17:09 I changed my idea.
//      I just can't leave a pity for my last CSP-S.
//      The Hope...The Bravery...The Insanity...
//      It's those which pushed me here.And I couldn't betray them anymore.
//17:27 Oh,sweet,soft NTTmod,we all missed you very much.
//17:33 It just can't work.
//17:36 Maybe I Really Can't Do It.
//      No Way!I'll Try It Again!I Should Fight Till The Last 1ms!
//17:47 But NoGeneral First,cuz I Have To Make Sure of 20pts.
//18:08 Oh,I'm Even Not An Idiot.=)
//      Ach,nein!
//      87pts.Is this the limit?
//      ......I'll just give up at 19:00.Too Many Employees Were Refused Before Me,And My c_i Is Only 5.
//      ...
//      闭嘴！老子今天跟你死磕到底！！！
//18:28 Yes!!!!!!!!!!!!!I finally have it done!!!!!!!!!!!!!
//      I knew I'm not that old and stupid!!!!!!!!!
//18:29 Gotta try T3.






//Well.I think it's time for me to stop my voyage.
//        -----The Speech Before AFO-----
//freopen()
//......Uh,what shall I say?
//There's too much but also too little to say.
//Little time is left for me......I have to do this quickly.
//When I was young,I used to play lots of video games.
//And I once listened to Jay Chou's songs as well.
//There is a song which says,'The children listen to my songs when we grow up now'.
//So I thought,
//'Is there one day that my games will be played by others,just like how I played the former games?'
//With that dream,I started to learn programming.
//Scratch,Python,C++...
//And I found myself not running towards my dream.
//I just wanted to tell stories,as we used to do.
//Neither the prizes nor the glory do I want.
//So I decided to get everything back on track.
//And then an OIer dies.
//With the summer,with the wonders,with the insanity.
//And now,I'm heading for the realise of The Project.
//And I saw Wendy and Katherine waving to me.
//Thanks to CCF,for the oppurtunities and memories which they gave me.
//Thanks to xingxing and my classmates,who encouraged and taught me a lot during those years.
//Thanks to you,who has a high c_i which supports you to finish the passage.
//And it's time to wind up the passage,with my OI life.
//The ten-year life of OI was not more than void,that a forgotten long long took you to your ancesters.
//Bye,CSP.
//AFO.
