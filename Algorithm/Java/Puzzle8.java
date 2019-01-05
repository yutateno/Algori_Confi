/*
 * class : Puzzle8
 */

public class Puzzle8 {
	public static void main(String[] args) {
		
		final int ROWS = 3;	// パズルの行数
		final int COLUMNS = 3;		// パズルの列数
		final int PUZZLESIZE = ROWS * COLUMNS;
		int[] puzzle = new int[PUZZLESIZE];		// 現在のパズル状態
		int[] ans = new int[PUZZLESIZE];		// パズル終了状態
		int empty = 0;		// 空白位置
		final int MAXINDIVIDUAL = 100;		// 探索回数及び遺伝子数
		int[][] nextAns = new int[5][PUZZLESIZE+2];		// 次の4パターンのパズルと直前のパズル
		int[][] result=new int[MAXINDIVIDUAL][MAXINDIVIDUAL+1];	// 探索遺伝子結果
		int[] superPuzzle = new int[3];		// 優位遺伝子から受け継ぐ
		
		
		// 初期化
		for(int i = 0; i < PUZZLESIZE; i++) {
			ans[i] = i;
			puzzle[i] = i;
		}
		for(int i=0;i<nextAns.length;i++) {
			for(int j=0;j<nextAns[i].length;j++) {
				nextAns[i][j]=0;
			}
		}
		for(int i=0;i<result.length;i++) {
			for(int j =0;j<result[i].length;j++) {
			result[i][j]=0;
			}
		}
		for(int i=0;i<superPuzzle.length;i++) {
			superPuzzle[i]=0;
		}
		
		
		// パズルの初期化
		final int SHUFFLE = 50;
		for(int i = 0; i < SHUFFLE; i++){
			int rand = (int)(Math.random()*4);
			
			switch(rand){
			case 0:		// UP
				if(empty < COLUMNS) break;		// 上に動けない
				puzzle[empty] = puzzle[empty - COLUMNS];
				empty = empty - COLUMNS;
				puzzle[empty] = 0;
				break;
			case 1:		// RIGHT
				if((empty + 1) % COLUMNS == 0) break;	// 右に動けない
				puzzle[empty] = puzzle[empty + 1];
				empty = empty + 1;
				puzzle[empty] = 0;
				break;
			case 2:		// DOWN
				if(empty >= PUZZLESIZE - COLUMNS) break;	// 下に動けない
				puzzle[empty] = puzzle[empty + COLUMNS];
				empty = empty + COLUMNS;
				puzzle[empty] = 0;
				break;
			case 3:		// LEFT
				if((empty) % COLUMNS == 0) break;	// 左に動けない
				puzzle[empty] = puzzle[empty - 1];
				empty = empty - 1;
				puzzle[empty] = 0;
				break;
			default:
				break;
			}
		}
		
		// 初期パズルの表示
		final int[] CURRENTPUZZLE = puzzle;
		System.out.println("初期パズル");
		for(int i = 0; i < puzzle.length; i++){
			System.out.print(puzzle[i]);
			if((i + 1) % COLUMNS == 0) System.out.println();
		}
		System.out.println("---");

		
		int count =0;		// パズルの試行回数
		int indiviNum=0;		// 遺伝子数
		int searchNum=0;		// 世代数
		int superNum=-1;		// 優位数
		
		// 世代ループ
		while(searchNum++<MAXINDIVIDUAL) {
			// 遺伝子ループ
			while(indiviNum<MAXINDIVIDUAL) {
				// パズルを初期化
				puzzle=CURRENTPUZZLE;
				count=0;
				
				// 一つの遺伝子の探索
				while(++count<MAXINDIVIDUAL) {
					//正解か確認
					boolean correct=true;
					
					for(int i=0; i<PUZZLESIZE; i++){
						if(puzzle[i]!=ans[i]){ //答えと一致するか比較
							correct=false;
							break;
						}
					}
					
					if(correct) {
						break; //正解
					}
					
					
					nextAns[0][0]=-1;
					
					// 現在のパズルの差分数を調べる
					int tempNum=0;		// 差分数
					for(int i = 0; i < puzzle.length; i++){
						if(puzzle[i]!=0) {
							int tempa=i/ROWS;
							int tempb=i%COLUMNS;
							int tempc=puzzle[i]/ROWS;
							int tempd=puzzle[i]%COLUMNS;
							tempNum+=Math.abs(tempa-tempc)+Math.abs(tempb-tempd);
						}
						
						nextAns[0][i+1]=puzzle[i];
					}
					nextAns[0][PUZZLESIZE+1]=tempNum;
					
					boolean[] cango=new boolean[4];		// 四方向へ移動可能かどうか
					for(int i=0;i<4;i++) {
						cango[i]=false;
					}
					
					// 四方向での移動後のパズルを得る
					for(int i =1;i<nextAns.length;i++) {
						int[] tempPuzzle=new int[PUZZLESIZE];
						
						for(int j = 0; j < puzzle.length; j++) {
							tempPuzzle[j]=puzzle[j];
						}
						
						int tempEnpty=empty;
						nextAns[i][0]=i;
						nextAns[i][PUZZLESIZE+1]=0;
						tempNum=0;
						
						switch(i-1){
						case 0:		// UP
							if(tempEnpty < COLUMNS) {
								nextAns[i][PUZZLESIZE+1]=99;
								break;		// 上に動けない
							}
							
							cango[0]=true;
							tempPuzzle[tempEnpty] = tempPuzzle[tempEnpty - COLUMNS];
							tempEnpty = tempEnpty - COLUMNS;
							tempPuzzle[tempEnpty] = 0;
							break;
						
						case 1:		// RIGHT
							if((tempEnpty + 1) % COLUMNS == 0) {
								nextAns[i][PUZZLESIZE+1]=99;
								break;	// 右に動けない
							}
							
							cango[1]=true;
							tempPuzzle[tempEnpty] = tempPuzzle[tempEnpty + 1];
							tempEnpty = tempEnpty + 1;
							tempPuzzle[tempEnpty] = 0;
							break;
						
						case 2:		// DOWN
							if(tempEnpty >= PUZZLESIZE - COLUMNS) {
								nextAns[i][PUZZLESIZE+1]=99;
								break;	// 下に動けない
							}
							
							cango[2]=true;
							tempPuzzle[tempEnpty] = tempPuzzle[tempEnpty + COLUMNS];
							tempEnpty = tempEnpty + COLUMNS;
							tempPuzzle[tempEnpty] = 0;
							break;
							
							case 3:		// LEFT
								if((tempEnpty) % COLUMNS == 0) {
									nextAns[i][PUZZLESIZE+1]=99;
									break;	// 左に動けない
								}
								
								cango[3]=true;
								tempPuzzle[tempEnpty] = tempPuzzle[tempEnpty - 1];
								tempEnpty = tempEnpty - 1;
								tempPuzzle[tempEnpty] = 0;
								break;
						
							default:
								break;
						}
						
						if(nextAns[i][PUZZLESIZE+1] == 99) continue;
						
						// このパズルでの差分数を調べる
						for(int j = 0; j < tempPuzzle.length; j++){
							if(tempPuzzle[j]!=0) {
								int tempa=j/ROWS;
								int tempb=j%COLUMNS;
								int tempc=tempPuzzle[j]/ROWS;
								int tempd=tempPuzzle[j]%COLUMNS;
								tempNum+=Math.abs(tempa-tempc)+Math.abs(tempb-tempd);
							}
							nextAns[i][j+1]=tempPuzzle[j];
						}
						nextAns[i][PUZZLESIZE+1]=tempNum;
					} // for(int i =1;i<nextAns.length;i++)
					
					
					// どれを渡すか
					int tempArrayNumber=1;
					int tempLowValue=nextAns[1][PUZZLESIZE+1];
					int[] tempLowPuzzle = new int[PUZZLESIZE];
					
					boolean[] setup=new boolean[4];
					for(int i=0;i<4;i++) {
						setup[i]=false;
					}
					
					if(count>2) {
						for(int i=1;i<5;i++) {
							if(nextAns[i][PUZZLESIZE+1]<=tempLowValue) {
								tempArrayNumber=i;
								tempLowValue=nextAns[i][PUZZLESIZE+1];
							}
						}
						// 候補が複数かどうか
						int selectNum=0;
						for(int i =0;i<4;i++) {
							if(tempLowValue==nextAns[i+1][PUZZLESIZE+1]) {
								selectNum++;
								setup[i]=true;
							}
						}
						
						if(selectNum>1) {
							while(true) {
								int tempRand=(int)(Math.random()*4);
								
								if(setup[tempRand] && cango[tempRand]) {
									tempArrayNumber=tempRand+1;
									break;
								}
							}
						}
					}
					else {
						// 優位個体を５個受け継がせる
						if(superNum != -1 && indiviNum < superNum + 5
								&& superPuzzle[count-1]!=0 && cango[superPuzzle[count-1]-1]) {
							int temp = superPuzzle[count-1];
							tempArrayNumber = temp;
						}
						else {
							while(true) {
								int tempRand=(int)(Math.random()*4);
								
								if(cango[tempRand]) {
									tempArrayNumber=tempRand+1;
									break;
								}
							}
						}
					}
					for(int i=1;i<PUZZLESIZE+1;i++) {
						tempLowPuzzle[i-1]=nextAns[tempArrayNumber][i];
					
						if(tempLowPuzzle[i-1]==0) {
							empty=i-1;
						}
					}
					result[indiviNum][count]=tempArrayNumber;
					puzzle=tempLowPuzzle;
				} // while(++count<MAXINDIVIDUAL)
				
				result[indiviNum][0]=count;
				indiviNum++;
			} // while(indiviNum<MAXINDIVIDUAL)
			
			superNum=0;
			
			// 探索できなかったものを-1にする
			for(int i=0;i<result.length;i++) {
				if(result[i][0]>=MAXINDIVIDUAL || superNum>=25) {
					result[i][0]=99;
					for(int j=1;j<result.length;j++) {
						result[i][j]=0;
					}
				}
				else {
					superNum++;
				}
			}
			
			
			// -1を下にやりつつ試行回数少ない順にソート
			int[] temparray = new int[MAXINDIVIDUAL];
			for(int i=0;i<result.length-1;i++) {
				for(int j=i+1;j<result.length;j++) {
					if(result[i][0]>result[j][0]) {
						for(int k=0;k<temparray.length;k++) {
							temparray=result[i];
						}
						for(int k=0;k<temparray.length;k++) {
							result[i]=result[j];
						}
						for(int k=0;k<temparray.length;k++) {
							result[j]=temparray;
						}
					}
				}
			}
			
			// 優位の最初の方を受け継がせる
			superPuzzle[0]=result[0][1];
			superPuzzle[1]=result[0][2];
			superPuzzle[2]=result[0][3];
			// 優位を残す
			if(superNum!=0) {
				indiviNum=superNum;
			}
			else {
				indiviNum = 0;
				superNum=-1;
			}
		} // while(searchNum++<MAXINDIVIDUAL)
		
		// 探索結果
		if(result[0][0] == 99) {
			System.out.println("一回も見つからなかった");
		}
		else {
			System.out.println("最適解："+(result[0][0] - 1));
			for(int i=1;i<result[0].length;i++) {
				switch(result[0][i]) {
				case 1:
					System.out.print("上, ");
					break;
				case 2:
					System.out.print("右, ");
					break;
				case 3:
					System.out.print("下, ");
					break;
				case 4:
					System.out.print("左, ");
					break;
				}
			}
		}
	}
}

/*
 * 実行結果
 * 
初期パズル
632
715
480
---
最適解：10
左, 左, 上, 上, 右, 下, 下, 左, 上, 上, 
 * 
 */
