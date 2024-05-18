#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 
using namespace std;
class chessBoard {
public:
  string board[8][8]; string fboard[8][8];
  string checkW[8][8]; string checkB[8][8];
  bool wCheck = false; bool bCheck = false;
  bool wMate = false; bool bMate = false;
  bool draw = false;
  string color = "w";
  vector<int> pMr; vector<int> pMc;
  bool wKm = false; bool bKm = false;
  bool wR1m = false; bool wR2m = false;
  bool bR1m = false; bool bR2m = false;
  bool wep = false; bool bep = false;
  int epc = 0;
  int mR = 0;
  vector<string> mC;
  vector<string> ps;
  void setUp () {
    pMc.clear(); pMr.clear();
    mC.clear();
    wCheck = false; bCheck = false;
    wMate = false; bMate = false;
    color = "w";
    wKm = false; bKm = false;
    wR1m = false; wR2m = false;
    bR1m = false; bR2m = false;
    wep = false; bep = false;
    epc = 0;
    mR = 0;
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        board[i][j] = "";
        fboard[i][j] = "";
        checkW[i][j] = "";
        checkB[i][j] = "";
      }
    }
    board[0][0] = "bR"; board[0][7] = "bR";
    board[7][0] = "wR"; board[7][7] = "wR";
    board[0][1] = "bN"; board[0][6] = "bN";
    board[7][1] = "wN"; board[7][6] = "wN";
    board[0][2] = "bB"; board[0][5] = "bB";
    board[7][2] = "wB"; board[7][5] = "wB";
    board[0][3] = "bQ"; board[0][4] = "bK";
    board[7][3] = "wQ"; board[7][4] = "wK";
    for (int i=0;i<8;i++) {board[1][i] = "bP"; board[6][i] = "wP";}
  }
  string getA(string p) {
    return p.substr(0,1);
  }
  string getApos(int r, string c) {
    int co = 0;
    if (c == "a") {
      co = 0;
    } else if (c == "b") {
      co = 1;
    } else if (c == "c") {
      co = 2;
    } else if (c == "d") {
      co = 3;
    } else if (c == "e") {
      co = 4;
    } else if (c == "f") {
      co = 5;
    } else if (c == "g") {
      co = 6;
    } else if (c == "h") {
      co = 7;
    }
    string p = board[8-r][co];
    if (p=="") {
      return "";
    } else {
      return getA(p);
    }
  }
  string getP(string p) {
    return p.substr(1,1);
  }
  void fp() {
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        fboard[i][j] = board[i][j];
      }
    }
  }
  void pf() {
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        board[i][j] = fboard[i][j];
      }
    }
  }
  void checker(int b) {
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        checkW[i][j] = "";
        checkB[i][j] = "";
      }
    }
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        if (b==1) {
          if (board[i][j]!="") {
            if (getP(board[i][j])=="N") {
              if (!((j<=1)||(i==0))) {
                if (getA(board[i][j])!=getA(board[i-1][j-2])) {
                  if (getA(board[i][j])=="w") {
                    checkB[i-1][j-2] = "x";
                  } else {
                    checkW[i-1][j-2] = "x";
                  }
                }
              }
              if (!((j==0)||(i<=1))) {
                if (getA(board[i][j])!=getA(board[i-2][j-1])) {
                  if (getA(board[i][j])=="w") {
                    checkB[i-2][j-1] = "x";
                  } else {
                    checkW[i-2][j-1] = "x";
                  }
                }
              }
              if (!((j>=6)||(i==0))) {
                if (getA(board[i][j])!=getA(board[i-1][j+2])) {
                  if (getA(board[i][j])=="w") {
                    checkB[i-1][j+2] = "x";
                  } else {
                    checkW[i-1][j+2] = "x";
                  }
                }
              }
              if (!((j==7)||(i<=1))) {
                if (getA(board[i][j])!=getA(board[i-2][j+1])) {
                  if (getA(board[i][j])=="w") {
                    checkB[i-2][j+1] = "x";
                  } else {
                    checkW[i-2][j+1] = "x";
                  }
                }
              }
              if (!((j<=1)||(i==7))) {
                if (getA(board[i][j])!=getA(board[i+1][j-2])) {
                  if (getA(board[i][j])=="w") {
                    checkB[i+1][j-2] = "x";
                  } else {
                    checkW[i+1][j-2] = "x";
                  }
                }
              }
              if (!((j==0)||(i>=6))) {
                if (getA(board[i][j])!=getA(board[i+2][j-1])) {
                  if (getA(board[i][j])=="w") {
                    checkB[i+2][j-1] = "x";
                  } else {
                    checkW[i+2][j-1] = "x";
                  }
                }
              }
              if (!((j>=6)||(i==7))) {
                if (getA(board[i][j])!=getA(board[i+1][j+2])) {
                  if (getA(board[i][j])=="w") {
                    checkB[i+1][j+2] = "x";
                  } else {
                    checkW[i+1][j+2] = "x";
                  }
                }
              }
              if (!((j==7)||(i>=6))) {
                if (getA(board[i][j])!=getA(board[i+2][j+1])) {
                  if (getA(board[i][j])=="w") {
                    checkB[i+2][j+1] = "x";
                  } else {
                    checkW[i+2][j+1] = "x";
                  }
                }
              }
            } else if (getP(board[i][j])=="P") {
              if (j!=7) {
                if (getA(board[i][j])=="w") {
                  checkB[i-1][j+1] = "x";
                } else {
                  checkW[i+1][j+1] = "x";
                }
              }
              if (j!=0) {
                if (getA(board[i][j])=="w") {
                  checkB[i-1][j-1] = "x";
                } else {
                  checkW[i+1][j-1] = "x";
                }
              }
            } else if (getP(board[i][j])=="K") {
              if (getA(board[i][j])=="w") {
                if (i!=7) {
                  checkB[i+1][j] = "x";
                }
                if ((i!=7)&&(j!=0)) {
                  checkB[i+1][j-1] = "x";
                }
                if (i!=0) {
                  checkB[i-1][j] = "x";
                }
                if ((i!=0)&&(j!=0)) {
                  checkB[i-1][j-1] = "x";
                }
                if (j!=0) {
                  checkB[i][j-1] = "x";
                }
                if (j!=7) {
                  checkB[i][j+1] = "x";
                }
                if ((i!=0)&&(j!=7)) {
                  checkB[i-1][j+1] = "x";
                }
                if ((i!=7)&&(j!=7)) {
                  checkB[i+1][j+1] = "x";
                }
              } else {
                if (i!=7) {
                  checkW[i+1][j] = "x";
                }
                if ((i!=7)&&(j!=0)) {
                  checkW[i+1][j-1] = "x";
                }
                if (i!=0) {
                  checkW[i-1][j] = "x";
                }
                if ((i!=0)&&(j!=0)) {
                  checkW[i-1][j-1] = "x";
                }
                if (j!=0) {
                  checkW[i][j-1] = "x";
                }
                if (j!=7) {
                  checkW[i][j+1] = "x";
                }
                if ((i!=0)&&(j!=7)) {
                  checkW[i-1][j+1] = "x";
                }
                if ((i!=7)&&(j!=7)) {
                  checkW[i+1][j+1] = "x";
                }
              }
            } else {
              if ((getP(board[i][j])=="Q")||(getP(board[i][j])=="R")) {
                if (j!=7) {
                  for (int g=j+1;g<=7;g++) {
                    if (board[i][g]!="") {
                      if (getA(board[i][j])!=getA(board[i][g])) {
                        if (getA(board[i][j])=="w") {
                          checkB[i][g] = "x";
                        } else {
                          checkW[i][g] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(board[i][j])=="w") {
                      checkB[i][g] = "x";
                    } else {
                      checkW[i][g] = "x";
                    }
                  }
                }
                if (j!=0) {
                  for (int g=j-1;g>=0;g--) {
                    if (board[i][g]!="") {
                      if (getA(board[i][j])!=getA(board[i][g])) {
                        if (getA(board[i][j])=="w") {
                          checkB[i][g] = "x";
                        } else {
                          checkW[i][g] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(board[i][j])=="w") {
                      checkB[i][g] = "x";
                    } else {
                      checkW[i][g] = "x";
                    }
                  }
                }
                if (i!=0) {
                  for (int g=i+1;g<=7;g++) {
                    if (board[g][j]!="") {
                      if (getA(board[i][j])!=getA(board[g][j])) {
                        if (getA(board[i][j])=="w") {
                          checkB[g][j] = "x";
                        } else {
                          checkW[g][j] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(board[i][j])=="w") {
                      checkB[g][j] = "x";
                    } else {
                      checkW[g][j] = "x";
                    }
                  }
                }
                if (i!=7) {
                  for (int g=i-1;g>=0;g--) {
                    if (board[g][j]!="") {
                      if (getA(board[i][j])!=getA(board[g][j])) {
                        if (getA(board[i][j])=="w") {
                          checkB[g][j] = "x";
                        } else {
                          checkW[g][j] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(board[i][j])=="w") {
                      checkB[g][j] = "x";
                    } else {
                      checkW[g][j] = "x";
                    }
                  }
                }
              }
              if ((getP(board[i][j])=="Q")||(getP(board[i][j])=="B")) {
                int I=1;
                if (!((j==0)||(i==7))) {
                  while (!(((j-I)==-1)||((i+I)==8))) {  
                    if (board[i+I][j-I]!="") {
                      if (getA(board[i][j])!=getA(board[i+I][j-I])) {
                        if (getA(board[i][j])=="w") {
                          checkB[i+I][j-I] = "x";
                        } else {
                          checkW[i+I][j-I] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(board[i][j])=="w") {
                      checkB[i+I][j-I] = "x";
                    } else {
                      checkW[i+I][j-I] = "x";
                    }
                    I++;
                  }
                }
                I=1;
                if (!((j==7)||(i==7))) {
                  while (!(((j+I)==8)||((i+I)==8))) {  
                    if (board[i+I][j+I]!="") {
                      if (getA(board[i][j])!=getA(board[i+I][j+I])) {
                        if (getA(board[i][j])=="w") {
                          checkB[i+I][j+I] = "x";
                        } else {
                          checkW[i+I][j+I] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(board[i][j])=="w") {
                      checkB[i+I][j+I] = "x";
                    } else {
                      checkW[i+I][j+I] = "x";
                    }
                    I++;
                  }
                }
                I=1;
                if (!((j==0)||(i==0))) {
                  while (!(((j-I)==-1)||((i-I)==-1))) {  
                    if (board[i-I][j-I]!="") {
                      if (getA(board[i][j])!=getA(board[i-I][j-I])) {
                        if (getA(board[i][j])=="w") {
                          checkB[i-I][j-I] = "x";
                        } else {
                          checkW[i-I][j-I] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(board[i][j])=="w") {
                      checkB[i-I][j-I] = "x";
                    } else {
                      checkW[i-I][j-I] = "x";
                    }
                    I++;
                  }
                }
                I=1;
                if (!((j==7)||(i==0))) {
                  while (!(((j+I)==8)||((i-I)==-1))) {  
                    if (board[i-I][j+I]!="") {
                      if (getA(board[i][j])!=getA(board[i-I][j+I])) {
                        if (getA(board[i][j])=="w") {
                          checkB[i-I][j+I] = "x";
                        } else {
                          checkW[i-I][j+I] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(board[i][j])=="w") {
                      checkB[i-I][j+I] = "x";
                    } else {
                      checkW[i-I][j+I] = "x";
                    }
                    I++;
                  }
                }
              }
            }
          }
        } else {
          if (fboard[i][j]!="") {
            if (getP(fboard[i][j])=="N") {
              if (!((j<=1)||(i==0))) {
                if (getA(fboard[i][j])!=getA(fboard[i-1][j-2])) {
                  if (getA(fboard[i][j])=="w") {
                    checkB[i-1][j-2] = "x";
                  } else {
                    checkW[i-1][j-2] = "x";
                  }
                }
              }
              if (!((j==0)||(i<=1))) {
                if (getA(fboard[i][j])!=getA(fboard[i-2][j-1])) {
                  if (getA(fboard[i][j])=="w") {
                    checkB[i-2][j-1] = "x";
                  } else {
                    checkW[i-2][j-1] = "x";
                  }
                }
              }
              if (!((j>=6)||(i==0))) {
                if (getA(fboard[i][j])!=getA(fboard[i-1][j+2])) {
                  if (getA(fboard[i][j])=="w") {
                    checkB[i-1][j+2] = "x";
                  } else {
                    checkW[i-1][j+2] = "x";
                  }
                }
              }
              if (!((j==7)||(i<=1))) {
                if (getA(fboard[i][j])!=getA(fboard[i-2][j+1])) {
                  if (getA(fboard[i][j])=="w") {
                    checkB[i-2][j+1] = "x";
                  } else {
                    checkW[i-2][j+1] = "x";
                  }
                }
              }
              if (!((j<=1)||(i==7))) {
                if (getA(fboard[i][j])!=getA(fboard[i+1][j-2])) {
                  if (getA(fboard[i][j])=="w") {
                    checkB[i+1][j-2] = "x";
                  } else {
                    checkW[i+1][j-2] = "x";
                  }
                }
              }
              if (!((j==0)||(i>=6))) {
                if (getA(fboard[i][j])!=getA(fboard[i+2][j-1])) {
                  if (getA(fboard[i][j])=="w") {
                    checkB[i+2][j-1] = "x";
                  } else {
                    checkW[i+2][j-1] = "x";
                  }
                }
              }
              if (!((j>=6)||(i==7))) {
                if (getA(fboard[i][j])!=getA(fboard[i+1][j+2])) {
                  if (getA(fboard[i][j])=="w") {
                    checkB[i+1][j+2] = "x";
                  } else {
                    checkW[i+1][j+2] = "x";
                  }
                }
              }
              if (!((j==7)||(i>=6))) {
                if (getA(fboard[i][j])!=getA(fboard[i+2][j+1])) {
                  if (getA(fboard[i][j])=="w") {
                    checkB[i+2][j+1] = "x";
                  } else {
                    checkW[i+2][j+1] = "x";
                  }
                }
              }
            } else if (getP(fboard[i][j])=="P") {
              if (j!=7) {
                if (getA(fboard[i][j])=="w") {
                  checkB[i-1][j+1] = "x";
                } else {
                  checkW[i+1][j+1] = "x";
                }
              }
              if (j!=0) {
                if (getA(fboard[i][j])=="w") {
                  checkB[i-1][j-1] = "x";
                } else {
                  checkW[i+1][j-1] = "x";
                }
              }
            } else if (getP(fboard[i][j])=="K") {
              if (getA(fboard[i][j])=="w") {
                if (i!=7) {
                  checkB[i+1][j] = "x";
                }
                if ((i!=7)&&(j!=0)) {
                  checkB[i+1][j-1] = "x";
                }
                if (i!=0) {
                  checkB[i-1][j] = "x";
                }
                if ((i!=0)&&(j!=0)) {
                  checkB[i-1][j-1] = "x";
                }
                if (j!=0) {
                  checkB[i][j-1] = "x";
                }
                if (j!=7) {
                  checkB[i][j+1] = "x";
                }
                if ((i!=0)&&(j!=7)) {
                  checkB[i-1][j+1] = "x";
                }
                if ((i!=7)&&(j!=7)) {
                  checkB[i+1][j+1] = "x";
                }
              } else {
                if (i!=7) {
                  checkW[i+1][j] = "x";
                }
                if ((i!=7)&&(j!=0)) {
                  checkW[i+1][j-1] = "x";
                }
                if (i!=0) {
                  checkW[i-1][j] = "x";
                }
                if ((i!=0)&&(j!=0)) {
                  checkW[i-1][j-1] = "x";
                }
                if (j!=0) {
                  checkW[i][j-1] = "x";
                }
                if (j!=7) {
                  checkW[i][j+1] = "x";
                }
                if ((i!=0)&&(j!=7)) {
                  checkW[i-1][j+1] = "x";
                }
                if ((i!=7)&&(j!=7)) {
                  checkW[i+1][j+1] = "x";
                }
              }
            } else {
              if ((getP(fboard[i][j])=="Q")||(getP(fboard[i][j])=="R")) {
                if (j!=7) {
                  for (int g=j+1;g<=7;g++) {
                    if (fboard[i][g]!="") {
                      if (getA(fboard[i][j])!=getA(fboard[i][g])) {
                        if (getA(fboard[i][j])=="w") {
                          checkB[i][g] = "x";
                        } else {
                          checkW[i][g] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(fboard[i][j])=="w") {
                      checkB[i][g] = "x";
                    } else {
                      checkW[i][g] = "x";
                    }
                  }
                }
                if (j!=0) {
                  for (int g=j-1;g>=0;g--) {
                    if (fboard[i][g]!="") {
                      if (getA(fboard[i][j])!=getA(fboard[i][g])) {
                        if (getA(fboard[i][j])=="w") {
                          checkB[i][g] = "x";
                        } else {
                          checkW[i][g] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(fboard[i][j])=="w") {
                      checkB[i][g] = "x";
                    } else {
                      checkW[i][g] = "x";
                    }
                  }
                }
                if (i!=0) {
                  for (int g=i+1;g<=7;g++) {
                    if (fboard[g][j]!="") {
                      if (getA(fboard[i][j])!=getA(fboard[g][j])) {
                        if (getA(fboard[i][j])=="w") {
                          checkB[g][j] = "x";
                        } else {
                          checkW[g][j] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(fboard[i][j])=="w") {
                      checkB[g][j] = "x";
                    } else {
                      checkW[g][j] = "x";
                    }
                  }
                }
                if (i!=7) {
                  for (int g=i-1;g>=0;g--) {
                    if (fboard[g][j]!="") {
                      if (getA(fboard[i][j])!=getA(fboard[g][j])) {
                        if (getA(fboard[i][j])=="w") {
                          checkB[g][j] = "x";
                        } else {
                          checkW[g][j] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(fboard[i][j])=="w") {
                      checkB[g][j] = "x";
                    } else {
                      checkW[g][j] = "x";
                    }
                  }
                }
              }
              if ((getP(fboard[i][j])=="Q")||(getP(fboard[i][j])=="B")) {
                int I=1;
                if (!((j==0)||(i==7))) {
                  while (!(((j-I)==-1)||((i+I)==8))) {  
                    if (fboard[i+I][j-I]!="") {
                      if (getA(fboard[i][j])!=getA(fboard[i+I][j-I])) {
                        if (getA(fboard[i][j])=="w") {
                          checkB[i+I][j-I] = "x";
                        } else {
                          checkW[i+I][j-I] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(fboard[i][j])=="w") {
                      checkB[i+I][j-I] = "x";
                    } else {
                      checkW[i+I][j-I] = "x";
                    }
                    I++;
                  }
                }
                I=1;
                if (!((j==7)||(i==7))) {
                  while (!(((j+I)==8)||((i+I)==8))) {  
                    if (fboard[i+I][j+I]!="") {
                      if (getA(fboard[i][j])!=getA(fboard[i+I][j+I])) {
                        if (getA(fboard[i][j])=="w") {
                          checkB[i+I][j+I] = "x";
                        } else {
                          checkW[i+I][j+I] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(fboard[i][j])=="w") {
                      checkB[i+I][j+I] = "x";
                    } else {
                      checkW[i+I][j+I] = "x";
                    }
                    I++;
                  }
                }
                I=1;
                if (!((j==0)||(i==0))) {
                  while (!(((j-I)==-1)||((i-I)==-1))) {  
                    if (fboard[i-I][j-I]!="") {
                      if (getA(fboard[i][j])!=getA(fboard[i-I][j-I])) {
                        if (getA(fboard[i][j])=="w") {
                          checkB[i-I][j-I] = "x";
                        } else {
                          checkW[i-I][j-I] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(fboard[i][j])=="w") {
                      checkB[i-I][j-I] = "x";
                    } else {
                      checkW[i-I][j-I] = "x";
                    }
                    I++;
                  }
                }
                I=1;
                if (!((j==7)||(i==0))) {
                  while (!(((j+I)==8)||((i-I)==-1))) {  
                    if (fboard[i-I][j+I]!="") {
                      if (getA(fboard[i][j])!=getA(fboard[i-I][j+I])) {
                        if (getA(fboard[i][j])=="w") {
                          checkB[i-I][j+I] = "x";
                        } else {
                          checkW[i-I][j+I] = "x";
                        }
                      }
                      break;
                    }
                    if (getA(fboard[i][j])=="w") {
                      checkB[i-I][j+I] = "x";
                    } else {
                      checkW[i-I][j+I] = "x";
                    }
                    I++;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  void checkingF(string c) {
    checker(0);
    if (c=="w") {
      wCheck = false;
    } else {
      bCheck = false;
    }
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        if (c=="w") {
          if ((fboard[i][j]=="wK")&&(checkW[i][j]=="x")) {
            wCheck = true;
            break;
          }
        } else {
          if ((fboard[i][j]=="bK")&&(checkB[i][j]=="x")) {
            bCheck = true;
            break;
          }
        }
      }
    }
  }
  void getMoves(string p,int r,int c,string A){
    //r:1-8 c:0-7
    if (p=="P") {
      if (color=="w") {
        if (board[8-(r+1)][c]=="") {
          pMc.push_back(c);
          pMr.push_back(r+1);
          if (r==2) {
            if (board[8-(r+2)][c]=="") {
              pMc.push_back(c);
              pMr.push_back(r+2);
            }
          }
        }
        if (c!=7) {
          if ((board[8-(r+1)][c+1]!="")&&(getA(board[8-(r+1)][c+1])!=color)) {
            pMc.push_back(c+1);
            pMr.push_back(r+1);
            if (epc==(c+1)) {
              wep = false;
            }
          } else if ((board[8-r][c+1]!="")&&(getA(board[8-r][c+1])!=color)&&wep&&(epc==(c+1))&&(board[8-(r+1)][c+1]=="")) {
            pMc.push_back(c+1);
            pMr.push_back(r+1);
          }
        }
        if (c!=0) {
          if ((board[8-(r+1)][c-1]!="")&&(getA(board[8-(r+1)][c-1])!=color)) {
            pMc.push_back(c-1);
            pMr.push_back(r+1);
            if (epc==(c-1)) {
              wep = false;
            }
          } else if ((board[8-r][c-1]!="")&&(getA(board[8-r][c-1])!=color)&&wep&&(epc==(c-1))&&(board[8-(r+1)][c-1]=="")) {
            pMc.push_back(c-1);
            pMr.push_back(r+1);
          }
        }
      } else if (color=="b") {
        if (board[8-(r-1)][c]=="") {
          pMc.push_back(c);
          pMr.push_back(r-1);
          if (r==7) {
            if (board[8-(r-2)][c]=="") {
              pMc.push_back(c);
              pMr.push_back(r-2);
            }
          }
        }
        if (c!=7) {
          if ((board[8-(r-1)][c+1]!="")&&(getA(board[8-(r-1)][c+1])!=color)) {
            pMc.push_back(c+1);
            pMr.push_back(r-1);
            if (epc==(c+1)) {
              bep = false;
            }
          } else if ((board[8-r][c+1]!="")&&(getA(board[8-r][c+1])!=color)&&bep&&(epc==(c+1))&&(board[8-(r-1)][c+1]=="")) {
            pMc.push_back(c+1);
            pMr.push_back(r-1);
          }
        }
        if (c!=0) {
          if ((board[8-(r-1)][c-1]!="")&&(getA(board[8-(r-1)][c-1])!=color)) {
            pMc.push_back(c-1);
            pMr.push_back(r-1);
            if (epc==(c-1)) {
              bep = false;
            }
          } else if ((board[8-r][c-1]!="")&&(getA(board[8-r][c-1])!=color)&&bep&&(epc==(c-1))&&(board[8-(r-1)][c-1]=="")) {
            pMc.push_back(c-1);
            pMr.push_back(r-1);
          }
        }
      }
    } else if (p=="N") {
      if (!((c<=1)||(r==8))) {
        string piece = board[8-(r+1)][c-2];
        if (getA(piece)!=A) {
          pMc.push_back(c-2);
          pMr.push_back(r+1);
        }
      }
      if (!((c==0)||(r>=7))) {
        string piece = board[8-(r+2)][c-1];
        if (getA(piece)!=A) {
          pMc.push_back(c-1);
          pMr.push_back(r+2);
        }
      }
      if (!((c>=6)||(r==8))) {
        string piece = board[8-(r+1)][c+2];
        if (getA(piece)!=A) {
          pMc.push_back(c+2);
          pMr.push_back(r+1);
        }
      }
      if (!((c==7)||(r>=7))) {
        string piece = board[8-(r+2)][c+1];
        if (getA(piece)!=A) {
          pMc.push_back(c+1);
          pMr.push_back(r+2);
        }
      }
      if (!((c<=1)||(r==1))) {
        string piece = board[8-(r-1)][c-2];
        if (getA(piece)!=A) {
          pMc.push_back(c-2);
          pMr.push_back(r-1);
        }
      }
      if (!((c==0)||(r<=2))) {
        string piece = board[8-(r-2)][c-1];
        if (getA(piece)!=A) {
          pMc.push_back(c-1);
          pMr.push_back(r-2);
        }
      }
      if (!((c>=6)||(r==1))) {
        string piece = board[8-(r-1)][c+2];
        if (getA(piece)!=A) {
          pMc.push_back(c+2);
          pMr.push_back(r-1);
        }
      }
      if (!((c==7)||(r<=2))) {
        string piece = board[8-(r-2)][c+1];
        if (getA(piece)!=A) {
          pMc.push_back(c+1);
          pMr.push_back(r-2);
        }
      }
    } else if (p=="K") {
      if (A=="w") {
        if (!wKm) {
          if ((!wR1m)&&(board[8-r][c-1]=="")&&(board[8-r][c-2]=="")&&(board[8-r][c-3]=="")&&(checkW[8-r][c-1]=="")&&(checkW[8-r][c-2]=="")&&(checkW[8-r][c-3]=="")) {
            pMc.push_back(c-2);
            pMr.push_back(r);
          }
          if ((!wR1m)&&(board[8-r][c+1]=="")&&(board[8-r][c+2]=="")&&(checkW[8-r][c+1]=="")&&(checkW[8-r][c+2]=="")) {
            pMc.push_back(c+2);
            pMr.push_back(r);
          }
        }
      } else {
        if (!bKm) {
          if ((!bR1m)&&(board[8-r][c-1]=="")&&(board[8-r][c-2]=="")&&(board[8-r][c-3]=="")&&(checkB[8-r][c-1]=="")&&(checkB[8-r][c-2]=="")&&(checkB[8-r][c-3]=="")) {
            pMc.push_back(c-2);
            pMr.push_back(r);
          }
          if ((!wR1m)&&(board[8-r][c+1]=="")&&(board[8-r][c+2]=="")&&(checkB[8-r][c+1]=="")&&(checkB[8-r][c+2]=="")) {
            pMc.push_back(c+2);
            pMr.push_back(r);
          }
        }
      }
      if (r!=8) {
        string piece = board[8-(r+1)][c];
        if (getA(piece)!=A) { 
          pMc.push_back(c);
          pMr.push_back(r+1);
        }
      }
      if ((r!=8)&&(c!=0)) {
        string piece = board[8-(r+1)][c-1];
        if (getA(piece)!=A) { 
          pMc.push_back(c-1);
          pMr.push_back(r+1);
        }
      }
      if (r!=1) {
        string piece = board[8-(r-1)][c];
        if (getA(piece)!=A) { 
          pMc.push_back(c);
          pMr.push_back(r-1);
        }
      }
      if ((r!=1)&&(c!=0)) {
        string piece = board[8-(r-1)][c-1];
        if (getA(piece)!=A) { 
          pMc.push_back(c-1);
          pMr.push_back(r-1);
        }
      }
      if (c!=0) {
        string piece = board[8-r][c-1];
        if (getA(piece)!=A) { 
          pMc.push_back(c-1);
          pMr.push_back(r);
        }
      }
      if (c!=7) {
        string piece = board[8-r][c+1];
        if (getA(piece)!=A) { 
          pMc.push_back(c+1);
          pMr.push_back(r);
        }
      }
      if ((r!=1)&&(c!=7)) {
        string piece = board[8-(r-1)][c+1];
        if (getA(piece)!=A) { 
          pMc.push_back(c+1);
          pMr.push_back(r-1);
        }
      }
      if ((r!=8)&&(c!=7)) {
        string piece = board[8-(r+1)][c+1];
        if (getA(piece)!=A) { 
          pMc.push_back(c+1);
          pMr.push_back(r+1);
        }
      }
    } else {
      if ((p=="R")||(p=="Q")) {
        if (c!=7) {
          for (int i=c+1;i<8;i++) {
            if (board[8-r][i]!="") {
              string piece = board[8-r][i];
              if (getA(piece)!=A) { 
                pMc.push_back(i);
                pMr.push_back(r);
              }
              break;
            }
            pMc.push_back(i);
            pMr.push_back(r);
          }
        }
        if (c!=0) {
          for (int i=c-1;i>=0;i--) {
            if (board[8-r][i]!="") {
              string piece = board[8-r][i];
              if (getA(piece)!=A) {
                pMc.push_back(i);
                pMr.push_back(r);
              }
              break;
            }
            pMc.push_back(i);
            pMr.push_back(r);
          }
        }
        if (r!=8) {
          for (int i=r+1;i<=8;i++) {
            if (board[8-i][c]!="") {
              string piece = board[8-i][c];
              if (getA(piece)!=A) {
                pMc.push_back(c);
                pMr.push_back(i);
              }
              break;
            }
            pMc.push_back(c);
            pMr.push_back(i);
          }
        }
        if (r!=1) {
          for (int i=r-1;i>0;i--) {
            if (board[8-i][c]!="") {
              string piece = board[8-i][c];
              if (getA(piece)!=A) {
                pMc.push_back(c);
                pMr.push_back(i);
              }
              break;
            }
            pMc.push_back(c);
            pMr.push_back(i);
          }
        }
      }
      if ((p=="B")||(p=="Q")) {
        int I=1;
        if (!((c==0)||(r==8))) {
          while (!(((c-I)==-1)||((r+I)==9))) {  
            if (board[8-(r+I)][c-I]!="") {
              string piece = board[8-(r+I)][c-I];
              if (getA(piece)!=A) { 
                pMc.push_back(c-I);
                pMr.push_back(r+I);
              }
              break;
            }
            pMc.push_back(c-I);
            pMr.push_back(r+I);
            I++;
          }
        }
        I=1;
        if (!((c==7)||(r==8))) {
          while (!(((c+I)==8)||((r+I)==9))) {  
            if (board[8-(r+I)][c+I]!="") {
              string piece = board[8-(r+I)][c+I];
              if (getA(piece)!=A) { 
                pMc.push_back(c+I);
                pMr.push_back(r+I);
              }
              break;
            }
            pMc.push_back(c+I);
            pMr.push_back(r+I);
            I++;
          }
        }
        I=1;
        if (!((c==0)||(r==1))) {
          while (!(((c-I)==-1)||((r-I)==0))) {  
            if (board[8-(r-I)][c-I]!="") {
              string piece = board[8-(r-I)][c-I];
              if (getA(piece)!=A) { 
                pMc.push_back(c-I);
                pMr.push_back(r-I);
              }
              break;
            }
            pMc.push_back(c-I);
            pMr.push_back(r-I);
            I++;
          }
        }
        I=1;
        if (!((c==7)||(r==1))) {
          while (!(((c+I)==8)||((r-I)==0))) {  
            if (board[8-(r-I)][c+I]!="") {
              string piece = board[8-(r-I)][c+I];
              if (getA(piece)!=A) { 
                pMc.push_back(c+I);
                pMr.push_back(r-I);
              }
              break;
            }
            pMc.push_back(c+I);
            pMr.push_back(r-I);
            I++;
          }
        }
      }
    }
  }
  void mater(string c) {
    string p = "";
    fp();
    checkingF(c);
    if (wCheck||bCheck) {
    if (c=="w") {
      wMate = true;
    } else {
      bMate = true;
    }
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        if (getA(board[i][j])==c) {
          pMc.clear(); pMr.clear();
          getMoves(getP(board[i][j]),8-i,j,c);
          p = board[i][j];
          //cout << p << "\n";
        for (int g=0;g<pMr.size();g++) {
          fp();
          fboard[8-pMr.at(g)][pMc.at(g)] = p;
          fboard[i][j] = "";
          checkingF(c);
          //cout << pMr.at(g) << pMc.at(g) << wCheck << bCheck << "\n";
          if (c=="w") {
            if (!wCheck) {
              wMate = false;
            }
          } else {
            if (!bCheck) {
              bMate = false;
            }
          }
        }
        }
      }
    }
    }
  }
  void staler(string c) {
    vector<int> lm;
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        if (getA(board[i][j])==c) {
          pMc.clear(); pMr.clear();
          getMoves(getP(board[i][j]),8-i,j,c);
          for (int g=0;g<pMc.size();g++) {
            fp();
            fboard[8-pMr.at(g)][pMc.at(g)] = board[i][j];
            fboard[i][j] = "";
            checkingF(c);
            if (c=="w") {
              if (!wCheck) {
                lm.push_back(pMr.at(g));
              }
            } else {
              if (!bCheck) {
                lm.push_back(pMr.at(g));
              }
            }
          }
        }
      }
    }
    if (lm.size()==0) {
      draw = true;
    }
  }
  void gmC() {
    string g = "";
    checker(1);
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        if (checkW[i][j]=="x") {
          g += "b" + to_string(i) + to_string(j);
        }
        if (checkB[i][j]=="x") {
          g += "w" + to_string(i) + to_string(j);
        }
      }
    }
    g += "e" + to_string(wep) + to_string(bep);
    //cout << g << "\n";
    mC.push_back(g);
  }
  void imer() {
    ps.clear();
    for (int i=0;i<8;i++) {
      for (int j=0;j<8;j++) {
        ps.push_back(board[i][j]);
      }
    }
    if (ps.size()==2) {
      draw = true;
    } else if (ps.size()==3) {
      for (int i=0;i<ps.size();i++) {
        if ((getP(ps.at(i))=="N")||(getP(ps.at(i))=="B")) {
          draw = true;
        }
      }
    } else if (ps.size()==4) {
      int bc = 0;
      int lb = 0;
      for (int i=0;i<ps.size();i++) {
        if (getP(ps.at(i))=="B") {bc++;}
      }
      if (bc==2) {
        for (int i=0;i<8;i++) {
          for (int j=0;j<8;j++) {
            if (getP(board[i][j])=="B") {
              if (((i%2==0)&&(j%2==0))||((i%2!=0)&&(j%2!=0))) {
                lb++;
              }
            }
          }
        }
        if ((lb==2)||(lb==0)) {
          draw = true;
        }
      }
    }
  }
  void drawer(string c) {
    staler(c);
    imer();
    gmC();
    for (int i=0;i<mC.size();i++) {
      for (int j=0;j<mC.size();j++) {
        for (int g=0;g<mC.size();g++) {
          if ((i!=j)&&(i!=g)&&(j!=g)) {
            if ((mC.at(i)==mC.at(j))&&(mC.at(i)==mC.at(g))&&(mC.at(j)==mC.at(g))) {
              draw = true;
            }
          }
        }
      }
    }
    if (mR==100) {
      draw = true;
    }
  }
  void move(int r, string c) {
    int co = 0; string col = "a";
    int R = 1; string ro = "1"; int C = 0;
    pMc.clear(); pMr.clear();
    bool breaky = true; bool moving = true;
    if (c == "a") {
      co = 0;
    } else if (c == "b") {
      co = 1;
    } else if (c == "c") {
      co = 2;
    } else if (c == "d") {
      co = 3;
    } else if (c == "e") {
      co = 4;
    } else if (c == "f") {
      co = 5;
    } else if (c == "g") {
      co = 6;
    } else if (c == "h") {
      co = 7;
    }
    cout << "Where do you want to move it?\n";
    string p = board[8-r][co];
    string piece = getP(p);
    getMoves(piece,r,co,getA(p));
    while (moving) {
      fp();
      breaky = true;
      while (breaky) {
        cout << "Column: "; cin >> col;
        cout << "Row: "; cin >> ro;
        if ((ro=="1")||(ro=="2")||(ro=="3")||(ro=="4")||(ro=="5")||(ro=="6")||(ro=="7")||(ro=="8")) {
          R = stoi(ro);
        } else {
          R = 0;
        }
        if (col == "a") {
          C = 0;
        } else if (col == "b") {
          C = 1;
        } else if (col== "c") {
          C = 2;
        } else if (col == "d") {
          C = 3;
        } else if (col == "e") {
          C = 4;
        } else if (col == "f") {
          C = 5;
        } else if (col == "g") {
          C = 6;
        } else if (col == "h") {
          C = 7;
        }
        for (int i=0;i<pMc.size();i++) {
          if ((R==pMr.at(i))&&(C==pMc.at(i))) {
            breaky = false;
          }
          //cout << R << pMr.at(i) << C << pMc.at(i) << "\n";
        }
        if ((R==r)&&(C==co)) {
          breaky = false;
        }
      }
      bool promoting = false;
      string p2 = board[R][C];
      if (!((R==r)&&(C==co))) {
        fboard[8-R][C] = p;
        fboard[8-r][co] = "";
        checkingF(getA(p));
        if ((!(bCheck)&&(getA(p)=="b"))||(!(wCheck)&&(getA(p)=="w"))) {
          moving = false;
          if (((getA(fboard[8-R][C])=="w")&&(getA(board[8-R][C])=="b"))||((getA(fboard[8-R][C])=="b")&&(getA(board[8-R][C])=="w"))) {
            mR = 0;
          }
          pf();
          if (getP(p)=="K") {
            if (getA(p)=="w") {
              if ((!wKm)&&(R==1)) {
                if ((!wR1m)&&(C==2)) {
                  board[8-R][C+1] = board[7][0];
                  board[7][0] = "";
                } else if ((!wR2m)&&(C==6)) {
                  board[8-R][C-1] = board[7][7];
                  board[7][7] = "";
                }
              }
              wKm = true;
            } else {
              if ((!bKm)&&(R==8)) {
                if ((!bR1m)&&(C==2)) {
                  board[8-R][C+1] = board[0][0];
                  board[0][0] = "";
                } else if ((!bR2m)&&(C==6)) {
                  board[8-R][C-1] = board[0][7];
                  board[0][7] = "";
                }
              }
              bKm = true;
            }
          } else if (getP(p)=="R") {
            if (getA(p)=="w") {
              if (r==1) {
                if (co==0) {
                  wR1m = true;
                } else if (co==7) {
                  wR2m = true;
                }
              }
            } else {
              if (r==8) {
                if (co==0) {
                  bR1m = true;
                } else if (co==7) {
                  bR2m = true;
                }
              }
            }
          } else if (getP(p)=="P") {
            mR = 0;
            if (color=="w") {
              if ((R==6)&&(C==epc)&&wep) {
                board[8-(R-1)][C] = "";
              }
            } else {
              if ((R==3)&&(C==epc)&&bep) {
                board[8-(R+1)][C] = "";
              }
            }
          }
          mR++;
          if (color=="w") {
            checkingF("b");
            if ((piece=="P")&&(R==8)) {
              promoting = true;
              printy();
              while (promoting) {
                cout << "What do you want to promote to?\n(R/N/B/Q)\n";
                cin >> piece;
                if ((piece=="R")||(piece=="N")||(piece=="B")||(piece=="Q")) {
                  promoting = false;
                }
              }
              board[8-R][C] = color + piece;
            } else if ((piece=="P")&&(r==2)&&(R==4)) {
              bep = true; epc = C;
            } else {
              bep = false;
            }
            color = "b";
          } else {
            checkingF("w");
            if ((piece=="P")&&(R==1)) {
              promoting = true;
              printy();
              while (promoting) {
                cout << "What do you want to promote to?\n(R/N/B/Q)\n";
                cin >> piece;
                if ((piece=="R")||(piece=="N")||(piece=="B")||(piece=="Q")) {
                  promoting = false;
                }
              }
              board[8-R][C] = color + piece;
            } else if ((piece=="P")&&(r==7)&&(R==5)) {
              wep = true; epc = C;
            } else {
              wep = false;
            }
            color = "w";
          }
        }
      } else {
        moving = false;
      }
    }
  }
  string getC() {
    return color;
  }
  void printy() {
    int syn = system("clear"); syn++;
    for (int i=0;i<8;i++) {
      cout << " ";
      for (int j=0;j<8;j++) {
        cout << "----";
      }
      cout << "-\n" << (8-i);
      for (int j=0;j<8;j++) {
        cout << "|";
        if (board[i][j]=="") {
          cout << "   ";
        } else {
          cout << board[i][j] << " ";
        }
      }
      cout << "|\n";
    }
    cout << " ";
    for (int j=0;j<8;j++) {cout << "----";}
    cout << "-\n ";
    cout << "  a   b   c   d   e   f   g   h\n";
    /*
        for (int i=0;i<8;i++) {
          cout << "w";
          for (int j=0;j<8;j++) {
            cout << "----";
          }
          cout << "-\n" << (8-i);
          for (int j=0;j<8;j++) {
            cout << "|";
            if (checkW[i][j]=="") {
              cout << "   ";
            } else {
              cout << " " << checkW[i][j] << " ";
            }
          }
          cout << "|\n";
        }
        cout << " ";
        for (int j=0;j<8;j++) {cout << "----";}
        cout << "-\n ";
        cout << "  a   b   c   d   e   f   g   h\n";
        for (int i=0;i<8;i++) {
          cout << "b";
          for (int j=0;j<8;j++) {
            cout << "----";
          }
          cout << "-\n" << (8-i);
          for (int j=0;j<8;j++) {
            cout << "|";
            if (checkB[i][j]=="") {
              cout << "   ";
            } else {
              cout << " " << checkB[i][j] << " ";
            }
          }
          cout << "|\n";
        }
        cout << " ";
        for (int j=0;j<8;j++) {cout << "----";}
        cout << "-\n ";
        cout << "  a   b   c   d   e   f   g   h\n";
    */
    //cout << wCheck << bCheck << "\n";
  }
};
int main() {
  string col = "a"; int row = 1; string r = "1";
  chessBoard c; 
  string colo = "w"; string a = "";
  bool moreGame = true; bool game = true;
  bool bm = true; bool breaky = true;
  bool d1 = false; bool d2 = false;
  string D2 = "";
  string mb = "";
  while (moreGame) {
    c.setUp();
    game = true;
    while (game) {
      d1 = false; d2 = false;
      D2 = "";
      c.checker(1);
      c.printy();
      colo = c.getC();
      c.mater(colo);
      c.drawer(colo);
      if (!(c.wMate||c.bMate||c.draw)) {
      bm = true;
      while (bm) {
        cout << "Which action do you want to take?\n";
        cout << "1 - Move Piece\n";
        cout << "2 - Resign\n";
        cout << "3 - Request Draw\n";
        cin >> mb;
        if ((mb=="1")||(mb=="2")||(mb=="3")) {
          if (mb=="2") {
            if (colo=="w") {
              c.wMate = true;
            } else {
              c.bMate = true;
            }
          }
          if (mb=="3") {
            d1 = true;
            cout << "Does the other player agree to draw? (y/n) ";
            cin >> D2;
            if (D2=="y") {
              d2 = true;
            }
            if (d1&&d2) {
              c.draw = true;
            }
          }
          bm = false;
        }
      }
      }
      //cout << c.wMate << c.wCheck << c.bMate << c.bCheck << "\n";
      if (!(c.wMate||c.bMate||c.draw)) {
      if (colo=="w") {
        cout << "White to move:\n";
      } else {
        cout << "Black to move:\n";
      }
      cout << "What piece do you want to move?\n";
      breaky = true;
      while (breaky) {
        cout << "Column: "; cin >> col;
        cout << "Row: "; cin >> r;
        if ((r=="1")||(r=="2")||(r=="3")||(r=="4")||(r=="5")||(r=="6")||(r=="7")||(r=="8")) {
          row = stoi(r);
        } else {
          row = 0;
        }
        if (((col=="a")||(col=="b")||(col=="c")||(col=="d")||(col=="e")||(col=="f")||(col=="g")||(col=="h"))&&(row>=1)&&(row<=8)) {
          if (c.getApos(row,col)==colo) {
            breaky = false;
          }
        }
      }
      c.move(row,col);
      }
      if (c.wMate||c.bMate||c.draw) {
        game = false;
      }
    }
    c.printy();
    if (c.bMate) {
      cout << "White wins 1-0\n";
    } else if (c.wMate) {
      cout << "Black wins 0-1\n";
    } else {
      cout << "Draw ½-½\n";
    }
    cout << "Play again? (y/n) "; cin >> a;
    if (a=="n") {
      moreGame = false;
    }
  }
}