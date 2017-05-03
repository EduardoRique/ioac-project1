#include <iostream>

using namespace std;

int main(){
    int ciclos=5;
    string bolha;
    string m[2][4] = {
        {"add", "$t0", "$zero", "$v0"},
        {"add", "$t1", "$t0", "$t2"}
    };

    if(m[0][0] == "lw"){
        cout << "erro" << endl;
        return 1;
    }
    else{
        bolha = m[0][1];
    }
    for(int i=2; i<4; i++){
        if(bolha == m[1][i]){
            ciclos += 4;
        }
    }
    cout << "Quantidade total de ciclos: " << ciclos << endl;
    
    for(int i=0; i<ciclos; i++){
        
                cout << "-------------------" << endl;
                cout << "Ciclo " << i+1 << endl;
              
                cout << "IF:    " << m[0][0] << " " << m[0][1] << " " << m[0][2] << " " << m[0][3] << endl;
                cout << "ID:    " << m[0][0] << " " << m[0][1] << " " << m[0][2] << " " << m[0][3] << endl;
                cout << "EXE:    " << m[0][0] << " " << m[0][1] << " " << m[0][2] << " " << m[0][3] << endl;
                cout << "MEM:    " << m[0][0] << " " << m[0][1] << " " << m[0][2] << " " << m[0][3] << endl;
                cout << "WB:    " << m[0][0] << " " << m[0][1] << " " << m[0][2] << " " << m[0][3] << endl;
            
        
    }
    return 0;
}