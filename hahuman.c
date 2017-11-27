#include <stdio.h>

struct word{
  int num;
  int score;
};

int main(){

char txt[20];
struct word word[10];
int tmp;
//structの初期化
 for(int i=0;i<10;i++){
   word[i].num=0;
   word[i].score=i;
 }

//stdinからの入力受付
fgets(txt,20,stdin);

//各数字が何回現れたかの記録
for(int i=0;txt[i];i++){
  word[txt[i]-'0'].num+=1;
}

for(int i=0; i<9; i++){
  for(int j=i+1; j<10; j++){
      //structに含まれるデータを交換し並び替える
    if(word[i].num<word[j].num){
      tmp=word[i].num;//numの取り替え
      word[i].num=word[j].num;
      word[j].num=tmp;
      tmp=word[i].score; //scoreの取り替え
      word[i].score=word[j].score;
      word[j].score=tmp;
    }
    //出現回数が同じ場合はscoreを元に優先順位を決定する.
    if(word[i].num == word[j].num && word[i].score > word[j].score ){
      tmp=word[i].num; //numの取り替え
      word[i].num=word[j].num;
      word[j].num=tmp;
      tmp=word[i].score; //scoreの取り替え
      word[i].score=word[j].score;
      word[j].score=tmp;
    }
  }
}
printf("num \t exist \t hahuman's sign\n");
//確認
for(int i=0;i<10;i++){
  printf("%d \t %d \t ",word[i].score,word[i].num);
  for(int j=0;j<=i;j++){
    if(j==i)printf("0\n");
    else printf("1");
  }
}

return 0;

}
