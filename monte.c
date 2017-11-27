// モンテカルロ法のプログラム(<-乱数を使ってそれらしいものを出力する手法.大数の法則的な感じ=確率的)
// 円周率を求める
// 正方形内に,ランダムにN点をとる.(rand_x,rand_y)
// これらの点で単位円内にあるもの(IN),と無いもの(OUT)を数えそれらの比を取る.

#define N 220
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 平方計算を使うのでそれの定義
double square(double p){
   return p*p;
  }

int main(){

// 変数宣言
  double rand_x[N],rand_y[N];
  int IN=0,OUT=0;

// 点をランダムにばらまく
  //srand((unsigned)time(NULL));<-従来は時間依存にしてさらに乱数らしさを与えるが
  //                              今回は,Nに比例してpiが収束していく過程を見たいので,固定乱数とする.
  for(int i=0;i<N;i++){
    rand_x[i]=rand()%11;
    rand_y[i]=rand()%11;
  }

// OUT,INに振り分けていく
  for(int i=0;i<N;i++){
    if( square(rand_x[i]) < rand_y[i] ) OUT++;
    else IN++;
  }

// ここで,面積の関係から次式が得られる.
//  1 : pi/4 = N : IN
printf("pi=%lf\n",4.0*IN/N);

return 0;

}
