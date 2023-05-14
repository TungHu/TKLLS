#include <iostream>
#include <string.h>

using namespace std;

void D_update(string &D, int nextState, int inputt)
{
    D = D + "S" + to_string(nextState) + ".I" + to_string(inputt) + " + ";
}

int main()
{
    string MSSV;
    string D3 = "";
    string D2 = "";
    string D1 = "";
    string D0 = "";
    cout << "Nhap MSSV: ";
    cin  >> MSSV;
    string temp;
    int state[MSSV.length()+1][10];

    for (int i = 0; i < MSSV.length() + 1; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            string temp = MSSV.substr(0,i) +  to_string(j);
            //cout  << MSSV.substr(0,i) << " ; " << to_string(j) << endl;
            for (int k = 0 ; k < temp.length()  ; k++)
            {
                if (temp.substr(k).compare(MSSV.substr(0, temp.length() - k)) == 0)
                {
                    //cout << temp.substr(k) << " ==? " << MSSV.substr(0, temp.length() - k) << " ; " << temp.length() - 1 << " ; " << j << " : " << temp.substr(k).length() << endl;
                    int nextState = temp.substr(k).length();
                    int curState = temp.length() - 1;
                    state[temp.length() - 1][j] = nextState;
                    switch (nextState)
                    {
                    case 1:
                        D_update(D0, curState, j);
                        break;
                    case 2:
                        D_update(D1, curState, j);
                        break;
                    case 3:
                        D_update(D0, curState, j);
                        D_update(D1, curState, j);
                        break;
                    case 4:
                        D_update(D2, curState, j);
                        break;
                    case 5:
                        D_update(D0, curState, j);
                        D_update(D2, curState, j);
                        break;
                    case 6:
                        D_update(D1, curState, j);
                        D_update(D2, curState, j);
                        break;
                    case 7:
                        D_update(D0, curState, j);
                        D_update(D1, curState, j);
                        D_update(D2, curState, j);
                        break;
                    case 8:
                        D_update(D3, curState, j);
                        break;
                    case 9:
                        D_update(D3, curState, j);
                        D_update(D0, curState, j);
                        break;
                    case 10:
                        D_update(D1, curState, j);
                        D_update(D3, curState, j);
                        break;
                    case 11:
                        D_update(D0, curState, j);
                        D_update(D1, curState, j);
                        D_update(D3, curState, j);
                        break;
                    case 12:
                        D_update(D3, curState, j);
                        D_update(D2, curState, j);
                        break;
                    case 13:
                        D_update(D0, curState, j);
                        D_update(D2, curState, j);
                        D_update(D3, curState, j);
                        break;
                    case 14:
                        D_update(D1, curState, j);
                        D_update(D2, curState, j);
                        D_update(D3, curState, j);
                        break;
                    default:
                        D_update(D0, curState, j);
                        D_update(D1, curState, j);
                        D_update(D2, curState, j);
                        D_update(D3, curState, j);
                        break;
                    }
                    //cout << D0 << endl << D1 << endl << D1 << endl << D2 << endl << D3; 
                    break;
                }
                state[temp.length() - 1][j] = 0;

                
            }
            
        }   
    }
    cout << "    ";
    for (int i = 0; i < 10; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < 25; i++)
    {
        cout << "_" ;
    }
    cout << endl;
    

    for (int i = 0; i < MSSV.length() + 1; i++)
    {
        cout << "S" << i << "| ";
        for (int j = 0; j < 10; j++)
        {
            cout  << state[i][j] << " ";
        }
        cout << endl;
    }    
    cout << endl;
    cout << "D0: " << D0.substr(0,D0.length() - 2) << endl << "D1: " << D1.substr(0,D1.length() - 2) << endl << "D2: " << D2.substr(0,D2.length() - 2) << endl << "D3: " << D3.substr(0,D3.length() - 2); 
}
