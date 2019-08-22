#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

class Result{
public:
    char name[10] ;

};

class Sub{
public:
    int subject[10] ;
};


void merge(int arr[], string arr1[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;


    int L[n1], R[n2];
    string L1[n1], R1[n2] ;


    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
        L1[i] = arr1[l + i] ;
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1+ j];
        R1[j] = arr1[m + 1+ j] ;
    }


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            arr1[k] = L1[i] ;
            i++;
        }
        else
        {
            arr[k] = R[j];
            arr1[k] = R1[j] ;
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        arr1[k] = L1[i] ;
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        arr1[k] = R1[j] ;
        j++;
        k++;
    }
}

void mergeSort(int arr[], string arr1[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;


        mergeSort(arr, arr1, l, m);
        mergeSort(arr, arr1 ,m+1, r);

        merge(arr,arr1, l, m, r);
    }
}




int main()
{
    int no_subject, no_student , sum[10] , k = 0 ;
    int pass = 0 , fail = 0 ;

    int avg[10] ;
    Result stud[10] ;
    Sub obj[10] ;

    cout << "Enter no. of students: ";
    cin >> no_student ;
    cout << "Enter no. of subjects: " ;
    cin >> no_subject ;
    cout << "\n\n" ;

    cout << "Enter name of each student\n\n" ;

    for(int i = 0 ; i < no_student ; i++){
        cout << "Student " << (i+1) << " : " ;
        cin >> stud[i].name ;
    }

    cout << "\n" ;
    cout << "*** Names of all students are entered successfully! ***" ;
    cout << "\n\n\n" ;


    for( int i = 0 ; i < no_student ; i++){
        cout << "Enter marks of student " << stud[i].name << "\n\n" ;
        for( int j = 0 ; j < no_subject ; j++){
            cout << "Subject " << (j+1) << " : " ;
            cin >> obj[i].subject[j] ;

        }
        cout << "\n\n" ;
    }

    for( int i = 0 ; i < no_student ; i++){
        sum[i] = 0 ;
        for( int j = 0 ; j < no_subject ; j++){
            sum[i] = sum[i] + obj[i].subject[j] ;
        }
    }

    string nn[10] ;
    for( int i = 0 ; i < no_student ; i++){
        nn[i] = stud[i].name ;
    }


    for( int i = 0 ; i < no_student ; i++){
        avg[i] = sum[i]/no_subject ;
    }

    mergeSort(avg, nn, 0 , no_student) ;

    for( int i = 0, j = no_student - 1 ; i < no_student/2 ; i++, j--){
        int temp = avg[i] ;
        string temp1 = nn[i];
        avg[i] = avg[j] ;
        nn[i] = nn[j] ;
        avg[j] = temp ;
        nn[j] = temp1 ;
    }

    for( int i = 0 ; i < no_student ; i++){
        if( avg[i] >= 40){
            pass = pass + 1 ;
        }
        else{
            fail = fail + 1 ;
        }
    }

    cout << "\n\n\n" ;

    cout << "--- Detail Report --- \n\n" ;


    cout << "*** Congratulation to the top three rankers ***\n\n\n" ;
    for( int i = 0 ; i < 3 ; i++){
     cout << (i+1) <<" " << nn[i] << " : " << avg[i] << "\n" ;
    }

    cout << "\n\n" ;

    cout << "--- List of rank of all the student --- \n\n" ;


    for( int i = 0 ; i < no_student ; i++){
        cout << (i+1) <<" " << nn[i] << " : " << avg[i] << "\n" ;

    }

    cout << "\n\n\n" ;


    cout << "Total number of student appeared : " << no_student <<"\n" ;
    cout << "Number of student passed  : " << pass << "\n" ;
    cout << "Number of student failed  : " << fail << "\n" ;

    cout << "\n\n\n" ;
    cout << "Check the Excel file of Report as well" ;

    ofstream t ;
    if( k == 0){
        t.open("Report.csv", fstream::in | fstream::out | fstream::app) ;
        t << "REPORT" << endl ;
        t << endl ;

        t << "Rank, Name, Marks" << endl ;
        for( int i = 0 ; i < no_student ; i++){
            t << i+1 << "," << nn[i] << "," << avg[i] << endl ;
        }

        t << endl ;
        t << "Total," << no_student << endl ;
        t << "Pass, " << pass << endl ;
        t << "Fail, " << fail << endl ;

        t << endl ;

        t.close() ;
    }

    getch() ;

    return 0;
}
