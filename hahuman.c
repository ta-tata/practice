#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct word{
  int num;//出現回数のカウント対象となる数字
  int score;//出現回数
  int sign;//出現回数に応じたhahuman符号を割り当てる.
};

int main(){

char txt[20];
struct word word[10];
int tmp;


//structの初期化
 for(int i=0;i<10;i++){
   word[i].num=0;
   word[i].score=i;
   word[i].sign=0;
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


//ハフマン符号の構成
for(int i=0;i<10;i++){
  for(int j=0;j<=i;j++){
     if(i!=0)word[i].sign =10*word[i-1].sign +10;
  }
}

printf("num \t exist \t hahuman's sign\n");

//確認
for(int i=0;i<10;i++){
  printf("%d \t %d \t %d \n",word[i].score,word[i].num,word[i].sign);
}

return 0;

}
