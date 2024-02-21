#include <iostream>

using namespace std;

double avg(double lst[], int length){
    double sum = 0;
    for(int ind = 0; ind<length; ++ind){
        sum+=lst[ind];
    }
    return sum / double(length);
}

int main()
{
    
    setlocale(LC_ALL,"rus");
    
    const int ROW = 3;
    const int COL = 5;
    
    double matrix[ROW][COL];
    
    for(int i = 0; i<ROW; ++i){
        for(int j = 0; j<COL; ++j){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i<ROW; ++i){
        cout << "AVG Строка-" << i << " :" << avg(matrix[i], COL) << endl;
    }
    

    return 0;
}
