import java.util.Scanner;//標準入力からの入力を受け取るために必要なオブジェクト


public class Hahuman{


  public static void main(String[] args){

    int score[]=new int[10];
    Date[] date=new Date[10];
    int tmp;

//dateの初期化
//自分でclass(構造体)を作った場合で,それを配列で扱いたい場合は２ステップ必要！！
// 1:配列の宣言(連続するメモリ10個を確保) -> Date[] date=new Date[10];
// 2:確保したメモリ上で,順番にDateインスタンスを作っていく -> 以下のfor文
    for(int i=0;i<10;i++){
       date[i]=new Date();
       date[i].num=i;
       date[i].score=0;
    }

//入力部分
    Scanner scanner=new Scanner(System.in);//Scanner型のscannerを定義
    String input_txt=scanner.nextLine();//読み込みが可能

//Stringをchar型へ！！(1文字づつ扱いたいから)
    char txt[]=new char[input_txt.length()];// 読み込んだtxtと同じサイズの配列の用意
   for(int i=0;i<input_txt.length();i++)  txt[i]=input_txt.charAt(i);//input_txtのi文字目をchar型へ

// 出現回数のカウント
   for(int i=0;i<input_txt.length();i++)  date[txt[i]-'0'].score+=1;

//頻度順に並び替え
   for(int i=0; i<9; i++){
     for(int j=i+1; j<10; j++){
         //structに含まれるデータを交換し並び替える
       if(date[i].score<date[j].score){
         tmp=date[i].num;//numの取り替え
         date[i].num=date[j].num;
         date[j].num=tmp;
         tmp=date[i].score; //scoreの取り替え
         date[i].score=date[j].score;
         date[j].score=tmp;
       }
       //出現回数が同じ場合はscoreを元に優先順位を決定する.
       if(date[i].score == date[j].score && date[i].num > date[j].num ){
         tmp=date[i].num; //numの取り替え
         date[i].num=date[j].num;
         date[j].num=tmp;
         tmp=date[i].score; //scoreの取り替え
         date[i].score=date[j].score;
         date[j].score=tmp;
       }
     }
   }

   for(int i=0;i<10;i++){
     System.out.printf("num=%d , %d , ",date[i].num,date[i].score);
     for(int j=0;j<i;j++) System.out.printf("1");
      System.out.printf("0\n");
   }
   }
}
